#pragma once

#include "Card.h"
#include "Player.h"


class PainfulLesson : public Card
{
public:
	string getName() const override
	{
		return "Painful Lesson";
	}

	void effect(Player* p) override
	{
		cout << "------------------------------------------------------------------------" << endl;

		p->opponent->loseHealth(2);
		
		cout << "Opponent is forced to play a card\n";
		// Opponent draws card
		if (!p->opponent->drawCard())
		{
			cout << p->opponent->name << " has no cards left to draw and loses the game" << endl;
		}
		cout << "------------------------------------------------------------------------" << endl;

	}
};

