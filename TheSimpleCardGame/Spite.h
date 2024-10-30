#pragma once
#include "Card.h"
class Spite : public Card
{
	string getName() const override
	{
		return "Spite";
	}

	void effect(Player* p) override
	{
		p->health -= 1;
		p->opponent->health -= 1;
	}
};

