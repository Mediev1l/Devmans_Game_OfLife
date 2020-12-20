#pragma once

#include "Animal.hpp"

class Prey : public Animal
{
private:
	static int PreyCount;
public:
	Prey();
	Prey(int x, int y);
	~Prey();

	virtual void Action(const Animal& animal) override;

	static int getPreysCount();
};