#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, November 13, 2020
// Project Name: Laboratory 07
/* 
 * You have been asked to write a program to create property tax bills for Bikini Bottom. The program that you write
 * will create a bill containing each taxpayer's name, address, city, state and zip code. Furthermore, the bill should
 * contain the amount of tax to be paid on the home. Each taxpayer pays a percentage of the assessed value. That
 * percentage is based on the assessed value itself. 
 * There is a data file available to you listing the taxpayer name, address, and assessed value.
 * The first line contains an integer identifying how many
 * taxpayers are in this file. You may build the file name into your code - i.e. do not ask
 * the user for it.
 * The program must ask the user, initially, for the current date and the due date. The
 * current date and due date are placed on each bill while the current data is placed
 * upon the assessment summary.
 * Your program should create a bill containing the taxpayer's name, address, city,
 * state, zip-code, assessed value, and property tax as well as a heading.
 * At the end of all of the tax bills, you should display an assessment summary that lists the number of properties within
 * each tax bracket and the total taxes that will be collected.
 */
// Project Number: Project 09

int main(void) {
    
    ifstream taxpayerInformationFile;
    char currentDate[80], dueDate[80];
    int numTaxpayers;
    char taxpayerName[80], taxpayerAddress[80];
    double assessedValue; 
    double taxRate;
    double taxDue;
    int lowPriceAssessments, mediumPriceAssessments, highPriceAssessments, expensivePriceAssessments;
    double totalTax;
    
    lowPriceAssessments = 0;
    mediumPriceAssessments = 0;
    highPriceAssessments = 0;
    expensivePriceAssessments = 0;
    totalTax = 0;
    
    //Get Dates
    cout << "Enter Current Date: "; //to user
    cin.getline(currentDate, 80); //from user
    cout << "Enter Due Date: "; //to user
    cin.getline(dueDate, 80); //from user
    
    //Get Number of Taxpayers
    taxpayerInformationFile.open("taxpayers.txt");
    taxpayerInformationFile >> numTaxpayers;
    
    //Get Taxpayer Information
    for(int cnt = 0; cnt < numTaxpayers; cnt++){
        taxpayerInformationFile.ignore(1000, '\n');
        taxpayerInformationFile.getline(taxpayerName, 80);
        taxpayerInformationFile.getline(taxpayerAddress, 80);
        taxpayerInformationFile >> assessedValue;
    
        //Determine Tax Rate
        if(assessedValue < 10001){
            taxRate = 0.03;
        }
        if(10001 <= assessedValue and assessedValue <= 30000){
            taxRate = 0.04;
        }
        if(30001 <= assessedValue and assessedValue <= 60000){
            taxRate = 0.05;
        }
        if(assessedValue > 60000){
            taxRate = 0.06;
        }  
    
        //Calculate Tax Due
        taxDue = assessedValue * taxRate;
    
        //Display Tax Bill
        cout << setw(34) << "City of Bikini Bottom" << endl << endl; //to user
        cout << setw(32) << "Property Tax Bill" << endl << endl; //to user
        cout << currentDate << endl << endl; //to user
        cout << taxpayerName << endl; //to user
        cout << taxpayerAddress << endl; //to user
        cout << "Bikini Bottom, Pacific Ocean 13579" << endl << endl; //to user
        cout << fixed << setprecision(2) << "Current assessed value:  " << assessedValue << endl << endl; //to user
        cout << "Property tax due:  " << taxDue << endl << endl; //to user
        cout << "Date DUE:  " << dueDate << endl; //to user
    
        //Update Totals
        if(assessedValue < 10001){
            lowPriceAssessments = lowPriceAssessments + 1;
        }
        if(10001 <= assessedValue and assessedValue <= 30000){
            mediumPriceAssessments = mediumPriceAssessments + 1;
        }
        if(30001 <= assessedValue and assessedValue <= 60000){
            highPriceAssessments = highPriceAssessments + 1;
        }
        if(assessedValue > 60000){
            expensivePriceAssessments = expensivePriceAssessments + 1;
        }
        totalTax = totalTax + taxDue;
    }
    taxpayerInformationFile.close();
    
    //Display Assessment Summary
    cout << setw(46) << "City of Bikini Bottom" << endl << endl; //to user
    cout << setw(47) << "Property Tax Statistics" << endl << endl; //to user
    cout << setw(34) << "As of " << currentDate << endl << endl; //to user
    cout << "Number of assessments below $10,001: " << setw(40) << lowPriceAssessments << endl << endl; //to user
    cout << "Number of assessments between $10,001-$30,000: " << setw(30) << mediumPriceAssessments << endl << endl; //to user
    cout << "Number of assessments between $30,001-$60,000: " << setw(30) << highPriceAssessments << endl << endl; //to user
    cout << "Number of assessments above $60,000: " << setw(40) << expensivePriceAssessments << endl << endl; //to user
    cout << "Total taxes: " << setw(64) << totalTax << endl; //to user
    
    return 0;
}

