#pragma once
#include "Card.h"
#include "Player.h"
class Spite : public Card
{
	string getName() const override
	{
		return "Spite";
	}

	void effect(Player* p) override
	{
		p->loseHealth(1);
		p->opponent->loseHealth(1);
	}
};

