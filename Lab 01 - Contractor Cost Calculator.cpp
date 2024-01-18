#include <iostream>

using namespace std;

// Name: Justyce Countryman
// Due date: Friday, September 25, 2020
// Project name: Laboratory 01
/* 
 * Project description: Write a program that will compute the costs for each contractor. The program should display the
 * square footage and total cost for the first contractor. For the second contractor, the program should display the
 * total volume of each material that will be used (cubic yards) along with the total cost.
 */
// Project number: Project 01

int main(void) {

    double gravelPrice, concretePrice;
    double sidewalkLength, sidewalkWidth, gravelDepth, concreteDepth;
    double contractor1SqFtPrice, contractor2FullPrice;
    double sidewalkSqFt;
    double contractor1Cost;
    double gravelVolume, concreteVolume;
    double gravelCost, concreteCost;
    double contractor2Cost;
    
    //Set Material Prices
    gravelPrice = 10.19; //per cubic yard
    concretePrice = 73.21; //per cubic yard
    
    //Set Sidewalk Dimensions
    sidewalkLength = 115; //feet
    sidewalkWidth = 4; //feet
    gravelDepth = 0.5; //feet
    concreteDepth = 1.0 / 3.0; //feet
            
    //Set Contractor Prices
    contractor1SqFtPrice = 7.19;
    contractor2FullPrice = 2683.00;
    
    //Compute Square Footage of Sidewalk
    sidewalkSqFt = sidewalkLength * sidewalkWidth;
    
    //Compute Contractor 1 Cost
    contractor1Cost = sidewalkSqFt * contractor1SqFtPrice;
    
    //Compute Volume Needed of Each Material
    gravelVolume = sidewalkSqFt * gravelDepth / 27.0; //cubic yards
    concreteVolume = sidewalkSqFt * concreteDepth / 27.0; //cubic yards
    
    //Compute Costs of Each Material
    gravelCost = gravelVolume * gravelPrice;
    concreteCost = concreteVolume * concretePrice;
    
    //Compute Contractor 2 Cost
    contractor2Cost = contractor2FullPrice + gravelCost + concreteCost;
           
    //Display Contractor 1 Cost Summary
    cout << "Square Feet: " << sidewalkSqFt << endl;
    cout << "Contractor 1 Cost: $ " << contractor1Cost << endl;
    
    //Display Contractor 2 Cost Summary
    cout << "Gravel Volume: " << gravelVolume << endl;
    cout << "Concrete Volume: " << concreteVolume << endl;
    cout << "Contractor 2 Cost: $ " << contractor2Cost << endl;
    
    return 0;
}

