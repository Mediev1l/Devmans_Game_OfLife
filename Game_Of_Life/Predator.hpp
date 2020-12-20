#pragma once

#include "Animal.hpp"

class Predator : public Animal
{
private:
	int TurnsAlive;
	static int PredatorsCount;
public:
	Predator();
	Predator(int x, int y);
	virtual ~Predator();

	virtual void Action(const Animal& animal) override;

	void Eat();
	void Hungry();

	int getTurns();

	static int getPredatorsCount();
};