#pragma once
#include "Player.h"

class ComputerPlayer : public Player
{
public:
	void myTurn() override
	{

        if (!drawCard()) {
            cout << "Computer player cannot draw a card. Deck is empty!\n";
            return;
        }

        // Display card selection and play cards automatically until hand size is <= 5
        while (hand.size() > 5) {
            int randomIndex = rand() % hand.size(); // Select a random card index
            Card* chosenCard = hand[randomIndex];
            cout << "Computer plays: " << chosenCard->getName() << endl;

            playCard(chosenCard);

            // Check if the game is over
            if (hasLost()) {
                cout << "Computer player has lost the game!\n";
                return;
            }
            if (opponent->hasLost()) {
                cout << "Computer player wins! Opponent has lost.\n";
                return;
            }
        }

        //cout << "Computer's turn has ended with hand size: " << hand.size() << endl;

    }

};

