#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

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

// Function to calculate hand value (for Baccarat)
int calculateHandValue(const vector<int>& hand);
// Function to draw a card from the deck (for Baccarat)
int drawCard();
// Function to print the hand (for Baccarat)
void printHand(const vector<int>& hand, const string& handName);
// Function to handle the player's third card decision (for Baccarat)
void playerDrawCard(vector<int>& playerHand);
// Function to handle the banker's third card decision (for Baccarat)
void bankerDrawCard(vector<int>& bankerHand, const vector<int>& playerHand);
// Function to calculate winnings (for Baccarat)
double calculateWinnings(double betAmount, const string& result, const string& betChoice);

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

struct Card {
    string rank;
    string suit;

    Card(string r, string s) : rank(r), suit(s) {}

    string to_string() const {
        return rank + " of " + suit;
    }
};

// ===== Shuffle Deck Function =====
void shuffle_deck(vector<Card>& deck) {
    random_shuffle(deck.begin(), deck.end());
}

// ===== Draw Card Function =====
Card draw_card(vector<Card>& deck) {
    Card drawn_card = deck.back();
    deck.pop_back();
    return drawn_card;
}

void playBlackjack(int& chips) {
    int bet;
    cout << "How much would you like to bet on Blackjack? ";
    cin >> bet;

    if (bet > chips) {
        cout << "You don't have enough chips for that bet!" << endl;
        return;
    }
    
    struct Hand {
        vector<Card> cards;
        int value = 0;

        void add_card(const Card& card) {
            cards.push_back(card);
            if (card.rank == "A") value += 11;
            else if (card.rank == "K" || card.rank == "Q" || card.rank == "J") value += 10;
            else value += stoi(card.rank);
        }

        string to_string() const {
            string hand_str = "";
            for (const auto& card : cards) {
                hand_str += card.to_string() + " ";
            }
            return hand_str;
        }
    };

    vector<Card> deck;
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (const auto& rank : ranks) {
        for (const auto& suit : suits) {
            deck.push_back(Card(rank, suit));
        }
    }

    shuffle_deck(deck);

    Hand player_hand, dealer_hand;

    // Deal initial two cards to each
    player_hand.add_card(draw_card(deck));
    player_hand.add_card(draw_card(deck));

    dealer_hand.add_card(draw_card(deck));
    dealer_hand.add_card(draw_card(deck));

    cout << "Dealer's Hand: " << dealer_hand.cards[0].to_string() << " and [Hidden]" << endl;
    cout << "Player's Hand: " << player_hand.to_string() << "\n" << endl;

    bool split = false;
    Hand hand1 = player_hand, hand2;
    int second_bet = bet;

    if (player_hand.cards.size() == 2 &&
        player_hand.cards[0].rank == player_hand.cards[1].rank &&
        chips >= bet * 2) {

        char split_choice;
        cout << "You have two cards of the same rank. Do you want to split? (y/n): ";
        cin >> split_choice;

        if (split_choice == 'y' || split_choice == 'Y') {
            split = true;
            chips -= bet; // Deduct second bet
            hand1.cards.pop_back();  // Keep first card in hand1
            hand2.add_card(player_hand.cards[1]); // Move second card to new hand

            hand1.value = 0;
            hand1.add_card(player_hand.cards[0]);
            hand1.add_card(draw_card(deck));

            hand2.add_card(draw_card(deck));
            cout << "\nSplit complete. Now playing each hand separately." << endl;
        }
    }
    
    // Lambda to let player play a hand
auto play_hand = [&](Hand& hand, string label) {
    cout << "\n" << label << " - " << hand.to_string() << endl;
    if (hand.value < 21) {
        char choice;
        cout << "Draw another card for " << label << "? (y/n): ";
        cin >> choice;
        while (choice == 'y' && hand.value < 21) {
            hand.add_card(draw_card(deck));
            cout << label << ": " << hand.to_string() << endl;
            if (hand.value >= 21) break;
            cout << "Draw again for " << label << "? (y/n): ";
            cin >> choice;
        }
    }
};

// Play hands based on whether the player split
if (split) {
    play_hand(hand1, "Hand 1");
    play_hand(hand2, "Hand 2");
} else {
    play_hand(player_hand, "Player's Hand");
}


    // Dealer's turn if at least one player hand is valid
if ((split && (hand1.value <= 21 || hand2.value <= 21)) || (!split && player_hand.value <= 21)) {
    cout << "\nDealer's turn..." << endl;
    cout << "Dealer's Hand: " << dealer_hand.to_string() << endl;

    while (dealer_hand.value < 17) {
        cout << "Dealer draws a card..." << endl;
        dealer_hand.add_card(draw_card(deck));
        cout << "Dealer's Hand: " << dealer_hand.to_string() << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Lambda to compare a hand vs dealer
    auto resolve = [&](Hand& hand, const string& label, int& current_chips) {
        if (hand.value > 21) {
            cout << label << " busts! Dealer wins that hand." << endl;
            current_chips -= bet;
        } else if (dealer_hand.value > 21 || hand.value > dealer_hand.value) {
            cout << label << " wins!" << endl;
            current_chips += bet;
        } else if (hand.value < dealer_hand.value) {
            cout << label << " loses." << endl;
            current_chips -= bet;
        } else {
            cout << label << " ties with dealer." << endl;
        }
    };

    if (split) {
        resolve(hand1, "Hand 1", chips);
        resolve(hand2, "Hand 2", chips);
    } else {
        resolve(player_hand, "Player", chips);
    }
} else {
    if (split) {
        if (hand1.value > 21) {
            cout << "Hand 1 busts!" << endl;
            chips -= bet;
        }
        if (hand2.value > 21) {
            cout << "Hand 2 busts!" << endl;
            chips -= bet;
        }
    } else {
        cout << "Player busts! Dealer wins!" << endl;
        chips -= bet;
    }
}


    cout << "Your current chip balance is: $" << chips << endl;
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
        } else {
            totalPayout -= currentBetAmount; // Subtract the bet amount if lost
        }
    }

    // Show the total winnings for all bets
    if (totalPayout > 0) {
        cout << "You win a total of $" << totalPayout << "!" << endl;
        chips += totalPayout;  // Add winnings to chips
    } else {
        cout << "Better luck next time!" << endl;
        chips += totalPayout;  // Subtract losses from chips
    }

    // Display updated chip balance
    cout << "Your current chip balance is: $" << chips << endl;
}

