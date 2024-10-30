#pragma once
#include "Card.h"

class Switcheroo : public Card
{
	string getName() const override
	{
		return "Switcheroo";
	}

	void effect(Player* p) override
	{

	}
};

