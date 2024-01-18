#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, November 20, 2020
// Project Name: Laboratory 08
/*
 * The work you did in the tax department got you some attention. You now took on some work
 * for the local electric company in the billing department. You have been asked to write a
 * program that will produce electrical bills for customers. The program will use a billing schedule
 * to generate bills for each customer in the customer data file.
 * The company charges various rates depending on usage.
 * The company also gives a 5% discount to commercial users. Commercial users have meter
 * numbers that begin with a C (i.e. CF1550-1) while all other users have meter numbers that
 * begins with a letter between S and Z (i.e. VR23-003).
 * The first line of the file contains an integer, which denotes the number of customers. The
 * remainder of the customer file contains the following information for each customer (1 item per
 * line, 8 lines total per customer): name, address, city/state/zip, account number, meter number,
 * reading date, present reading, and previous reading.
 * The program should determine the usage in kilowatt/hours (kwh) and then the billable amount
 * (according to the schedule). The program should generate a bill for each customer. The layout
 * of the bill should look semi-realistic. Include headings and label all data. Include name,
 * address, city/state/zip, account number, meter number, reading date, present reading, previous
 * reading, usage (kwh), and billable amount.
 * You will use a for loop like we have done previously.
 */
// Project Number: Project 10

int main(void) {

    ifstream electricBillingInformation;
    int numCustomers;
    char customerName[80], customerAddress[80], customerCityStateZip[80], customerAccountNumber[80], customerMeterNumber[80], customerReadingDate[80];
    double customerPresentReading, customerPreviousReading, customerUsage;
    double amountDue;
    
    //Get Number of Customers
    electricBillingInformation.open("electricity.txt");
    electricBillingInformation >> numCustomers;
    
    //Get Customer Information
    for(int cnt = 0; cnt < numCustomers; cnt++){
        electricBillingInformation.ignore(1000, '\n');
        electricBillingInformation.getline(customerName, 80);
        electricBillingInformation.getline(customerAddress, 80);
        electricBillingInformation.getline(customerCityStateZip, 80);
        electricBillingInformation.getline(customerAccountNumber, 80);
        electricBillingInformation.getline(customerMeterNumber, 80);
        electricBillingInformation.getline(customerReadingDate, 80);
        electricBillingInformation >> customerPresentReading;
        electricBillingInformation >> customerPreviousReading;
        
        //Compute Usage
        customerUsage = customerPresentReading - customerPreviousReading;
        
        //Compute Amount Due
        if(customerUsage <= 300){
            amountDue = 52.11;
        }    
        else{
            if(300 < customerUsage and customerUsage <= 1000){
                amountDue = 52.11 + (customerUsage - 300) * 0.19226;
            }
            else{
                amountDue = 52.11 + (700 * 0.19226) + (customerUsage - 1000) * 0.16981;
            }
        }    
        if(strcmp(customerMeterNumber, "C") >= 0 && strcmp(customerMeterNumber, "D") < 0){
            amountDue = amountDue * 0.95;
        }
        
    //Display Customer Bill
    cout << "Bikini Bottom Power" << endl; //to user
    cout << customerName << endl; //to user
    cout << customerAddress << endl; //to user
    cout << customerCityStateZip << endl << endl; //to user
    cout << setw(29) << "Account Number: " << setw(30) << customerAccountNumber << endl; //to user
    cout << setw(29) << "Meter Number: " << setw(30) << customerMeterNumber << endl; //to user
    cout << setw(29) << "Date: " << setw(30) << customerReadingDate << endl << endl; //to user
    cout << setw(29) << fixed << setprecision(2) << "Present Reading (kWh): " << setw(30) << customerPresentReading << endl; //to user
    cout << setw(29) << "Previous Reading (kWh): " << setw(30) << customerPreviousReading << endl; //to user
    cout << setw(29) << "Usage for this period (kWh): " << setw(30) << customerUsage << endl; //to user
    cout << setw(29) << "Amount Due ($): " << setw(30) << amountDue << endl << endl; //to user
    }  
    electricBillingInformation.close();
    
    return 0;
}
