#include "Prey.hpp"

int Prey::PreyCount = 0;

Prey::Prey()
    : Prey(0, 0)
{
}
Prey::Prey(int x, int y)
    : Animal("Prey", Vec2i(x,y))
{
    Aggresive = false;
    PreyCount++;
}

Prey::~Prey()
{
    std::cout << "Prey died\n";
    PreyCount--;
}

void Prey::Action(const Animal& animal)
{
    std::cout << Name << " met " << animal.getName() << " at " << getCoords()._x << ' ' << getCoords()._y << '\n';
}

int Prey::getPreysCount()
{
    return PreyCount;
}
