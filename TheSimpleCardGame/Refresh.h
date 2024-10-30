#pragma once
#include "Card.h"
#include <vector>
#include <random>     // for default_random_engine
#include <chrono>     // for seeding random engine with time
#include "Player.h"
class Refresh : public Card
{
	string getName() const override
	{
		return "Refresh";
	}

	void effect(Player* p) override
	{

		default_random_engine rng(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));

		for (int i = 0; i < p->discard_pile.size(); i++)
		{

			p->deck.push_back(p->discard_pile[i]);

			
		}

		p->discard_pile.clear();

		shuffle(p->deck.begin(), p->deck.end(), rng);

	}
};

