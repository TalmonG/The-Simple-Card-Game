#pragma once
#include "Card.h"

class FullHeal : public Card
{
	string getName() const override
	{
		return "Full Health";
	}

	void effect(Player* p) override
	{

	}
};

