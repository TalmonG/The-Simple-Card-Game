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

		cout << p->name << "'s top card: " << p->deck.back()->getName() << endl;
		cout << p->opponent->name << "'s top card: " << p->opponent->deck.back()->getName() << endl;
		cout << "------------------------------------------------------------------------" << endl;

	}
};

