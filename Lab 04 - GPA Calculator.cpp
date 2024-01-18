#include <iostream>
#include <iomanip>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, October 16, 2020
// Project Name: Laboratory 04
/*
 * Project Description: You happen to have a friend who is struggling in college - hmmm, who doesn’t. This friend wants to have some
 * idea of what their grade point average (GPA) will be for their current semester. Since this is somewhat new to
 * you and you are even unsure of how to do the math, you have decided to write a program to solve the problem.
 * Initially, ask the user for the student’s name and the current semester. These will be displayed upon the final
 * report you generate.
 * In order to do this work, you need to get grade information for the semester. For each course, this information
 * would include the course name as well as what is called “attempted hours” and “quality points.” Attempted
 * hours are the credit hours from courses for which they have registered (i.e. CIS 116 is 3 credits so taking it adds 3
 * earned hours to the total). Quality points are how courses are weighted - these are computed for each course
 * by taking the grade weight (A is 4, B is 3, C is 2, D is 1, and everything else is a 0) and multiplying it times the
 * attempted hours. The program must allow the student to enter 6 courses. For each course, the student will
 * enter the course name, attempted hours, and the grade weight (A is 4, B is 3, C is 2, D is 1, and everything else is
 * a 0).
 * To compute the semester GPA, you must first compute the total attempted hours and then the total quality
 * points. To determine the total attempted hours, add up the attempted hours entered for each of the 6 courses.
 * To determine the total quality points, sum up the product of the attempted hours (as entered) and the grade
 * weight (also as entered) for all courses entered. The semester GPA is calculated by dividing the total quality
 * points by the total attempted hours.
 * For the report, show the student name followed by a summary of the course grade information and the
 * semester GPA
 */
// Project Number: Project 04

int main(void) {

    char studentName[80];
    char semester[80];
    char course1Name[80], course2Name[80], course3Name[80], course4Name[80], course5Name[80], course6Name[80];
    int course1AttHours, course2AttHours, course3AttHours, course4AttHours, course5AttHours, course6AttHours;
    int course1Weight, course2Weight, course3Weight, course4Weight, course5Weight, course6Weight;
    double course1QualityPoints, course2QualityPoints, course3QualityPoints, course4QualityPoints, course5QualityPoints, course6QualityPoints;
    double totalQualityPoints;
    double totalAttemptedHours;
    double gpa;
    
    //Get Student Name
    cout << "Enter Student Name: "; //to user
    cin.getline(studentName, 80); //from user
    
    //Get Semester
    cout << "Enter Semester: "; //to user
    cin.getline(semester, 80); //from user
    
    //Get Course Information 
    cout << "Enter Course 1 Name: "; //to user
    cin.getline(course1Name, 80); //from user
    cout << "Enter Course 1 Attempted Hours: "; //to user
    cin >> course1AttHours; //from user
    cout << "Enter Course 1 Grade Weight: "; //to user
    cin >> course1Weight; //from user
    
    cout << "Enter Course 2 Name: "; //to user
    cin.ignore(1000, '\n');
    cin.getline(course2Name, 80); //from user
    cout << "Enter Course 2 Attempted Hours: "; //to user
    cin >> course2AttHours; //from user
    cout << "Enter Course 2 Grade Weight: "; //to user
    cin >> course2Weight; //from user
    
    cout << "Enter Course 3 Name: "; //to user
    cin.ignore(1000, '\n');
    cin.getline(course3Name, 80); //from user
    cout << "Enter Course 3 Attempted Hours: "; //to user
    cin >> course3AttHours; //from user
    cout << "Enter Course 3 Grade Weight: "; //to user
    cin >> course3Weight; //from user
    
    cout << "Enter Course 4 Name: "; //to user
    cin.ignore(1000, '\n');
    cin.getline(course4Name, 80); //from user
    cout << "Enter Course 4 Attempted Hours: "; //to user
    cin >> course4AttHours; //from user
    cout << "Enter Course 4 Grade Weight: "; //to user
    cin >> course4Weight; //from user
    
    cout << "Enter Course 5 Name: "; //to user
    cin.ignore(1000, '\n');
    cin.getline(course5Name, 80); //from user
    cout << "Enter Course 5 Attempted Hours: "; //to user
    cin >> course5AttHours; //from user
    cout << "Enter Course 5 Grade Weight: "; //to user
    cin >> course5Weight; //from user
    
    cout << "Enter Course 6 Name: "; //to user
    cin.ignore(1000, '\n');
    cin.getline(course6Name, 80); //from user
    cout << "Enter Course 6 Attempted Hours: "; //to user
    cin >> course6AttHours; //from user
    cout << "Enter Course 6 Grade Weight: "; //to user
    cin >> course6Weight; //from user
    
    //Calculate Quality Points for Each Course
    course1QualityPoints = course1AttHours * course1Weight;
    course2QualityPoints = course2AttHours * course2Weight;
    course3QualityPoints = course3AttHours * course3Weight;
    course4QualityPoints = course4AttHours * course4Weight;
    course5QualityPoints = course5AttHours * course5Weight;
    course6QualityPoints = course6AttHours * course6Weight;
    
    //Calculate Total Quality Points
    totalQualityPoints = course1QualityPoints + course2QualityPoints + course3QualityPoints + course4QualityPoints + course5QualityPoints + course6QualityPoints;
    
    //Calculate Total Attempted Hours
    totalAttemptedHours = course1AttHours + course2AttHours + course3AttHours + course4AttHours + course5AttHours + course6AttHours;
    
    //Calculate GPA
    gpa = totalQualityPoints / totalAttemptedHours;
    
    //Display Student Information
    cout << "GPA Report for " << studentName << " (" << semester << " semester)" << endl << endl; //to user
    
    //Display Semester Information
    cout << setw (10) << "Course Name" << setw (35) << "Att. Hrs." << setw (20) << "Grd. Wght." << endl; //to user
    cout << setw (5) << course1Name << setw (18) << course1AttHours << setw (20) << course1Weight << endl; //to user
    cout << setw (5) << course2Name << setw (17) << course2AttHours << setw (20) << course2Weight << endl; //to user
    cout << setw (5) << course3Name << setw (20) << course3AttHours << setw (20) << course3Weight << endl; //to user
    cout << setw (5) << course4Name << setw (17) << course4AttHours << setw (20) << course4Weight << endl; //to user
    cout << setw (5) << course5Name << setw (18) << course5AttHours << setw (20) << course5Weight << endl; //to user
    cout << setw (5) << course6Name << setw (13) << course6AttHours << setw (20) << course6Weight << endl << endl; //to user
    
    //Display GPA Grade Summary
    cout << "Total Attempted Hours: " << totalAttemptedHours << endl; //to user
    cout << "Total Quality Points: " << totalQualityPoints << endl; //to user
    cout << "GPA: " << gpa << endl; //to user

    return 0;
}

