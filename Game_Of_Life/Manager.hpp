#pragma once

#include <vector>

class Animal;

class Manager
{
private:
	std::vector<Animal*> Animals;
	int Width;
	int Height;
	int Turns;
private:

	void AddAnimal(Animal* animal);
	void RemoveAnimal(Animal* animal);
	void ShowAnimals();

	void PredatorEats(int id);
	void PredatorHunger();

	void CreatePredator();
	void CreatePrey();

	void MakeMoves();
	void CheckSimulation();
public:

	Manager();
	Manager(int width, int height, int turns);
	Manager(const Manager& cpy) = delete;
	Manager(const Manager&& move) = delete;

	void Run();
};