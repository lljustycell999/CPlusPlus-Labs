#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Name: Justyce Countryman
// Due Date: Friday, November 6, 2020
// Project Name: Laboratory 06
/*
 * Project Description: Due to your expertise and your fabulous programs for calculating grades and averages, you have landed a
 * job with a company that sells tools. Your company sells the following tools: a table saw, a paint tool, and
 * a blow torch. After seeing your previous work, they would like you to write code.
 * Your program should allow the user to perform one of two possible tasks (either produce a bill or change
 * prices). When the program begins, it will ask the user which task they want to perform and then it should
 * perform that task.
 * When the user chooses to produce a bill, the program should read the product description and price for
 * the table saw, paint tool, and blow torch from the price file. Next the program should ask the user for the
 * customer name, address, and order information. Order information would include the quantity of saws,
 * paint tools, and blow torches that the customer wants - when prompting for the quantities, display the
 * product description and price as read from the file. Finally, the program should display a bill. All screen
 * output should be laid out "attractively" on the screen(i.e. using formatted output). Place a company
 * heading followed by the customer information and then a summary of items selected - do not show
 * items that have a 0 quantity. At the bottom, show a subtotal, tax(8.0%), and total for the purchase. The
 * following could be a bill for a customer who purchased 1 table saw and 3 blow torches - note that NO
 * paint tools were purchased. 
 */
// Project Number: Project 06

int main(void) {
    
    ifstream productInformationFile;
    ofstream newProductInformationFile;
    char product1Description[80], product2Description[80], product3Description[80];
    double product1Price, product2Price, product3Price;
    int userChoice;
    char customerName[80], customerStreetAddress[80], customerCityStateZip[80];
    int product1Quantity, product2Quantity, product3Quantity;
    double product1ExtendedCost, product2ExtendedCost, product3ExtendedCost;
    double subtotal;
    double tax;
    double total;
    
    //Get Product Information
    productInformationFile.open("productInformation.txt");
    productInformationFile.getline(product1Description, 80);
    productInformationFile >> product1Price;
    productInformationFile.ignore(1000, '\n'); //Use .ignore whenever you are using multiple getlines
    productInformationFile.getline(product2Description, 80);
    productInformationFile >> product2Price;
    productInformationFile.ignore(1000, '\n');
    productInformationFile.getline(product3Description, 80);     
    productInformationFile >> product3Price;      
    productInformationFile.close();
 
    //Get User Choice
    cout << "Generate Bill[1] or Change Prices[2]?: "; //to user
    cin >> userChoice; //from user 
    
    if(userChoice == 1){
        
        //Get Customer Information
        cout << "Enter Customer Name: "; //to user
        cin.ignore(1000, '\n');
        cin.getline(customerName, 80); //from user
        cout << "Enter Customer Street Address: "; //to user
        cin.getline(customerStreetAddress, 80); //from user
        cout << "Enter City, State, Zip: "; //to user
        cin.getline(customerCityStateZip, 80); //from user
        
        //Get Product Quantities
        cout << "Enter Quantity of " << product1Description << " (" << product1Price << "): "; //to user
        cin >> product1Quantity; //from user
        cout << "Enter Quantity of " << product2Description << " (" << product2Price << "): "; //to user
        cin >> product2Quantity; //from user
        cout << "Enter Quantity of " << product3Description << " (" << product3Price << "): "; //to user
        cin >> product3Quantity; //from user
        
        //Calculate Extended Cost
        product1ExtendedCost = product1Price * product1Quantity;
        product2ExtendedCost = product2Price * product2Quantity;
        product3ExtendedCost = product3Price * product3Quantity;
        
        //Calculate Subtotal
        subtotal = product1ExtendedCost + product2ExtendedCost + product3ExtendedCost;
        
        //Calculate Tax
        tax = subtotal * 0.08;
        
        //Calculate Total
        total = subtotal + tax;
        
        //Display Bill
        cout << setw(80) << "MIRACLE TOOLS" << endl; //to user
        cout << setw(92) << "When it's a good tool, it's a MIRACLE!" << endl << endl; //to user
        cout << customerName << endl; //to user
        cout << customerStreetAddress << endl; //to user
        cout << customerCityStateZip << endl << endl; //to user
        cout << "Tool" << setw(40) << "Price" << setw(20) << "Quantity" << setw(27) << "Extended Cost" << endl;
        if(product1Quantity > 0){
            cout << product1Description << setw(28) << product1Price << setw(20) << product1Quantity << setw(27) << product1ExtendedCost << endl;
        }
        if(product2Quantity > 0){
            cout << product2Description << setw(23) << product2Price << setw(20) << product2Quantity << setw(27) << product2ExtendedCost << endl;
        }
        if(product3Quantity > 0){
            cout << product3Description << setw(22) << product3Price << setw(20) << product3Quantity << setw(27) << product3ExtendedCost << endl << endl;
        }
        cout << fixed << setprecision(2) << setw(74) << "Subtotal: " << setw(17) << subtotal << endl << endl; //to user
        cout << fixed << setprecision(2) << setw(76) << "Tax (8.0%): " << setw(15) << tax << endl << endl; //to user
        cout << fixed << setprecision(2) << setw(71) << "Total: " << setw(20) << total << endl; //to user
    }
    
    if(userChoice == 2){
       
        //Get New Prices
        cout << "Enter New Price for " << product1Description << " (" << product1Price << "): "; //to user
        cin >> product1Price; //from user
        cout << "Enter New Price for " << product2Description << " (" << product2Price << "): "; //to user
        cin >> product2Price; //from user
        cout << "Enter New Price for " << product3Description << " (" << product3Price << "): "; //to user
        cin >> product3Price; //from user
        
        //Create Updated Price File
        newProductInformationFile.open("productInformation.txt", ios::out);
        newProductInformationFile << product1Description << endl;
        newProductInformationFile << fixed << setprecision(2) << product1Price << endl;
        newProductInformationFile << product2Description << endl;
        newProductInformationFile << fixed << setprecision(2) << product2Price << endl;
        newProductInformationFile << product3Description << endl;
        newProductInformationFile << fixed << setprecision(2) << product3Price << endl;   
        newProductInformationFile.close();
    }
    
    return 0;
}

