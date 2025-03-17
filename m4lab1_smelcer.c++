/*
CSC 134
M4LAB1 - Grid with Loops
smelcerl
3/17/25
nested Loops
*/

#include <iostream>
using namespace std;

int main() {
    //string pattern = "🌿🌱";
    string pattern = "🚬🍃";
    int WIDTH;
    int HEIGHT;

    cout << "Enter a width: ";
    cin >> WIDTH;
    if (WIDTH < 1) {
        cout << "Invalid value. Please input a positive value. ";
        cin >> WIDTH;
    }
    cout << endl;

    cout << "Enter a height: ";
    cin >> HEIGHT;
    if (HEIGHT < 1) {
        cout << "Invalid value. Please input a positive value. ";
        cin >> HEIGHT;
    }
    cout << endl;
    
    /*
    int count = 0;
    while (count < WIDTH) {
        cout << pattern;
        count++;
    }
    cout << endl;
    */
    
    cout << "Row" << endl;
    for (int i=0; i < WIDTH; i++) {
        cout << pattern;
    }
    cout << endl;

    cout << "column" << endl;
    for (int i=0; i < HEIGHT; i++) {
        cout << pattern << endl;
    }

    cout << "Square of " << WIDTH << " by " << HEIGHT << endl;
    for (int v=0; v < HEIGHT; v++) {
        for (int h=0; h < WIDTH; h++) {
            cout << pattern;
        }
        cout << endl;
    }
}