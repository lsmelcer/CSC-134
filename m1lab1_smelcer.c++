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
    string customer_name;
    int num_apples = 100;
    double price_each = 0.25;
    int customer_want;

    cout << "Hi, what's your name? ";
    cin >> customer_name;
    cout << "Nice to meet you, " << customer_name << endl;
    
    cout << endl;
    
    cout << "Welcome to the " << name << " Apple Farm." << endl;
    cout << "We have " << num_apples << " apples in stock." << endl;
    cout << "Price per apple is: $" << price_each << endl;
    
    cout << endl;

    cout << "How many apples would you like? ";
    cin >> customer_want;
    cout << endl;
    

    // Calculate total
    double total_cost = customer_want * price_each;

    // print answer
    cout << fixed << setprecision(2); // this ensures two decimal places are always printed
    cout << "The total for all your " << customer_want << " apples is $" << total_cost << endl;
    cout << "thank you for visiting " << name << " Apple Farm, " << customer_name << "! We hope to see you again!" << endl;
    
     return 0;

}