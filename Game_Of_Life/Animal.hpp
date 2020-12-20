#pragma once

#include "Vec2.hpp"
#include <iostream>
#include <random>

enum class GenderType { MALE = 0, FEMALE = 1 };

class Animal : public Vec2i
{
private:
	static int AnimalCount;
	int Id;
protected:
	GenderType Gender;
	std::string Name;
	Vec2i Coords;

	bool Aggresive;
	bool Breed;
public:
	Animal();
	virtual ~Animal();
	Animal(const std::string& name);
	Animal(const std::string& name, const Vec2i& coords);

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

	virtual void Action(const Animal& animal) = 0;

	void Print();

	void setGender(GenderType gender);
	void setName(const std::string& name);
	void setCoords(const Vec2i& coords);
	void setBreed(bool value);

	GenderType getGender();
	const std::string getName() const;
	const Vec2i getCoords() const;
	bool getBreed();
	bool isAggresive();
	int getId() const;

};