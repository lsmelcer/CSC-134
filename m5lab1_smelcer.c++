#include <iostream>
using namespace std;

/*
CSC 134
M5LAB1 - Choose Your Own Adventure
smelcerl
3/26/25
*/

void main_menu();
void choice_front_door();
void choice_back_door();
void choice_stay_home();
void front_door_2();
void choice_take_cover();
void choice_run_away();
void choice_fight_back();
void choice_fake_valuables();
void choice_all_valuables();
void choice_peek_window();
void choice_stay_put();
// TODO: add more choices here

int main() {
  cout << "Surviving O'Block" << endl;
  main_menu();
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  cout << "Main Menu" << endl;
  cout << "You're in your house located in the Parkway Garden Homes in Chicago. It's 2018/2019. You need to get to work." << endl;
  cout << "Do you:" << endl;
  cout << "1. Leave through the front door" << endl;
  cout << "2. Go out the back door" << endl;
  cout << "3. Forget it, and stay home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_stay_home();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

void choice_front_door() {
  cout << "Leave through the front door." << endl;
  cout << "You open it. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Shut the door and go out through the back." << endl;
  cout << "2. Go out the front door." << endl;
  cout << "3. Shut the door and stay home." << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    choice_stay_home();
  } else if (3 == choice) {
    front_door_2();
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore();
    }
}

void choice_back_door() { 
    cout << "You decide to leave out the back door." << endl;
    cout << "As you're walking along the back alley, you hear a shootout happen." << endl;
    cout << "You're happy you walked out the back door, as it might have saved your life." << endl;
    cout << "Unfortunately, you're not totally out of the clear." << endl;
    cout << "As you were walking, a man jumped into your path and immediately threatened you, demanding all valuables and money." << endl;
    cout << "Do you:" << endl;
    cout << "1. Fight back" << endl;
    cout << "2. Only give some valuables" << endl;
    cout << "3. Give all your valuables and money." << endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (choice == 1) {
        choice_fight_back();
    } else if (choice == 2) {
        choice_fake_valuables();
    } else if (choice == 3) {
        choice_all_valuables();
    } else {
        cout << "That's not a valid choice, please try again." << endl;
        cin.ignore();
    }
}

void choice_fight_back() {
    cout << "You chose to fight back" << endl;
    cout << "Unfortunately for you, the man had a gun." << endl;
    cout << "You get shot and start bleeding out." << endl;
    cout << "While the guy is rummaging through your pockets, he gets shot and killed by somebody else." << endl;
    cout << "Tht somebody else was King Von, and now he is the one going through your pockets." << endl;
    cout << "You bleed out and you die." << endl;
    cout << "Game over." << endl;
    return;
}

void choice_fake_valuables() {
    cout << "You choose to try and fake him out and not give all your valuables." << endl;
    cout << "Unfortunately, the man noticed your chain, and shot you for you faking what you had." << endl;
    cout << "You get shot and start bleeding out." << endl;
    cout << "While the guy is rummaging through your pockets, he gets shot and killed by somebody else." << endl;
    cout << "Tht somebody else was King Von, and now he is the one going through your pockets." << endl;
    cout << "You bleed out and you die." << endl;
    cout << "Game over." << endl;
    return;
}

void choice_all_valuables() {
    cout << "You decide to give him everything you have." << endl;
    cout << "Next thing you know, he gets shot." << endl;
    cout << "Right after he gets shot, the shooter yells at you to take your stuff back." << endl;
    cout << "You quickly leave the area, making it to the bus stop with no more incidents." << endl;
    cout << "You make it to work on time and you have a good shift, even earning a promotion!" << endl;
    cout << "You're able to move out of O'Block, and you no longer get caught in between gang beef." << endl;
    cout << "Game over." << endl;
    return;
}

void choice_stay_home() { 
    cout << "You decide to skip work and stay home for the day." << endl;
    cout << "While relaxing at home, you hear a commotion outside." << endl;
    cout << "Do you:" << endl;
    cout << "1. Peek through the window" << endl;
    cout << "2. Stay where you're at and ignore it" << endl;
    cout << "3. Leave through the back door to get away from it." << endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (choice == 1) {
        choice_peek_window();
    } else if (choice == 2) {
        choice_stay_put();
    } else if (choice == 3) {
        choice_back_door();
    } else {
        cout << "That's not a valid choice, please try again." << endl;
        cin.ignore();
    }
}

void choice_peek_window() {
    cout << "You decide to look through the window." << endl;
    cout << "You look out the window and see two men arguing." << endl;
    cout << "Suddenly, one of the men pulls out a gun and starts firing." << endl;
    cout << "You get hit in the crossfire, and bleed out inside your home." << endl;
    cout << "Game over." << endl;
    return;
}

void choice_stay_put() {
    cout << "You decide to stay right where your at." << endl;
    cout << "All of a sudden, you hear gunshots outside the front door." << endl;
    cout << "One of your windows shatter, and a couple stray bullets make their way into your home." << endl;
    cout << "Thankfully, you are unscathed and nothing happens to you." << endl;
    cout << "Later on in the day, you get a call from your boss." << endl;
    cout << "It's your boss." << endl;
    cout << "He tells you that because of your absence, you have been fired." << endl;
    cout << "You are now unemployed." << endl;
    cout << "Game over." << endl;
    return;
}

void front_door_2() { 
    cout << "You walk out through the front door." << endl; 
    cout << "You walk down the steps and see two men arguing." << endl;
    cout << "Suddenly, one of the men pulls out a Glock 19 with a switch." << endl;
    cout << "The man opens fire, do you:" << endl;
    cout << "1. Run away as far and as fast as you can." << endl;
    cout << "2. Take cover quickly and wait it out." << endl;
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (1 == choice) {
        choice_run_away();
    } else if (2 == choice) {
        choice_take_cover();
    } else {
        cout << "That's not a valid choice, please try again." << endl;
        cin.ignore();
    }

}

void choice_run_away() {
    cout << "You run as fast as you can." << endl;
    cout << "Unfortunately, due to the switch, you also get gunned down in the crossfire." << endl;
    cout << "You look up and see the man who has just shot you is the grim reaper himself, King Von." << endl;
    cout << "You bleed out, knowing you are now likely to be mentioned in a King Von song." << endl;
    cout << "Game over." << endl; 
    return;
}

void choice_take_cover() {
    cout << "You decide to take cover and wait it out." << endl;
    cout << "You manage to take cover behind a brick wall." << endl;
    cout << "You hear the sound of a Glock 19 with a switch firing, and the unmistakable sound of the human body getting shot." << endl;
    cout << "You wait about five minutes after the final shot was made, and come out to see multiple bodies sitting in their own pool of blood, with no killer in sight." << endl;
    cout << "You smartly keep walking, and make your way to the bus stop." << endl;
    cout << "You successfully make it to work, and have a good shift." << endl;
    cout << "Game over." << endl;
    return;
}