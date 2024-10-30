#pragma once
#include "Card.h"
class Refresh : public Card
{
	string getName() const override
	{
		return "Refresh";
	}

	void effect(Player* p) override
	{

	}
};

