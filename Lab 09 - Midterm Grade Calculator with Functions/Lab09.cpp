#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, December 4, 2020
// Project Name: Laboratory 09 (Originally Laboratory 05)
/* 
 * Project Description: You and your classmates want to know what your midterm grade is going to be. You, being
 * the brightest amongst your classmates, have decided to write a program that will perform
 * such a calculation.
 * Initially, the program should ask for the users name, address, city, state, and zip code from the
 * keyboard. Next, the individual grades to be used for the calculations should be read in from
 * a data file. Read in one exam grade, one homework grade, four laboratory grades, and two
 * quiz grades. A weighted-average should be calculated from the lab average, quiz average,
 * homework grade, and exam grade. Finally, the program should store (appended) the student
 * name and midterm average in a file named “midterm.txt”. Store the name on one line and
 * the midterm average on the next line.
 * Use the following weights for the exam, homework, laboratories, and quizzes respectively:
 * 26.67%, 13.33%, 46.67%, and 13.33%. These weights must be read in from a different file.
 * All output should be laid out "attractively" on the screen. Include headings to display the
 * college name, student name and student address. Display the Students individual assignment
 * grades in a tabular format and finally display the midterm average up to 2 decimal places.
 * Include labels identifying each group of data displayed.
 * Revise Laboratory 05 (Midterm Average) so it is implemented EXACTLY via functions - one function for
 * EVERY box in the top down except the top box, which is main. DO NOT ALTER THE DISIGNS EXCEPT TO
 * MAKE CORRECTIONS. Use local variables when possible.
 */
// Project Number: Project 09 (Originally Project 05)

//Function Prototypes
void getStudentName(char[]);
void getStudentAddress(char[]);
void getGradeWeightsFromFile(double &, double &, double &, double &);
void getStudentGradesFromFile(double &, double &, double &, double &, double &, double &, double &, double &);
void calculateTheWeightedAverages(double &, double &, double &, double &, double, double, double, double, double, double, double, double, double, double, double, double);
void calculateMidtermAverage(double &, double, double, double, double);
void displayGradeSummary(char[], char[], double, double, double, double, double, double, double, double, double);
void logStudentMidtermInformation(char[], double);

int main(void) {
    char studentName[80];
    char studentAddress[80];
    double examWeight, hwWeight, labWeight, quizWeight;
    double examGrade, hwGrade, lab1Grade, quiz1Grade;
    double lab2Grade, quiz2Grade;
    double lab3Grade;
    double lab4Grade;
    double examWeightedAvg, hwWeightedAvg, labWeightedAvg, quizWeightedAvg;
    double midtermAvg;
    
    //Get Student Name
    getStudentName(studentName);
    
    //Get Student Address
    getStudentAddress(studentAddress);
    
    //Get Grade Weights from File
    getGradeWeightsFromFile(examWeight, hwWeight, labWeight, quizWeight);
    
    //Get Student Grades from File
    getStudentGradesFromFile(examGrade, hwGrade, lab1Grade, quiz1Grade, lab2Grade, quiz2Grade, lab3Grade, lab4Grade);
    
    //Calculate the Weighted Averages
    calculateTheWeightedAverages(examWeightedAvg, hwWeightedAvg, labWeightedAvg, quizWeightedAvg, examGrade, examWeight, hwGrade, hwWeight, lab1Grade, lab2Grade, lab3Grade, lab4Grade, labWeight, quiz1Grade, quiz2Grade, quizWeight);
    
    //Calculate Midterm Average
    calculateMidtermAverage(midtermAvg, examWeightedAvg, hwWeightedAvg, labWeightedAvg, quizWeightedAvg);
    
    //Display Grade Summary
    displayGradeSummary(studentName, studentAddress, examGrade, hwGrade, lab1Grade, quiz1Grade, lab2Grade, quiz2Grade, lab3Grade, lab4Grade, midtermAvg);
    
    //Log Student Midterm Information
    logStudentMidtermInformation(studentName, midtermAvg);
    
    return 0;
}

