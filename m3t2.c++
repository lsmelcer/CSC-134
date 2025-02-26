// M3T2 starting point
// 


#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    int choice;
    cout << "Welcome to the the Lucky Mirage! Please, come play roulette. Enter 1 for red, 2 for black, 3 for green. ";
    cin >> choice;
    int TO_HIT;
    if (choice == 1) {
        TO_HIT <= 8;
    }
    else if (choice == 2) {
        TO_HIT >= 10;
    }
    else {
        TO_HIT = 9;
    }
    const int SIDES = 8; // yours will differ!
    //int seed = rand();
    int seed = time(0);
    cout << "Seed is: " << seed << endl;
    // seed the random number generator
    srand(seed);
    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, total;
    // roll a few times
    roll1 = ( (rand() % SIDES)+1 );
    //cout << roll << endl;

    roll2 = ( (rand() % SIDES)+1 );
    //cout << roll << endl;

    total = roll1 + roll2;
    cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;

    if (total == TO_HIT) {
        if (TO_HIT == 9) {
            cout << "HOLY LUCK. YOU SIR, CAN RETIRE THE FAMILY!!" << endl;
        }
        else {
            cout << "JACKPOT!!!" << endl;
        }
    }
        

    else {
        cout << "Unlucky. You're broke. Take out a second mortgage." << endl;
    }
}