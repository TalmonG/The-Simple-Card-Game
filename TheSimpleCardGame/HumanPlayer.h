#pragma once
#include <iostream>

#include "Player.h"



class HumanPlayer : public Player
{
public:
	void myTurn() override
	{
        // Draw a card at the start of the turn
        if (!drawCard()) {
            cout << "Human player cannot draw a card. Deck is empty!\n";
            return;
        }

        //cout << "Human player's turn begins.\n";

        while (hand.size() > 5) {
            // Display the hand to the player
            cout << "Your hand:" << endl;
            for (int i = 0; i < hand.size(); i++) {
                cout << i + 1 << ". " << hand[i]->getName() << endl;
            }

            int choice;
            cout << "Choose a card to play (1-" << hand.size() << ") or 0 to end turn: ";
            cin >> choice;

            if (choice == 0 && hand.size() <= 5) {
                cout << "Ending turn.\n";
                break;
            }

            if (choice > 0 && choice <= hand.size()) {
                Card* chosenCard = hand[choice - 1];
                playCard(chosenCard);

                // Check if either player has lost
                if (hasLost()) {
                    cout << "Human player has lost the game!\n";
                    return;
                }
                if (opponent->hasLost()) {
                    cout << "Human player wins! Opponent has lost.\n";
                    return;
                }
            }
            else {
                cout << "Invalid choice! Try again.\n";
            }
        }

        isInitialSetupComplete = true;
        
        //cout << "Computer player's turn has ended with hand size: " << hand.size() << endl;
    }
};

