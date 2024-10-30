#pragma once
#include "Card.h"

class Peek : public Card
{
	string getName() const override
	{
		return "Peek";
	}

	void effect(Player* p) override
	{

	}
};

