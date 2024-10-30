#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;



class Player
{

public:
	Player* opponent;
	string name = "default";
	int health = 20;
	vector<Card*> deck, hand, discard_pile;
	//bool isInitialSetupComplete = false;


	void loseHealth(int i) { health -= i; }

	bool drawCard()
	{
		if (deck.empty()) {
			return false;
		}

		Card* drawnCard = deck.back();
		hand.push_back(drawnCard); // Add the card to the hand
		deck.pop_back();            // Remove it from the deck
		return true;
	}

	virtual void playCard(Card* c)
	{
		// Apply the card's effect
		c->effect(this);

		// Move the card to the discard pile
		discard_pile.push_back(c);

		// Remove the card from hand
		auto it = std::find(hand.begin(), hand.end(), c);
		if (it != hand.end()) {
			hand.erase(it); // Remove card from hand
		}


	}

	virtual void myTurn() = 0
	{

	}

	bool hasLost()
	{
		if (health <= 0 || deck.empty() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};