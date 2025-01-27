// CSC 134
// M1Lab1 - Apple Farm
// smelcerl
// 1/27/2025

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string name = "Smelcer";
    int num_apples = 100;
    double price_each = 0.25;

    cout << "Welcome to the " << name << " apple farm." << endl;
    cout << "We have " << num_apples << " apples in stock." << endl;
    cout << "Price per apple is: $" << price_each << endl;
    cout << endl;

    // Calculate total
    double total_cost = num_apples * price_each;

    // print answer
    cout << fixed << setprecision(2); // this ensures two decimal places are always printed
    cout << "The total for all " << num_apples << " is $" << total_cost << endl;
    
     return 0;

}