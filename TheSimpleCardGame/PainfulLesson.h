#pragma once
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

	}
};

