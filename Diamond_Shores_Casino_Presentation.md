
# Diamond Shores Casino
### A Multi-Game Virtual Casino in C++  
**Presented by:** [Louis Smelcer]  
**Course/Project:** [C++ Final Project]  
**Date:** [5/14/2025]

---

## Slide 2: Introduction
### What is Diamond Shores Casino?
- A virtual casino simulation built in C++.
- Offers five classic casino games.
- Emulates a chip-based betting experience.
- Designed using a modular, function-based approach.

---

## Slide 3: Game Overview
### Games Included:
- **Blackjack** – Classic 21-point card game.
- **Craps** – Dice game involving betting on outcomes.
- **Roulette** – Spin the wheel and pick red, black, or a number.
- **Baccarat** – Player vs Banker hand comparison with draw rules.
- **Slots** – Simulated slot machine with randomized reels.

---

## Slide 4: Game Architecture
### Core Design Features:
- Main game loop handles game selection and chip balance.
- Player starts with a chip pool (e.g., 1000 chips).
- Each game modifies chip count based on outcomes.
- Games implemented as separate functions for clarity and modularity.

---

## Slide 5: Baccarat Deep Dive
### Why Baccarat Stands Out:
- Implements card drawing using `drawCard()` and a simulated deck.
- Calculates hand values (modulo 10 rule).
- Uses real-world Baccarat logic:
  - Player draws 3rd card based on initial total.
  - Banker draws based on complex conditional rules.
- Uses `vector<int>` to manage player and banker hands.
- Outputs hands visually using `printHand()`.

---

## Slide 6: Key Features
### Highlights of the Program:
- Random number generation for realism (`rand()`, seeded with `time(0)`)
- Clear terminal-based UI (text prompts and feedback).
- Consistent chip-tracking across all games.
- Timed pauses (`this_thread::sleep_for`) simulate real gameplay pacing.
- Organized, reusable code design—easy to expand.

---

## Slide 7: Sample Gameplay Flow
1. Program welcomes the player and shows available chips.
2. Player selects a game from a menu.
3. Player places a bet (validated against balance).
4. Game plays out and updates chip count.
5. Player can return to menu or exit.

---

## Slide 8: Future Enhancements
### Ideas for Growth:
- Add a **Graphical User Interface (GUI)** using SFML or Qt.
- Introduce **persistent profiles** to save player progress.
- Add more games (e.g., poker, keno).
- Implement **multiplayer** or simulated AI opponents.
- Refactor for object-oriented design (use classes).

---

## Slide 9: Conclusion
- Diamond Shores Casino showcases how **modular programming** can build engaging simulations.
- Provides a platform for learning **C++ structures, randomness, and logic handling.**
- Great foundation for expanding into more complex or graphical applications.
- A fun and educational project for programmers interested in gaming and simulations.
