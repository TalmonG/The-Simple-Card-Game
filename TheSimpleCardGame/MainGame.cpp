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

    // 3. Assign opponents
    human.opponent = &computer;
    computer.opponent = &human;

    // 4. Create and fill decks
    vector<Card*> humanDeck = {
        new PainfulLesson(), new PainfulLesson(), new PainfulLesson(), new PainfulLesson(), new PainfulLesson(),
        new Spite(), new Spite(), new Spite(), new Spite(), new Spite(), new Spite(),
        new Peek(), new Peek(), new Peek(), new Peek(),
        new Switcheroo(), new Switcheroo(),
        new Refresh(), new Refresh(),
        new FullHeal(),
    };

    vector<Card*> computerDeck = humanDeck;  // Both players have identical decks

    // 5. Shuffle decks
    //shuffle(humanDeck.begin(), humanDeck.end(), rng);
    //shuffle(computerDeck.begin(), computerDeck.end(), rng);

    // 6. Assign decks to players
    human.deck = humanDeck;
    computer.deck = computerDeck;

    // 7. Game loop
    while (true) {
        // Human player's turn
        if (!human.isInitialSetupComplete)
        {
            cout << "Human's turn:\n";
        }
        human.myTurn();
        if (human.hasLost()) {
            cout << "Computer wins!\n";
            break;
        }

        // Computer player's turn
        if (!human.isInitialSetupComplete)
        {
            cout << "Computer's turn:\n";
        }
        computer.myTurn();
        if (computer.hasLost()) {
            cout << "Human wins!\n";
            break;
        }
    }

    // 8. Clean up dynamically allocated memory
    for (Card* card : humanDeck) delete card;
}
