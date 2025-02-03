// CSC 134
// M2T2 - Receipt
// smelcerl
// 2/3/2025

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setprecision(2) << fixed;
    string store_name = "Smelcer's BBQ";
    string food_name = "bbq plate";
    double food_cost = 7.99;
    double subtotal, total, tax_percent, tax_cost; 
    int food_amount;
    
    cout << "Welcome to " << store_name << "!" << endl;
    cout << "How many bbq plates would you like? ";
    cin >> food_amount;

    double food_price = food_cost * food_amount;
    
    cout << "You ordered " << food_amount << " " << food_name << " and it's $" << food_price << "." << endl;
    cout << endl;

    tax_percent = 0.08;
    tax_cost = food_price * tax_percent;
    subtotal = food_price;
    total = subtotal + tax_cost;

    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax (8%): $" << tax_cost << endl;
    cout << "   Total: $" << total << endl;
    
    cout << "Have a nice day!" << endl;
    return 0;
}