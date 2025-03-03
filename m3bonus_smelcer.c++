#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function to simulate the roulette spin (roll the wheel)
int spinRouletteWheel() {
    return rand() % 37;  // Returns a number between 0 and 36
}

// Function to handle player's bet and spin the wheel
void playRoulette() {
    vector<int> betTypes;
    vector<int> betNumbers;
    vector<string> betColors;
    vector<int> betAmounts;

    int spunNumber;
    string spunColor;
    int betAmount;
    int betType;

    char addAnotherBet;

    // Ask the player to place bets and choose bet types
    do {
        // Ask the player to place a bet amount
        cout << "Enter your bet amount: $";
        cin >> betAmount;
        betAmounts.push_back(betAmount);

        // Ask the player to choose a bet type
        cout << "Choose your bet type:\n";
        cout << "1. Bet on a specific number (0-36)\n";
        cout << "2. Bet on Red or Black\n";
        cout << "3. Bet on 1st 12 (1-12)\n";
        cout << "4. Bet on 2nd 12 (13-24)\n";
        cout << "5. Bet on 3rd 12 (25-36)\n";
        cout << "6. Bet on 1st 18 (1-18)\n";
        cout << "7. Bet on 2nd 18 (19-36)\n";
        cout << "8. Bet on Even\n";
        cout << "9. Bet on Odd\n";
        cout << "Enter your choice (1-9): ";
        cin >> betType;
        betTypes.push_back(betType);

        // For specific number bet
        if (betType == 1) {
            int betNumber;
            cout << "Enter a number to bet on (0-36): ";
            cin >> betNumber;
            betNumbers.push_back(betNumber);
        } else {
            betNumbers.push_back(-1);  // -1 for non-specific-number bets
        }

        // For Red or Black bet
        if (betType == 2) {
            string betColor;
            cout << "Enter a color to bet on (Red/Black): ";
            cin >> betColor;
            betColors.push_back(betColor);
        } else {
            betColors.push_back("");  // Empty string for non-color bets
        }

        // Ask if the player wants to place another bet
        cout << "Do you want to place another bet? (y/n): ";
        cin >> addAnotherBet;

    } while (addAnotherBet == 'y' || addAnotherBet == 'Y');  // Repeat if 'y' or 'Y'

    // Spin the roulette wheel
    spunNumber = spinRouletteWheel();

    // Determine the color of the spun number
    if (spunNumber == 0) {
        spunColor = "Green";  // Special case for 0
    } else if ((spunNumber >= 1 && spunNumber <= 10) || (spunNumber >= 19 && spunNumber <= 28)) {
        // Numbers 1-10, 19-28 alternate between Red and Black
        if (spunNumber % 2 == 0) {
            spunColor = "Black";
        } else {
            spunColor = "Red";
        }
    } else {
        // Numbers 11-18, 29-36 alternate between Red and Black
        if (spunNumber % 2 == 0) {
            spunColor = "Red";
        } else {
            spunColor = "Black";
        }
    }

    // Output the result of the spin
    cout << "The wheel spun: " << spunNumber << " (" << spunColor << ")" << endl;

    // Payout calculation
    int payout = 0;  // Payout multiplier (will be used to calculate total payout)
    int totalPayout = 0;
    bool won;

    // Process each bet placed by the player
    for (size_t i = 0; i < betTypes.size(); i++) {
        int currentBetType = betTypes[i];
        int currentBetNumber = betNumbers[i];
        string currentBetColor = betColors[i];
        int currentBetAmount = betAmounts[i];

        won = false;
        payout = 0;

        switch (currentBetType) {
            case 1: // Bet on a specific number (Straight Up)
                if (currentBetNumber == spunNumber) {
                    payout = 35; // Pays 35 to 1
                    cout << "Congratulations! You win the number bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the number bet." << endl;
                }
                break;

            case 2: // Bet on Red or Black
                if (currentBetColor == spunColor) {
                    payout = 1; // Pays 1 to 1
                    cout << "Congratulations! You win the color bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the color bet." << endl;
                }
                break;

            case 3: // Bet on 1st 12 (1-12)
                if (spunNumber >= 1 && spunNumber <= 12) {
                    payout = 2; // Pays 2 to 1
                    cout << "Congratulations! You win the 1st 12 bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the 1st 12 bet." << endl;
                }
                break;

            case 4: // Bet on 2nd 12 (13-24)
                if (spunNumber >= 13 && spunNumber <= 24) {
                    payout = 2; // Pays 2 to 1
                    cout << "Congratulations! You win the 2nd 12 bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the 2nd 12 bet." << endl;
                }
                break;

            case 5: // Bet on 3rd 12 (25-36)
                if (spunNumber >= 25 && spunNumber <= 36) {
                    payout = 2; // Pays 2 to 1
                    cout << "Congratulations! You win the 3rd 12 bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the 3rd 12 bet." << endl;
                }
                break;

            case 6: // Bet on 1st 18 (1-18)
                if (spunNumber >= 1 && spunNumber <= 18) {
                    payout = 1; // Pays 1 to 1
                    cout << "Congratulations! You win the 1st 18 bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the 1st 18 bet." << endl;
                }
                break;

            case 7: // Bet on 2nd 18 (19-36)
                if (spunNumber >= 19 && spunNumber <= 36) {
                    payout = 1; // Pays 1 to 1
                    cout << "Congratulations! You win the 2nd 18 bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the 2nd 18 bet." << endl;
                }
                break;

            case 8: // Bet on Even
                if (spunNumber != 0 && spunNumber % 2 == 0) {
                    payout = 1; // Pays 1 to 1
                    cout << "Congratulations! You win the Even bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the Even bet." << endl;
                }
                break;

            case 9: // Bet on Odd
                if (spunNumber != 0 && spunNumber % 2 != 0) {
                    payout = 1; // Pays 1 to 1
                    cout << "Congratulations! You win the Odd bet!" << endl;
                    won = true;
                } else {
                    cout << "Sorry, you lost the Odd bet." << endl;
                }
                break;

            default:
                cout << "Invalid bet type selected!" << endl;
        }

        // Calculate total payout for this bet
        if (won) {
            totalPayout += currentBetAmount * payout;
        }
    }

    // Show the total winnings for all bets
    if (totalPayout > 0) {
        cout << "You win a total of $" << totalPayout << "!" << endl;
    } else {
        cout << "Better luck next time!" << endl;
    }
}

// Main function
int main() {
    srand(time(0));  // Initialize the random number generator

    char playAgain;  // Variable to ask the user if they want to play again

    do {
        playRoulette();  // Call the function to play a round of roulette

        // Ask if the player wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');  // If the player enters 'y' or 'Y', play again

    cout << "Thanks for playing Roulette!" << endl;
    return 0;
}
