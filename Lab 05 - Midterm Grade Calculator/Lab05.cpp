#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, October 30, 2020
// Project Name: Laboratory 05
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
 */
// Project Number: Project 05

int main(void) {
    
   ifstream gradeFile;
   ifstream weightFile;
   ofstream midtermFile;
   char studentName[80], studentAddress[80];
   double examGrade, hwGrade, lab1Grade, quiz1Grade, examWeight, hwWeight, labWeight, quizWeight;
   double lab2Grade, quiz2Grade;
   double lab3Grade;
   double lab4Grade;
   double examWeightedAvg, hwWeightedAvg, labWeightedAvg, quizWeightedAvg;
   double midtermAvg;
   
   //Get Student Name
   cout << "Name of Student: "; //to user
   cin.getline(studentName, 80); //from user

   //Get Student Address
   cout << "Student Address, City, State, and Zip Code: "; //to user
   cin.getline(studentAddress, 80); //from user
   
   //Get Grade Weights from File
   weightFile.open("weights.txt");
   weightFile >> examWeight;
   weightFile >> hwWeight;
   weightFile >> labWeight;
   weightFile >> quizWeight;
   weightFile.close();
   
   //Get Student Grades from File
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
   
   //Calculate the Weighted Averages
   examWeightedAvg = examGrade * examWeight;
   hwWeightedAvg = hwGrade * hwWeight;
   labWeightedAvg = ((lab1Grade + lab2Grade + lab3Grade + lab4Grade) / 4) * labWeight;
   quizWeightedAvg = ((quiz1Grade + quiz2Grade) / 2) * quizWeight;
   
   //Calculate Midterm Average  
   midtermAvg = examWeightedAvg + hwWeightedAvg + labWeightedAvg + quizWeightedAvg;
   
   //Display Grade Summary
   cout << "Jefferson Community College" << endl; //to user
   cout << studentName << endl; //to user
   cout << studentAddress << endl << endl; //to user
   cout << "Grades" << endl; //to user
   cout << setw(4) << "Exam" << setw(9) << "Homework" << setw(5) << "Labs" << setw(8) << "Quizzes" << endl; //to user
   cout << setw(4) << examGrade << setw(9) << hwGrade << setw(5) << lab1Grade << setw(8) << quiz1Grade << endl; //to user
   cout << setw(18) << lab2Grade << setw(8) << quiz2Grade << endl; //to user
   cout << setw(18) << lab3Grade << endl; //to user
   cout << setw(18) << lab4Grade << endl << endl; //to user
   cout << setprecision(4) << "Midterm Average: " << midtermAvg << endl; //to user
   
   //Log Student Midterm Information
   midtermFile.open("midterm.txt", ios::app);
   midtermFile << studentName << endl;
   midtermFile << midtermAvg << endl;
   midtermFile.close(); 
   
   return 0;
}

