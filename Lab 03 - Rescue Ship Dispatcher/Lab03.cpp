#include <iostream>
#include <cmath>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, October 9, 2020
// Project Name: Laboratory 03
/*
 * Project Description: You work for the US Coast Guard and you have been put in charge of a project to dispatch ships to
 * distress calls. You have decided to create a program that will determine how close your ships are to the
 * coordinates of the ship that is in trouble. Using coordinate data, calculate the distances of each of the
 * Coast Guard vessels from the distress call. Your program should also account for the maximum speed of each rescue vessel (you wouldn't send a
 * slow ship that is closest if a fast ship that is further away could get there first). Therefore, calculate the
 * time needed for each ship to travel the calculated distance. The program should ask for the name of the vessel, current date and time, number of people to be
 * rescued, and the position (via x and y coordinates). The program should display all of the user-entered
 * data along with a table of capacities, distances, and travel times for each Coast Guard vessel. Run your program to answer the following question. If there were 47 people to be rescued at location
 * 15x and 20y, how many of the ships would need to be sent (of the ones with the shortest travel time).  
 */
// Project Number: Project 03

int main(void) {

    char vesselName[80];
    char dateTime[80];
    int numPeople;
    double cg1XCoord, cg1YCoord, cg1Speed, cg1Capacity;
    double cg2XCoord, cg2YCoord, cg2Speed, cg2Capacity;
    double cg3XCoord, cg3YCoord, cg3Speed, cg3Capacity;
    double cg4XCoord, cg4YCoord, cg4Speed, cg4Capacity;
    double cg5XCoord, cg5YCoord, cg5Speed, cg5Capacity;
    double cg6XCoord, cg6YCoord, cg6Speed, cg6Capacity;
    double cg7XCoord, cg7YCoord, cg7Speed, cg7Capacity;
    double xCoord, yCoord, distance1, distance2, distance3, distance4, distance5, distance6, distance7;
    double time1, time2, time3, time4, time5, time6, time7;
    
    //Get Vessel in Distress Data
    cout << "Enter the Name of the Vessel in Distress: "; //to user
    cin.getline(vesselName, 80); //from user
    
    cout << "Enter the Date and Time of Incident: " << endl; //to user
    cin.getline(dateTime, 80); //from user
    
    cout << "Enter Number of People to be Rescued: "; //to user
    cin >> numPeople; //from user
    
    cout << "Enter the X coordinate of the Vessel in Distress: "; //to user
    cin >> xCoord; //from user
    
    cout << "Enter the Y coordinate of the Vessel in Distress: "; //to user
    cin >> yCoord; //from user
    
    //Set Coast Guard Vessel Data
    cg1XCoord = 10;
    cg1YCoord = 20; 
    cg1Speed = 22;
    cg1Capacity = 8;
    
    cg2XCoord = 5;        
    cg2YCoord = 5;        
    cg2Speed = 30;
    cg2Capacity = 5;  
    
    cg3XCoord = 18;
    cg3YCoord = 2;
    cg3Speed = 12;
    cg3Capacity = 25;
    
    cg4XCoord = 29;
    cg4YCoord = 10; 
    cg4Speed = 19;
    cg4Capacity = 14;
    
    cg5XCoord = 3;
    cg5YCoord = 12;
    cg5Speed = 23;
    cg5Capacity = 8;
    
    cg6XCoord = 11;
    cg6YCoord = 17;
    cg6Speed = 12;
    cg6Capacity = 25;
    
    cg7XCoord = 12;
    cg7YCoord = 22;
    cg7Speed = 22;
    cg7Capacity = 8;
    
    //Calculate Distances to Vessel in Distress
    distance1 = sqrt(pow(xCoord - cg1XCoord, 2) + pow(yCoord - cg1YCoord, 2));
    distance2 = sqrt(pow(xCoord - cg2XCoord, 2) + pow(yCoord - cg2YCoord, 2));
    distance3 = sqrt(pow(xCoord - cg3XCoord, 2) + pow(yCoord - cg3YCoord, 2));
    distance4 = sqrt(pow(xCoord - cg4XCoord, 2) + pow(yCoord - cg4YCoord, 2));
    distance5 = sqrt(pow(xCoord - cg5XCoord, 2) + pow(yCoord - cg5YCoord, 2));
    distance6 = sqrt(pow(xCoord - cg6XCoord, 2) + pow(yCoord - cg6YCoord, 2));
    distance7 = sqrt(pow(xCoord - cg7XCoord, 2) + pow(yCoord - cg7YCoord, 2));
    
    //Calculate Times to Reach Vessel in Distress
    time1 = distance1 / cg1Speed;
    time2 = distance2 / cg2Speed;
    time3 = distance3 / cg3Speed;
    time4 = distance4 / cg4Speed;
    time5 = distance5 / cg5Speed;
    time6 = distance6 / cg6Speed;
    time7 = distance7 / cg7Speed;
    
    //Display Rescue Summary
    cout << "Rescue Summary" << endl; //to user
    cout << "Vessel in Distress: " << vesselName << endl; //to user
    cout << "Incident Date and Time: " << dateTime << endl; //to user
    cout << "Number of People Aboard: " << numPeople << endl; //to user
    cout << "Incident Location: (" << xCoord << "," << yCoord << ")" << endl; //to user
    cout << setw (14) << "Vessel Number" << setw (10) << "Capacity" << setw (10) << "Distance" << setw (13) << "Rescue Time" << endl; //to user
    cout << setw (7) << "1" << setw (13) << cg1Capacity << setw (13) << distance1 << setw (12) << time1 << endl; //to user
    cout << setw (7) << "2" << setw (13) << cg2Capacity << setw (13) << distance2 << setw (12) << time2 << endl; //to user
    cout << setw (7) << "3" << setw (13) << cg3Capacity << setw (13) << distance3 << setw (12) << time3 << endl; //to user
    cout << setw (7) << "4" << setw (13) << cg4Capacity << setw (13) << distance4 << setw (12) << time4 << endl; //to user
    cout << setw (7) << "5" << setw (13) << cg5Capacity << setw (13) << distance5 << setw (12) << time5 << endl; //to user
    cout << setw (7) << "6" << setw (13) << cg6Capacity << setw (13) << distance6 << setw (12) << time6 << endl; //to user
    cout << setw (7) << "7" << setw (13) << cg7Capacity << setw (13) << distance7 << setw (12) << time7 << endl; //to user
    
    return 0;
}

