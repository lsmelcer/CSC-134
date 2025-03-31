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

// Function to display the menu
void displayMenu() {
    std::cout << "Welcome to the Casino!" << std::endl;
    std::cout << "1. Blackjack" << std::endl;
    std::cout << "2. Craps" << std::endl;
    std::cout << "3. Roulette" << std::endl;
    std::cout << "4. Baccarat" << std::endl;
    std::cout << "5. Slots" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Please choose a game (1-6): ";
}

// Function to get chips from the player
int getChips() {
    int chips = 0;
    std::cout << "Enter your initial amount of chips: ";
    std::cin >> chips;
    return chips;
}

// Function to handle game switching logic
void playGame(int& chips) {
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

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
                std::cout << "Thank you for playing! You leave with " << chips << " chips." << std::endl;
                return; // Exit the game
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        if (chips <= 0) {
            std::cout << "You ran out of chips! Game Over!" << std::endl;
            return; // Exit if the player runs out of chips
        }
    }
}

// Blackjack logic (stubbed for now)
void playBlackjack(int& chips) {
    int bet;
    std::cout << "How much would you like to bet on Blackjack? ";
    std::cin >> bet;

    if (bet > chips) {
        std::cout << "You don't have enough chips for that bet!" << std::endl;
        return;
    }

    // Insert actual Blackjack logic here
    std::cout << "You played Blackjack. You lost the bet!" << std::endl;
    chips -= bet; // Update chip count (based on actual game result)
}

// Craps logic (fixed)
void playCraps(int& chips) {
    const int SIDES = 6;  // Number of sides on the dice
    int roll1, roll2, total;
    int point;
    int betAmount;

    // Ask the player to place a bet
    std::cout << "You have $" << chips << " chips. Enter your bet amount: $";
    std::cin >> betAmount;

    if (betAmount > chips) {
        std::cout << "You don't have enough chips to place that bet!" << std::endl;
        return;  // Exit if the player doesn't have enough chips
    }

    // First roll
    roll1 = (rand() % SIDES) + 1;
    roll2 = (rand() % SIDES) + 1;
    total = roll1 + roll2;

    std::cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << std::endl;

    if (total == 7 || total == 11) {
        std::cout << "You win!" << std::endl;
        chips += betAmount;  // Add winnings to chips
    } else if (total == 2 || total == 3 || total == 12) {
        std::cout << "You lose." << std::endl;
        chips -= betAmount;  // Subtract the bet amount from chips
    } else {
        std::cout << "Your point is " << total << std::endl;
        point = total;

        // Subsequent rolls
        while (true) {
            roll1 = (rand() % SIDES) + 1;
            roll2 = (rand() % SIDES) + 1;
            total = roll1 + roll2;
            std::cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << std::endl;

            if (total == point) {
                std::cout << "You win!" << std::endl;
                chips += betAmount;  // Add winnings to chips
                break;
            } else if (total == 7) {
                std::cout << "You lose." << std::endl;
                chips -= betAmount;  // Subtract the bet amount from chips
                break;
            }
        }
    }

    // Display updated chip balance
    std::cout << "Your current chip balance is: $" << chips << std::endl;
}

// Roulette logic (fixed)
int spinRouletteWheel() {
    return rand() % 37;  // Returns a number between 0 and 36
}

