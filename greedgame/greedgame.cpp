#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// Create a function to return a random integer from 0 - 100.
int GetRandomNumber() {
    srand(time(NULL));  // Seed the random number generator with a value of seconds elapsed.
    int number = rand() % 101; // Set the upper limit of the random number to 100.
    return number;
}

// Create a function to clear the console when called.
// (doesn't actually clear the console, but prints 30 empty lines which has the same effect. Slow work-around)
void ClearScreen() {
    int n;
    for (n = 0; n < 3; n++)
        printf("\n\n\n\n\n\n\n\n\n\n");
}

// Create a function that performs the same action as system("PAUSE").
void PressEnterToContinue() {
    cout << "Press ENTER to continue" << flush;
    cin.ignore(numeric_limits <streamsize> ::max(), '\n');
}

// Create a player class with all the required attributes.
class Player {
    public:
    int wallet;
    int lives;
    string name;
};

// Create a class for the money pool.
class MoneyPot {
    public:
    int coins;
};


int main() {
    ClearScreen(); // for readability
    // Create first player object and assign the starting values.
    Player p1;
    p1.wallet = 50;
    p1.lives = 3;
    cout << "Player 1 Enter Your Name: ";
    cin >> p1.name; 

    // Create the second player object and assign the starting values.
    Player p2;
    p2.wallet = 50;
    p2.lives = 3;
    cout << "Player 2 Enter Your Name: ";
    cin >> p2.name; 

    //Create the money pool object and call the GetRandomNumber function to set a starting value.
    MoneyPot pot;
    pot.coins = GetRandomNumber();

    char p1_turn_action;
    char p2_turn_action;
    int turn = 1;

    //Displaying lives and wallet 
    while (p1.lives && p2.lives > 0) {
        ClearScreen();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << p1.name << " : " << p1.lives << " Lives, " << p1.wallet << " Coins" << endl;
        cout << p2.name << " : " << p2.lives << " Lives, " << p2.wallet << " Coins" << endl;
        cout << "The pot currently has " << pot.coins << " Coins." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        PressEnterToContinue();

        //Player 1's turn
        ClearScreen();
        if(turn == 1) {
            cout << p1.name << "'s turn" << endl;
            PressEnterToContinue();
            
            // Player 1 prompted to buy life if they have enough coins.
            if(p1.wallet > 100) {
                char p1_life_buy;
                cout << "You can afford an extra life, would you like to purchase it for 100 coins? (y/n): ";
                cin >> p1_life_buy;

                // Player 1 buys a life.
                if(p1_life_buy == 'y') {
                    p1.wallet -= 100;
                    p1.lives += 1;
                    cout << "You now have " << p1.lives << " Lives, and " << p1.wallet << " Coins.\n" << endl;
                }
            }

            // Player 1 is prompted to steal or pass the coins in the pot.

            cout << endl << "There are " << pot.coins << " coins in the pot." << endl;
            cout << "What would you like to do, steal or pass? (s/p): ";
            cin >> p1_turn_action;
            turn = 2;
            PressEnterToContinue();
        }


        //Player 2's turn
        ClearScreen();
        if(turn == 2) {
            cout << p2.name << "'s turn" << endl;
            PressEnterToContinue();
            
            // Player 2 prompted to buy life if they have enough coins.
            if(p2.wallet > 100) {
                char p2_life_buy;
                cout << "You can afford an extra life, would you like to purchase it for 100 coins? (y/n): ";
                cin >> p2_life_buy;

                // Player 2 buys a life.
                if(p2_life_buy == 'y') {
                    p2.wallet -= 100;
                    p2.lives += 1;
                    cout << "You now have " << p2.lives << " Lives, and " << p2.wallet << " Coins.\n";
                }
            }
        
            // Player 2 is prompted to steal or pass the coins in the pot.
            cout << endl << "There are " << pot.coins << " coins in the pot." << endl;
            cout << "What would you like to do, steal or pass? (s/p): ";
            cin >> p2_turn_action;
            PressEnterToContinue();
        }

        // THE OUTCOMES OF THE TURN ARE CALCULATED
        ClearScreen();
        cout << "Comparing Results" << endl;
        PressEnterToContinue();

        // Player 1 steals, Player 2 passes.
        if(p1_turn_action == 's' && p2_turn_action == 'p') {
            cout << endl << p1.name << " stole the pot!" << endl;
            PressEnterToContinue();
            p1.wallet += pot.coins;
            pot.coins = GetRandomNumber();
            turn = 1;
        }

        // Player 2 steals, Player 1 passes.
        else if(p2_turn_action == 's' && p1_turn_action == 'p') {
            cout << endl << p2.name << " stole the pot!" << endl;
            PressEnterToContinue();
            p2.wallet += pot.coins;
            pot.coins = GetRandomNumber();
            turn = 1;
        }

        // Both players steal.
        else if(p1_turn_action == 's' && p2_turn_action == 's') {
            cout << endl << "Both players tried to steal. You both lose!" << endl;
            PressEnterToContinue();
            p1.wallet -= pot.coins;
            // Remove lives if the player wallet gets below 0.
            if(p1.wallet < 0) {
                p1.wallet = 50;
                p1.lives -= 1;
            }
            p2.wallet -= pot.coins;
            if(p2.wallet < 0) {
                p2.wallet = 50;
                p2.lives -= 1;
            }
            pot.coins = GetRandomNumber();
            turn = 1;
        }

        // Both players pass.
        else if(p1_turn_action == 'p' && p2_turn_action == 'p') {
            cout << endl << "Both players passed on the coins! They will be added to the next round." << endl;
            PressEnterToContinue();
            pot.coins += GetRandomNumber();
            turn = 1;
        }

    // If player 1 loses all their lives and player 2 still has at least 1.
    if(p1.lives == 0 && p2.lives > 0) {
        cout << endl << "**** " << p1.name << "Ran out of lives. " << p2.name << " Wins! ****" << endl;
    }

    // If player 2 loses all their lives and player 1 still has at least 1.
    else if(p2.lives == 0 && p1.lives > 0) {
        cout << endl << "**** " << p2.name << "Ran out of lives. " << p1.name << " Wins! ****" << endl;
    }

    // If both players lose their lives at the same time.
    else if(p1.lives == 0 && p2.lives == 0) {
        cout << endl << "**** Both players are out of lives. Nobody Wins! ****" << endl;
    }

    }
    return 0;
}