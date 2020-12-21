#pragma once

#include <iostream>

enum class GenderType : char { MALE = 'M', FEMALE = 'F' };

class Animal
{
private:
	static int AnimalCount;
	int Id;
protected:
	GenderType Gender;
	std::string Name;
	int PosX;
	int PosY;

	bool Aggresive;
	bool Breed;
public:
	Animal();
	virtual ~Animal();
	Animal(const std::string& name);
	Animal(const std::string& name, int x, int y);

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

	virtual void Action(const Animal& animal) = 0;

	void Print();

	void setGender(GenderType gender);
	void setName(const std::string& name);
	void setCoords(int x, int y);
	void setBreed(bool value);

	GenderType getGender();
	const std::string& getName() const;
	const int getX() const;
	const int getY() const;
	bool getBreed();
	bool isAggresive();
	int getId() const;

};