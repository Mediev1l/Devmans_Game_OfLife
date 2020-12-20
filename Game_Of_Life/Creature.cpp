#include "Creature.hpp"

Creature::Creature()
	: Creature(Vec2i{0,0})
{
}

Creature::~Creature()
{
}

Creature::Creature(const Vec2i& coords)
	: m_Coords(coords)
	, m_fSpeed(1.f)
	, m_bAggresive(false)
{
}

Creature::Creature(Vec2i&& coords)
	: m_Coords(std::move(coords))
	, m_fSpeed(1.f)
	, m_bAggresive(false)
{
}

Creature::Creature(const Creature& cpy)
	: m_Coords(cpy.m_Coords)
	, m_fSpeed(cpy.m_fSpeed)
	, m_bAggresive(cpy.m_bAggresive)
{
}

Creature::Creature(Creature&& move) noexcept
{
	this->m_Coords = std::move(move.m_Coords);
	this->m_fSpeed = move.m_fSpeed;
	this->m_bAggresive = move.m_bAggresive;

	move.m_fSpeed = 0;	 
	move.m_bAggresive = 0;
}


void Creature::setCoords(int x, int y)
{
	this->m_Coords._x = x;
	this->m_Coords._y = y;
}

void Creature::setCoords(const Vec2i& coords)
{
	this->m_Coords = coords;
}

void Creature::setSpeed(float speed)
{
	this->m_fSpeed = speed;
}

void Creature::setAggresion(bool isAggresive)
{
	this->m_bAggresive = isAggresive;
}

int Creature::getX()
{
	return m_Coords._x;
}

int Creature::getY()
{
	return m_Coords._y;
}

Vec2i Creature::getCoords()
{
	return m_Coords;
}

float Creature::getSpeed()
{
	return m_fSpeed;
}

bool Creature::isAggresive()
{
	return m_bAggresive;
}