//Function Definitions
void getStudentName(char studentName[80]){
    
   cout << "Name of Student: "; //to user
   cin.getline(studentName, 80); //from user
}

void getStudentAddress(char studentAddress[80]){
    
   cout << "Student Address, City, State, and Zip Code: "; //to user
   cin.getline(studentAddress, 80); //from user
}

void getGradeWeightsFromFile(double & examWeight, double & hwWeight, double & labWeight, double & quizWeight){
    
   ifstream weightFile;
    
   weightFile.open("weights.txt");
   weightFile >> examWeight;
   weightFile >> hwWeight;
   weightFile >> labWeight;
   weightFile >> quizWeight;
   weightFile.close();
}

void getStudentGradesFromFile(double & examGrade, double & hwGrade, double & lab1Grade, double & quiz1Grade, double & lab2Grade, double & quiz2Grade, double & lab3Grade, double & lab4Grade){
    
   ifstream gradeFile;
   
   gradeFile.open("grades.txt");
   gradeFile >> examGrade;
   gradeFile >> hwGrade;
   gradeFile >> lab1Grade;
   gradeFile >> quiz1Grade;
   gradeFile >> lab2Grade;
   gradeFile >> quiz2Grade;
   gradeFile >> lab3Grade;
   gradeFile >> lab4Grade;
   gradeFile.close();
}

void calculateTheWeightedAverages(double & examWeightedAvg, double & hwWeightedAvg, double & labWeightedAvg, double & quizWeightedAvg, double examGrade, double examWeight, double hwGrade, double hwWeight, double lab1Grade, double lab2Grade, double lab3Grade, double lab4Grade, double labWeight, double quiz1Grade, double quiz2Grade, double quizWeight){
    
   examWeightedAvg = examGrade * examWeight;
   hwWeightedAvg = hwGrade * hwWeight;
   labWeightedAvg = ((lab1Grade + lab2Grade + lab3Grade + lab4Grade) / 4) * labWeight;
   quizWeightedAvg = ((quiz1Grade + quiz2Grade) / 2) * quizWeight;
}

void calculateMidtermAverage(double & midtermAvg, double examWeightedAvg, double hwWeightedAvg, double labWeightedAvg, double quizWeightedAvg){
    
    midtermAvg = examWeightedAvg + hwWeightedAvg + labWeightedAvg + quizWeightedAvg;
}

void displayGradeSummary(char studentName[80], char studentAddress[80], double examGrade, double hwGrade, double lab1Grade, double quiz1Grade, double lab2Grade, double quiz2Grade, double lab3Grade, double lab4Grade, double midtermAvg){
    
   cout << "Jefferson Community College" << endl; //to user
   cout << studentName << endl; //to user
   cout << studentAddress << endl << endl; //to user
   cout << "Grades" << endl; //to user
   cout << setw(4) << "Exam" << setw(9) << "Homework" << setw(5) << "Labs" << setw(8) << "Quizzes" << endl; //to user
   cout << setw(4) << examGrade << setw(9) << hwGrade << setw(5) << lab1Grade << setw(8) << quiz1Grade << endl; //to user
   cout << setw(18) << lab2Grade << setw(8) << quiz2Grade << endl; //to user
   cout << setw(18) << lab3Grade << endl; //to user
   cout << setw(18) << lab4Grade << endl << endl; //to user
   cout << fixed << setprecision(2) << "Midterm Average: " << midtermAvg << endl; //to user
}

void logStudentMidtermInformation(char studentName[80], double midtermAvg){
    
   ofstream midtermFile;
   
   midtermFile.open("midterm.txt", ios::app);
   midtermFile << studentName << endl;
   midtermFile << fixed << setprecision(2) << midtermAvg << endl;
   midtermFile.close();
}