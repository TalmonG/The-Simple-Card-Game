#pragma once
#include <string>
using namespace std;


class Player;

class Card
{
	string cardName;  // Protected so derived classes can set it
public:

	virtual string getName() const = 0
	{
		return cardName;
	}

	virtual void effect(Player* p) = 0
	{

	}


};

