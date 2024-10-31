#include <iostream>
#include <vector>
#include <algorithm>  // for shuffle
#include <random>     // for default_random_engine
#include <chrono>     // for seeding random engine with time

#include "HumanPlayer.h"
#include "ComputerPlayer.h"

// Cards classes
#include "PainfulLesson.h"
#include "Spite.h"
#include "Peek.h"
#include "Switcheroo.h"
#include "Refresh.h"
#include "FullHeal.h"

using namespace std;

// Assuming other necessary includes, class definitions, and function declarations

int main() {
    // 1. Set up random engine for shuffling
    default_random_engine rng(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));

    // 2. Create players
    HumanPlayer human;
    ComputerPlayer computer;

    bool humansTurn = true;
    bool computersTurn = false;

    // 3. Assign opponents
    human.opponent = &computer;
    computer.opponent = &human;
    human.opponent->name = "Computer";
    computer.opponent->name = "Human";

    vector<Card*> humanDeck = {};

    for (int i = 0; i < 5; i++)
    {
        humanDeck.push_back(new PainfulLesson());
    }
    for (int i = 0; i < 6; i++)
    {
        humanDeck.push_back(new Spite()); // FINISHED
    }
    for (int i = 0; i < 4; i++)
    {
        humanDeck.push_back(new Peek());
    }
    for (int i = 0; i < 2; i++)
    {
        humanDeck.push_back(new Switcheroo());
    }
    for (int i = 0; i < 2; i++)
    {
        humanDeck.push_back(new Refresh()); // FINISHED
    }
    for (int i = 0; i < 1; i++)
    {
        humanDeck.push_back(new FullHeal()); // FINISHED
    }
    
    //// 4. Create and fill decks
    //vector<Card*> humanDeck = {
    //    new PainfulLesson(), new PainfulLesson(), new PainfulLesson(), new PainfulLesson(), new PainfulLesson(),
    //    new Spite(), new Spite(), new Spite(), new Spite(), new Spite(), new Spite(),
    //    new Peek(), new Peek(), new Peek(), new Peek(),
    //    new Switcheroo(), new Switcheroo(),
    //    new Refresh(), new Refresh(),
    //    new FullHeal(),
    //};

    vector<Card*> computerDeck = humanDeck;  // Both players have identical decks
    

    // 5. Shuffle decks
    shuffle(humanDeck.begin(), humanDeck.end(), rng);
    shuffle(computerDeck.begin(), computerDeck.end(), rng);

    // 6. Assign decks to players
    human.deck = humanDeck;
    computer.deck = computerDeck;

    // 7. Game loop
    bool isInitialSetupComplete = false;
    while (!human.hasLost() && !computer.hasLost()) {
        // Initial setup output
        if (!isInitialSetupComplete) {
            cout << "Starting game:\n";
            cout << "Human's Health: " << human.health << endl;
            cout << "Computer's Health: " << computer.health << endl;
            isInitialSetupComplete = true;
        }

        if (humansTurn == true)
        {
            human.myTurn();        // Human player's turn
            humansTurn = false;
            computersTurn = true;
        }


        if (human.hasLost()) {
            cout << "Computer wins!\n";
            break;
        }

        if (computersTurn == true)
        {
            computer.myTurn();        // Computer player's turn
            humansTurn = true;
            computersTurn = false;
        }


        if (computer.hasLost()) {
            cout << "Human wins!\n";
            break;
        }
    }

    // 8. Clean up dynamically allocated memory
    for (Card* card : humanDeck) delete card;
    for (Card* card : computerDeck) delete card;
}
