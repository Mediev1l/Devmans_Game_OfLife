#include "Predator.hpp"

int Predator::PredatorsCount = 0;

Predator::Predator()
	: Predator(0,0)
{
}

Predator::Predator(int x, int y)
	: TurnsAlive(0)
	, Animal("Predator", x, y)
{
	Aggresive = true;
	PredatorsCount++;
}

Predator::~Predator()
{
	std::cout << "Predator died\n";
	PredatorsCount--;
}

void Predator::Action(const Animal& animal)
{
	std::cout << Name << " fighting with " << animal.getName() << " at " << getX() << ' ' << getY() << '\n';
}

void Predator::Eat()
{
	TurnsAlive = 0;
	std::cout << "om om";
}

void Predator::Hungry()
{
	TurnsAlive++;
}

int Predator::getTurns()
{
	return TurnsAlive;
}

int Predator::getPredatorsCount()
{
	return PredatorsCount;
}
