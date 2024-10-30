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
            hasLost();
            return;
        }


        while (hand.size() > 5) {
            cout << "------------------------------------------------------------------------" << endl;

            cout << "HUMAN'S TURN" << endl;
                        cout << "------------------------------------------------------------------------" << endl;

            // Display the hand to the player
            cout << "Your hand:" << endl;
            for (int i = 0; i < hand.size(); i++) {
                cout << i + 1 << ". " << hand[i]->getName() << endl;
            }

            int choice;
            cout << "Choose a card to play (1-" << hand.size() << "): ";
            cin >> choice;

            if (choice > 0 && choice <= hand.size()) {
                Card* chosenCard = hand[choice - 1];
                playCard(chosenCard);
                cout << "------------------------------------------------------------------------" << endl;
                cout << "Human's Health: " << health << endl;
                cout << "Computer's Health: " << opponent->health << endl;
                cout << "------------------------------------------------------------------------" << endl;

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

            // Initial setup output
            //if (!isInitialSetupComplete) {

        }

        //isInitialSetupComplete = true;
        
    }
};

