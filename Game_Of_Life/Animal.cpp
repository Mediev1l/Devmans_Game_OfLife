#include "Animal.hpp"

int Animal::AnimalCount = 0;

Animal::Animal()
	: Animal("Unnamed Animal", 0, 0)
{
}

Animal::~Animal()
{
}

Animal::Animal(const std::string& name)
	: Animal(name, 0, 0)
{
}

Animal::Animal(const std::string& name, int x, int y)
	: Name(name)
	, Aggresive(false)
	, PosX(x)
	, PosY(y)
	, Id(0)
	, Breed(false)
{

	if (rand() % 2 == 0)
	{
		Gender = GenderType::MALE;
	}
	else
	{
		Gender = GenderType::FEMALE;
	}

	Id = AnimalCount;

	AnimalCount++;
}

void Animal::MoveUp()
{
	PosY--;
}

void Animal::MoveDown()
{
	PosY++;
}

void Animal::MoveLeft()
{
	PosX--;
}

void Animal::MoveRight()
{
	PosX++;
}


void Animal::Print()
{
	auto gender = Gender == GenderType::MALE ?  "Male" : "Female";
	std::cout << "| " << Name << " | " << gender << " X: " << getX() << " Y: " << getY() << " |\n";
}

void Animal::setGender(GenderType gender)
{
	Gender = gender;
}

void Animal::setName(const std::string& name)
{
	Name = name;
}

void Animal::setCoords(int x, int y)
{
	PosX = x;
	PosY = y;
}

void Animal::setBreed(bool value)
{
	Breed = value;
}

GenderType Animal::getGender()
{
	return Gender;
}

const std::string& Animal::getName() const
{
	return Name;
}

const int Animal::getX() const
{
	return PosX;
}

const int Animal::getY() const
{
	return PosY;
}

bool Animal::getBreed()
{
	return Breed;
}

bool Animal::isAggresive()
{
	return Aggresive;
}

int Animal::getId() const
{
	return Id;
}
