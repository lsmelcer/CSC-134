// CSC 134
// M5T2
// name
// 3/24/2025

// TODO:
// add declarations
// finish the functions
// write main()
#include <iostream>
using namespace std;
int find_square(int number);
void print_line(int number, int square);

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int square = find_square(number);
    print_line(number, square);
}

int find_square(int number) {
    int square = number * number;
    return square;
}

void print_line(int number, int square) {
    cout << number << " " << square << endl;

}