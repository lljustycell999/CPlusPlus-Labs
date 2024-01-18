#include <iostream>

using namespace std;

// Name: Justyce Countryman
// Due date: Friday, October 2, 2020
// Project name: Laboratory 02
/*
 * Project Description: You work for a store who wants to automate the way change is dispensed to customers. The
 * store will eventually use machines to dispense the change, but the first step is to write the
 * program that will determine how many of each denomination will be returned. This task has
 * been given to you. Your program should ask the user for the amount due and amount tendered (not shown
 * below). The program will then display how many of each denomination should be returned.
 */
// Project number: Project 02

int main(void) {
    
    double amountDue;
    double amountTendered;
    double changeDue;
    int dollarChange;
    int coinChange;
    int num20s, num10s, num5s, num1s;
    int numQuarters, numDimes, numNickels, numPennies;
    
    //Get Amount Due
    cout << "Enter Amount Due: "; //to user
    cin >> amountDue; //from user
    
    //Get Amount Tendered
    cout << "Enter Amount Tendered: "; //to user
    cin >> amountTendered; //from user
    
    //Calculate Change Due
    changeDue = amountTendered - amountDue;
    
    //Calculate Dollar Change Due
    dollarChange = changeDue; // [Truncated]
    
    //Calculate Coin Change Due
    coinChange = ((changeDue - dollarChange) * 100) + 0.5; // [Rounded Up]
    
    //Calculate Number of Each Bill Returned
    num20s = dollarChange / 20; // [Integer Division]
    dollarChange = dollarChange % 20; // [Integer Division]
    num10s = dollarChange / 10; // [Integer Division]
    dollarChange = dollarChange % 10; // [Integer Division]
    num5s = dollarChange / 5; // [Integer Division]
    dollarChange = dollarChange % 5; // [Integer Division]
    num1s = dollarChange / 1; // [Integer Division]
    dollarChange = dollarChange % 1; // [Integer Division]
    
    //Calculate Number of Each Coin Returned
    numQuarters = coinChange / 25; // [Integer Division]
    coinChange = coinChange % 25; // [Integer Division]
    numDimes = coinChange / 10; // [Integer Division]
    coinChange = coinChange % 10; // [Integer Division]
    numNickels = coinChange / 5; // [Integer Division]
    coinChange = coinChange % 5; // [Integer Division]
    numPennies = coinChange / 1; // [Integer Division]
    coinChange = coinChange % 1; // [Integer Division]
    
    //Display Change Summary
    cout << "Amount Due: " << amountDue << endl; //to user
    cout << "Amount Tendered: " << amountTendered << endl << endl; //to user
    cout << "Change Due: " << changeDue << endl << endl; //to user
    cout << "Give the following Bills: " << endl; //to user
    cout << num20s << " - $20 Bill(s) " << endl; //to user
    cout << num10s << " - $10 Bill(s) " << endl; //to user
    cout << num5s << " - $5 Bill(s) " << endl; //to user
    cout << num1s << " - $1 Bill(s) " << endl << endl; //to user
    cout << "Give the following Coins: " << endl; //to user
    cout << numQuarters << " - Quarter(s) " << endl; //to user
    cout << numDimes << " - Dime(s) " << endl; //to user
    cout << numNickels << " - Nickel(s) " << endl; //to user
    cout << numPennies << " - Pennie(s) " << endl; //to user
  
    return 0;
}
