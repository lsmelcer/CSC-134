#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function to handle game switching logic
void playGame(int& chips);

// Functions for each game (you can replace these with your actual game logic)
void playBlackjack(int& chips);
void playCraps(int& chips);
void playRoulette(int& chips);
void playBaccarat(int& chips);
void playSlots(int& chips);
int spinRouletteWheel();
auto spinReels();

// Function to display the menu
void displayMenu() {
    cout << "Welcome to the Diamond Shores Casino!" << endl;
    cout << "1. Blackjack" << endl;
    cout << "2. Craps" << endl;
    cout << "3. Roulette" << endl;
    cout << "4. Baccarat" << endl;
    cout << "5. Slots" << endl;
    cout << "6. Exit" << endl;
    cout << "Please choose a game (1-6): ";
}

// Function to get chips from the player
int getChips() {
    int chips = 0;
    cout << "Enter your initial amount of chips: ";
    cin >> chips;
    return chips;
}

// Function to handle game switching logic
void playGame(int& chips) {
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                playBlackjack(chips);
                break;
            case 2:
                playCraps(chips);
                break;
            case 3:
                playRoulette(chips);
                break;
            case 4:
                playBaccarat(chips);
                break;
            case 5:
                playSlots(chips);
                break;
            case 6:
                cout << "Thank you for playing! You leave with " << chips << " chips." << endl;
                return; // Exit the game
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        if (chips <= 0) {
            cout << "You ran out of chips! Game Over!" << endl;
            return; // Exit if the player runs out of chips
        }
    }
}

// Blackjack logic (stubbed for now)
void playBlackjack(int& chips) {
    int bet;
    cout << "How much would you like to bet on Blackjack? ";
    cin >> bet;

    if (bet > chips) {
        cout << "You don't have enough chips for that bet!" << endl;
        return;
    }

    // Insert actual Blackjack logic here
    cout << "You played Blackjack. You lost the bet!" << endl;
    chips -= bet; // Update chip count (based on actual game result)
}

// Craps logic (fixed)
void playCraps(int& chips) {
    const int SIDES = 6;  // Number of sides on the dice
    int roll1, roll2, total;
    int point;
    int betAmount;

    // Ask the player to place a bet
    cout << "You have $" << chips << " chips. Enter your bet amount: $";
    cin >> betAmount;

    if (betAmount > chips) {
        cout << "You don't have enough chips to place that bet!" << endl;
        return;  // Exit if the player doesn't have enough chips
    }

    // First roll
    roll1 = (rand() % SIDES) + 1;
    roll2 = (rand() % SIDES) + 1;
    total = roll1 + roll2;

    cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;

    if (total == 7 || total == 11) {
        cout << "You win!" << endl;
        chips += betAmount;  // Add winnings to chips
    } else if (total == 2 || total == 3 || total == 12) {
        cout << "You lose." << endl;
        chips -= betAmount;  // Subtract the bet amount from chips
    } else {
        cout << "Your point is " << total << endl;
        point = total;

        // Subsequent rolls
        while (true) {
            roll1 = (rand() % SIDES) + 1;
            roll2 = (rand() % SIDES) + 1;
            total = roll1 + roll2;
            cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;

            if (total == point) {
                cout << "You win!" << endl;
                chips += betAmount;  // Add winnings to chips
                break;
            } else if (total == 7) {
                cout << "You lose." << endl;
                chips -= betAmount;  // Subtract the bet amount from chips
                break;
            }
        }
    }

    // Display updated chip balance
    cout << "Your current chip balance is: $" << chips << endl;
}

// Roulette logic (fixed)
int spinRouletteWheel() {
    return rand() % 37;  // Returns a number between 0 and 36
}

void playRoulette(int& chips) {
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
        cout << "You have $" << chips << " chips. Enter your bet amount: $";
        cin >> betAmount;

        // Check if the player has enough chips
        if (betAmount > chips) {
            cout << "You don't have enough chips for that bet!" << endl;
            continue;  // Prompt for bet amount again if player doesn't have enough chips
        }

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
        spunColor = (spunNumber % 2 == 0) ? "Black" : "Red";
    } else {
        // Numbers 11-18, 29-36 alternate between Red and Black
        spunColor = (spunNumber % 2 == 0) ? "Red" : "Black";
    }

    // Output the result of the spin
    cout << "The wheel spun: " << spunNumber << " (" << spunColor << ")" << endl;

    // Payout calculation (keeping structure intact)
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
        chips += totalPayout;  // Add winnings to chips
    } else {
        cout << "Better luck next time!" << endl;
    }
}

// Baccarat logic (stubbed for now)
void playBaccarat(int& chips) {
    int bet;
    cout << "How much would you like to bet on Baccarat? ";
    cin >> bet;

    if (bet > chips) {
        cout << "You don't have enough chips for that bet!" << endl;
        return;
    }

    // Insert actual Baccarat logic here
    cout << "You played Baccarat. You lost the bet!" << endl;
    chips -= bet; // Update chip count (based on actual game result)
}

// Fixed Slots logic
void playSlots(int& chips) {
    int bet;
    cout << "How much would you like to bet on Slots? ";
    cin >> bet;

    if (bet > chips) {
        cout << "You don't have enough chips for that bet!" << endl;
        return;
    }

    // Define the possible symbols on the reels
    const string symbols[] = {"🍒", "🍋", "🍊", "🍉", "⭐"};
    const int numSymbols = sizeof(symbols) / sizeof(symbols[0]);

    string reels[3]; // Array to store the results of the spin

    // Spin the reels directly inside playSlots
    for (int i = 0; i < 3; ++i) {
        int randomIndex = rand() % numSymbols; // Random index for the symbols array
        reels[i] = symbols[randomIndex];
    }

    cout << "Spinning... 🎰" << endl;
    cout << "Reels: " << reels[0] << " | " << reels[1] << " | " << reels[2] << endl;

    // Check if all three symbols match
    if (reels[0] == reels[1] && reels[1] == reels[2]) {
        cout << "Congratulations! You win! 🎉" << endl;
        chips += bet; // Add winnings (double the bet)
    } else {
        cout << "Sorry, no win this time. Better luck next time!" << endl;
        chips -= bet; // Subtract the bet if the player loses
    }

    // Display updated chip balance
    cout << "Your current chip balance is: $" << chips << endl;
}


// Main function
int main() {
    srand(time(0));  // Initialize random seed
    int chips = getChips();
    playGame(chips);

    return 0;
}
