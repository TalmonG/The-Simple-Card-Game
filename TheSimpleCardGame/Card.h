#pragma once
#include <string>
using namespace std;

#include "Player.h"

class Player;

class Card
{
private:
	string cardName;
public:
	virtual string getName() const = 0
	{
		return cardName;
	}

	virtual void effect(Player* p) = 0
	{

	}
};

