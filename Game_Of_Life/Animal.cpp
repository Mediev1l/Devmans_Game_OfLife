#include "Animal.hpp"

int Animal::AnimalCount = 0;

Animal::Animal()
	: Animal("Unnamed Animal", Vec2i{ 0,0 })
{
}

Animal::~Animal()
{
}

Animal::Animal(const std::string& name)
	: Animal(name, Vec2i{ 0,0 })
{
}

Animal::Animal(const std::string& name, const Vec2i& coords)
	: Name(name)
	, Aggresive(false)
	, Coords(coords)
	, Id(0)
	, Breed(false)
{

	if (rand() % 2 == 0)
		Gender = GenderType::MALE;
	else
		Gender = GenderType::FEMALE;

	Id = AnimalCount;

	AnimalCount++;
}

void Animal::MoveUp()
{
	Coords._y--;
}

void Animal::MoveDown()
{
	Coords._y++;
}

void Animal::MoveLeft()
{
	Coords._x--;
}

void Animal::MoveRight()
{
	Coords._y++;
}


void Animal::Print()
{
	auto gender = Gender == GenderType::MALE ?  "Male" : "Female";
	std::cout << "| " << Name << " | " << gender << " X: " << Coords._x << " Y: " << Coords._y << " |\n";
}

void Animal::setGender(GenderType gender)
{
	Gender = gender;
}

void Animal::setName(const std::string& name)
{
	Name = name;
}

void Animal::setCoords(const Vec2i& coords)
{
	Coords = coords;
}

void Animal::setBreed(bool value)
{
	Breed = value;
}

GenderType Animal::getGender()
{
	return Gender;
}

const std::string Animal::getName() const
{
	return Name;
}

const Vec2i Animal::getCoords() const
{
	return Coords;
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