void playRoulette(int& chips) {
    std::vector<int> betTypes;
    std::vector<int> betNumbers;
    std::vector<std::string> betColors;
    std::vector<int> betAmounts;

    int spunNumber;
    std::string spunColor;
    int betAmount;
    int betType;

    char addAnotherBet;

    // Ask the player to place bets and choose bet types
    do {
        // Ask the player to place a bet amount
        std::cout << "You have $" << chips << " chips. Enter your bet amount: $";
        std::cin >> betAmount;

        // Check if the player has enough chips
        if (betAmount > chips) {
            std::cout << "You don't have enough chips for that bet!" << std::endl;
            continue;  // Prompt for bet amount again if player doesn't have enough chips
        }

        betAmounts.push_back(betAmount);

        // Ask the player to choose a bet type
        std::cout << "Choose your bet type:\n";
        std::cout << "1. Bet on a specific number (0-36)\n";
        std::cout << "2. Bet on Red or Black\n";
        std::cout << "3. Bet on 1st 12 (1-12)\n";
        std::cout << "4. Bet on 2nd 12 (13-24)\n";
        std::cout << "5. Bet on 3rd 12 (25-36)\n";
        std::cout << "6. Bet on 1st 18 (1-18)\n";
        std::cout << "7. Bet on 2nd 18 (19-36)\n";
        std::cout << "8. Bet on Even\n";
        std::cout << "9. Bet on Odd\n";
        std::cout << "Enter your choice (1-9): ";
        std::cin >> betType;
        betTypes.push_back(betType);

        // For specific number bet
        if (betType == 1) {
            int betNumber;
            std::cout << "Enter a number to bet on (0-36): ";
            std::cin >> betNumber;
            betNumbers.push_back(betNumber);
        } else {
            betNumbers.push_back(-1);  // -1 for non-specific-number bets
        }

        // For Red or Black bet
        if (betType == 2) {
            std::string betColor;
            std::cout << "Enter a color to bet on (Red/Black): ";
            std::cin >> betColor;
            betColors.push_back(betColor);
        } else {
            betColors.push_back("");  // Empty string for non-color bets
        }

        // Ask if the player wants to place another bet
        std::cout << "Do you want to place another bet? (y/n): ";
        std::cin >> addAnotherBet;

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
    std::cout << "The wheel spun: " << spunNumber << " (" << spunColor << ")" << std::endl;

    // Payout calculation (keeping structure intact)
    int payout = 0;  // Payout multiplier (will be used to calculate total payout)
    int totalPayout = 0;
    bool won;

    // Process each bet placed by the player
    for (size_t i = 0; i < betTypes.size(); i++) {
        int currentBetType = betTypes[i];
        int currentBetNumber = betNumbers[i];
        std::string currentBetColor = betColors[i];
        int currentBetAmount = betAmounts[i];

        won = false;
        payout = 0;

        switch (currentBetType) {
            case 1: // Bet on a specific number (Straight Up)
                if (currentBetNumber == spunNumber) {
                    payout = 35; // Pays 35 to 1
                    std::cout << "Congratulations! You win the number bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the number bet." << std::endl;
                }
                break;

            case 2: // Bet on Red or Black
                if (currentBetColor == spunColor) {
                    payout = 1; // Pays 1 to 1
                    std::cout << "Congratulations! You win the color bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the color bet." << std::endl;
                }
                break;

            case 3: // Bet on 1st 12 (1-12)
                if (spunNumber >= 1 && spunNumber <= 12) {
                    payout = 2; // Pays 2 to 1
                    std::cout << "Congratulations! You win the 1st 12 bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the 1st 12 bet." << std::endl;
                }
                break;

            case 4: // Bet on 2nd 12 (13-24)
                if (spunNumber >= 13 && spunNumber <= 24) {
                    payout = 2; // Pays 2 to 1
                    std::cout << "Congratulations! You win the 2nd 12 bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the 2nd 12 bet." << std::endl;
                }
                break;

            case 5: // Bet on 3rd 12 (25-36)
                if (spunNumber >= 25 && spunNumber <= 36) {
                    payout = 2; // Pays 2 to 1
                    std::cout << "Congratulations! You win the 3rd 12 bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the 3rd 12 bet." << std::endl;
                }
                break;

            case 6: // Bet on 1st 18 (1-18)
                if (spunNumber >= 1 && spunNumber <= 18) {
                    payout = 1; // Pays 1 to 1
                    std::cout << "Congratulations! You win the 1st 18 bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the 1st 18 bet." << std::endl;
                }
                break;

            case 7: // Bet on 2nd 18 (19-36)
                if (spunNumber >= 19 && spunNumber <= 36) {
                    payout = 1; // Pays 1 to 1
                    std::cout << "Congratulations! You win the 2nd 18 bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the 2nd 18 bet." << std::endl;
                }
                break;

            case 8: // Bet on Even
                if (spunNumber != 0 && spunNumber % 2 == 0) {
                    payout = 1; // Pays 1 to 1
                    std::cout << "Congratulations! You win the Even bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the Even bet." << std::endl;
                }
                break;

            case 9: // Bet on Odd
                if (spunNumber != 0 && spunNumber % 2 != 0) {
                    payout = 1; // Pays 1 to 1
                    std::cout << "Congratulations! You win the Odd bet!" << std::endl;
                    won = true;
                } else {
                    std::cout << "Sorry, you lost the Odd bet." << std::endl;
                }
                break;

            default:
                std::cout << "Invalid bet type selected!" << std::endl;
        }

        // Calculate total payout for this bet
        if (won) {
            totalPayout += currentBetAmount * payout;
        }
    }

    // Show the total winnings for all bets
    if (totalPayout > 0) {
        std::cout << "You win a total of $" << totalPayout << "!" << std::endl;
        chips += totalPayout;  // Add winnings to chips
    } else {
        std::cout << "Better luck next time!" << std::endl;
    }
}

// Baccarat logic (stubbed for now)
void playBaccarat(int& chips) {
    int bet;
    std::cout << "How much would you like to bet on Baccarat? ";
    std::cin >> bet;

    if (bet > chips) {
        std::cout << "You don't have enough chips for that bet!" << std::endl;
        return;
    }

    // Insert actual Baccarat logic here
    std::cout << "You played Baccarat. You won the bet!" << std::endl;
    chips += bet; // Update chip count (based on actual game result)
}

// Slots logic (stubbed for now)
void playSlots(int& chips) {
    int bet;
    std::cout << "How much would you like to bet on Slots? ";
    std::cin >> bet;

    if (bet > chips) {
        std::cout << "You don't have enough chips for that bet!" << std::endl;
        return;
    }

    // Insert actual Slots logic here
    std::cout << "You played Slots. You lost the bet!" << std::endl;
    chips -= bet; // Update chip count (based on actual game result)
}

int main() {
    srand(time(0)); // Initialize random number generator for randomness in games

    int chips = getChips();  // Start the game with an initial chip amount
    playGame(chips);         // Start the main game loop
    return 0;
}
