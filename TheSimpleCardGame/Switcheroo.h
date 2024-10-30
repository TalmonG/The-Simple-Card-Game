#pragma once
#include "Card.h"
#include "Player.h"
#include <algorithm>

class Switcheroo : public Card
{
	string getName() const override
	{
		return "Switcheroo";
	}

	void effect(Player* p) override
	{
		swap(p->hand, p->opponent->hand);
	}
};

