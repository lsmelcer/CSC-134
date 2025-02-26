// CSC 134
// M3T3
// norrisa
// 2/17/2025
// Start with dice rolls
// What dice are you using today?
// norris - 1d20

#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    const int SIDES = 6; // yours will differ!
    //int seed = 19;
    int seed = time(0);
    // seed the random number generator
    srand(seed);
    // rand() is a large number, so we take the remainder which is %
    int roll1, roll2, total;
    int point = 11;
    // roll a few times
    roll1 = ( (rand() % SIDES)+1 );
    roll2 = ( (rand() % SIDES)+1 );
    total = roll1 + roll2;

    cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;
    if (7 == total || point == total) {
        cout << "You win!" << endl;
    }
    else if (2 == total || 3 == total || 12 == total) {
        cout << "You lose." << endl;
    }
    else {
        cout << "Your point is " << total << endl;
        point = total;
        roll1 = ( (rand() % SIDES)+1 );
        roll2 = ( (rand() % SIDES)+1 );
        total = roll1 + roll2;
        cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;
        if (7 == total || point == total) {
            cout << "You win!" << endl;
        }
        else if (2 == total || 3 == total || 12 == total) {
            cout << "You lose." << endl;
        }
        while (total != 7 && total != point) {
            roll1 = ( (rand() % SIDES)+1 );
            roll2 = ( (rand() % SIDES)+1 );
            total = roll1 + roll2;
            cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;
            if (point == total) {
                cout << "You win!" << endl;
            }
            else if (7 == total) {
                cout << "You lose." << endl;
            }
        }
    }
}