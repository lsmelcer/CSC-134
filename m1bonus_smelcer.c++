// CSC 134
// M1Bonus
// smelcerl
// 1/29/2025

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Problem one, calculating a rectangle with a width of 10 and a height of 8." << endl;

    int height = 8;
    int width = 10; 
    int area;

    area = height * width;

    cout << area << endl;
    cout << endl;

    cout << "Problem two, calculating cost with sales tax.";

    double price = 99.99;
    double sales_tax = 0.08;
    double sales_tax_amount;
    double total;

    sales_tax_amount = price * sales_tax;
    total = price + sales_tax_amount;

    cout << fixed << setprecision(2);
    cout << "Product price: $" << price << endl;
    cout << "Sales tax amount: $" << sales_tax_amount << endl;
    cout << "Total cost: $" << total << endl;
    cout << endl;

    cout << "Problem three, calculating a 12 inch pizza's area." << endl;
    cout << endl;

    int pizza_diameter = 12;
    double pi = 3.14;

    int radius = pizza_diameter / 2;
    double pizza_area = radius * radius * pi;

    cout << "The pizza has an area of " << pizza_area << " inches." << endl;
    cout << endl;

    cout << "Problem four, area of each slice of pizza if there is 8 slices." << endl;

    double pizza_slice = pizza_area / 8;
    cout << "Each slice of pizza has an area of " << pizza_slice << " inches." << endl;
}