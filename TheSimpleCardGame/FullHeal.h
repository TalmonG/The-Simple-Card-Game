#pragma once
#include "Card.h"
#include "Player.h"

class FullHeal : public Card
{
	string getName() const override
	{
		return "Full Health";
	}

	void effect(Player* p) override
	{
		p->health = 20;
	}
};

