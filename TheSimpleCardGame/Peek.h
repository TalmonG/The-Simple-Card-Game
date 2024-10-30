#pragma once
#include <iostream>
using namespace std;
#include "Card.h"
#include "Player.h"

class Peek : public Card
{
	string getName() const override
	{
		return "Peek";
	}

	void effect(Player* p) override
	{
		cout << "------------------------------------------------------------------------" << endl;

		cout << "Your top card: " << p->deck.back()->getName() << endl;
		cout << "Opponent's top card: " << p->opponent->deck.back()->getName() << endl;
		cout << "------------------------------------------------------------------------" << endl;

	}
};

