#include <iostream>
using namespace std;

void say_hi();
int add(int first, int second);
void print_number(int num);
int global_x = 999;

int main() {
    int my_num = 50;
    say_hi();
    cout << "In main(), my_num = " << my_num << endl;
    cout << "global_x = " << global_x << endl;
    cout << "2 + 2 = ";
    int num = add(2, 2);
    print_number(num);
}

void say_hi() {
    cout << "Hi" << endl;
}

int add(int first, int second) {
    int answer = first + second;
    return answer;
}

void print_number(int num) {
    cout << num << endl;
}