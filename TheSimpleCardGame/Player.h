#pragma once
#include <iostream>
#include <vector>

#include "Card.h"

class Card;

class Player
{

public:
	Player* opponent;
	int health = 20;
	vector<Card*> deck, hand, discard_pile;
	bool isInitialSetupComplete = false;


	void loseHealth(int i)
	{

	}

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

	void playCard(Card* c)
	{

	}

	virtual void myTurn() = 0
	{

	}

	bool hasLost()
	{
		if (hand.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};