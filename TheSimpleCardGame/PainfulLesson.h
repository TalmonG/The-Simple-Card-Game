#pragma once

#include "Player.h"
#include "Card.h"


class PainfulLesson : public Card
{
public:
	string getName() const override
	{
		return "Painful Lesson";
	}

	void effect(Player* p) override
	{
		p->opponent->health -= 2;
		
		// Opponent draws card
		if (!p->opponent->drawCard())
		{
			cout << p->opponent->name << " has no cards left to draw and loses the game" << endl;
		}
	}
};