// Baccarat logic
void playBaccarat(int& chips) {
    int bet;
    cout << "How much would you like to bet on Baccarat? ";
    cin >> bet;

    if (bet > chips) {
        cout << "You don't have enough chips for that bet!" << endl;
        return;
    }

    // Ask the player on which outcome they want to bet
    string betChoice;
    cout << "Do you want to bet on Player, Banker, or Tie? ";
    cin >> betChoice;

    // Ensure valid input
    while (betChoice != "Player" && betChoice != "Banker" && betChoice != "Tie") {
        cout << "Invalid choice. Please choose Player, Banker, or Tie: ";
        cin >> betChoice;
    }

    vector<int> playerHand;
    vector<int> bankerHand;
    
    // Draw initial two cards for player and banker
    playerHand.push_back(drawCard());
    playerHand.push_back(drawCard());
    bankerHand.push_back(drawCard());
    bankerHand.push_back(drawCard());

    // Print initial hands
    printHand(playerHand, "Player");
    printHand(bankerHand, "Banker");

    // Handle Player's draw based on their total
    playerDrawCard(playerHand);

    // Print hands after player draw
    printHand(playerHand, "Player");

    // Handle Banker's draw based on their total and the player's actions
    bankerDrawCard(bankerHand, playerHand);

    // Print hands after banker draw
    printHand(bankerHand, "Banker");

    // Calculate the final hand totals
    int playerTotal = calculateHandValue(playerHand);
    int bankerTotal = calculateHandValue(bankerHand);

    // Display hand totals
    cout << "Player Total: " << playerTotal << endl;
    cout << "Banker Total: " << bankerTotal << endl;

    // Determine the result
    string result;
    if (playerTotal > bankerTotal) {
        result = "Player Wins";
        cout << "Player Wins!" << endl;
    } else if (bankerTotal > playerTotal) {
        result = "Banker Wins";
        cout << "Banker Wins!" << endl;
    } else {
        result = "Tie";
        cout << "It's a Tie!" << endl;
    }

    // Calculate winnings or losses
    double winnings = calculateWinnings(bet, result, betChoice);

    // Update chip count
    if (result == betChoice || (betChoice == "Player" && result == "Player Wins") || 
        (betChoice == "Banker" && result == "Banker Wins") || 
        (betChoice == "Tie" && result == "Tie")) {
        cout << "You won the bet!" << endl;
        chips += winnings;
    } else {
        cout << "You lost the bet!" << endl;
        chips -= bet;
    }

    // Display updated chip balance
    cout << "Your current chip balance is: $" << chips << endl;
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
        chips += bet * 2; // Add winnings (triple the bet)
    } else {
        cout << "Sorry, no win this time. Better luck next time!" << endl;
        chips -= bet; // Subtract the bet if the player loses
    }

    // Display updated chip balance
    cout << "Your current chip balance is: $" << chips << endl;
}

// Function to calculate hand value (for Baccarat)
int calculateHandValue(const vector<int>& hand) {
    int sum = 0;
    for (int card : hand) {
        int value = (card % 13) + 1; // Adjust to 1-13 range
        if (value > 9) value = 0; // 10, J, Q, K are worth 0
        else if (value == 1) value = 1; // Ace is worth 1
        sum += value;
    }
    return sum % 10; // Baccarat value is modulo 10
}

// Function to draw a card from the deck (for Baccarat)
int drawCard() {
    return rand() % 52; // 52 cards in a deck
}

// Function to print the hand (for Baccarat)
void printHand(const vector<int>& hand, const string& handName) {
    cout << handName << " Hand: ";
    for (int card : hand) {
        int cardValue = (card % 13) + 1;
        if (cardValue == 11) cout << "J ";
        else if (cardValue == 12) cout << "Q ";
        else if (cardValue == 13) cout << "K ";
        else if (cardValue == 1) cout << "A ";
        else cout << cardValue << " ";
    }
    cout << endl;
}

// Function to handle the player's third card decision (for Baccarat)
void playerDrawCard(vector<int>& playerHand) {
    int playerTotal = calculateHandValue(playerHand);
    if (playerTotal <= 5) { // Player draws a card if total is 5 or less
        cout << "Player draws a third card." << endl;
        playerHand.push_back(drawCard());
    } else {
        cout << "Player stands." << endl;
    }
}

// Function to handle the banker's third card decision (for Baccarat)
void bankerDrawCard(vector<int>& bankerHand, const vector<int>& playerHand) {
    int bankerTotal = calculateHandValue(bankerHand);
    
    if (bankerTotal >= 7) {
        cout << "Banker stands." << endl;
    } else if (bankerTotal <= 2) {
        cout << "Banker draws a third card." << endl;
        bankerHand.push_back(drawCard());
    } else if (playerHand.size() == 2) { // Player didn't draw a third card
        if (bankerTotal <= 5) {
            cout << "Banker draws a third card." << endl;
            bankerHand.push_back(drawCard());
        } else {
            cout << "Banker stands." << endl;
        }
    } else { // Player drew a third card
        int playerThirdCard = playerHand[2] % 13;
        bool bankerShouldDraw = false;
        
        if (bankerTotal == 3) {
            bankerShouldDraw = (playerThirdCard != 8);
        } else if (bankerTotal == 4) {
            bankerShouldDraw = (playerThirdCard >= 2 && playerThirdCard <= 7);
        } else if (bankerTotal == 5) {
            bankerShouldDraw = (playerThirdCard >= 4 && playerThirdCard <= 7);
        } else if (bankerTotal == 6) {
            bankerShouldDraw = (playerThirdCard >= 6 && playerThirdCard <= 7);
        }
        
        if (bankerShouldDraw) {
            cout << "Banker draws a third card." << endl;
            bankerHand.push_back(drawCard());
        } else {
            cout << "Banker stands." << endl;
        }
    }
}

// Function to calculate winnings (for Baccarat)
double calculateWinnings(double betAmount, const string& result, const string& betChoice) {
    double winnings = 0;
    if (betChoice == "Player") {
        if (result == "Player Wins") {
            winnings = betAmount;
        }
    } else if (betChoice == "Banker") {
        if (result == "Banker Wins") {
            winnings = betAmount * 0.95; // Banker win pays 1:1 minus 5% commission
        }
    } else if (betChoice == "Tie") {
        if (result == "Tie") {
            winnings = betAmount * 8; // Tie pays 8:1
        }
    }
    return winnings;
}

// Main function
int main() {
    srand(time(0));  // Initialize random seed
    int chips = getChips();
    playGame(chips);

    return 0;
}