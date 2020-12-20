#include "Manager.hpp"

Manager::Manager()
	: Manager(10, 10, 50)
{
}

Manager::Manager(int width, int height, int turns)
	: Width(width)
	, Height(height)
	, Turns(turns)
	, Animals{}
{
	srand(time(NULL));
}

void Manager::Run()
{
	int currentTurn{};

	for (size_t i = 0; i < 10; i++)
	{
		CreatePredator();
		CreatePredator();
		CreatePrey();
	};

	while (Prey::getPreysCount() > 0 && Predator::getPredatorsCount() > 0 && currentTurn < Turns)
	{
		std::cout << "| Turn: " << currentTurn << " |\n";
		ShowAnimals();

		PredatorHunger();

		CheckSimulation();

		MakeMoves();

		currentTurn++;
	}

}

void Manager::AddAnimal(Animal* animal)
{
	Animals.push_back(animal);
}

void Manager::RemoveAnimal(Animal* animal)
{
	auto position = std::find(Animals.begin(), Animals.end(), animal);

	if (position != Animals.end())
	{
		delete* position;
		Animals.erase(position);
	}
}

void Manager::ShowAnimals()
{
	for (auto& animal : Animals)
		animal->Print();
}

void Manager::PredatorEats(int id)
{
	auto position = std::find_if(Animals.begin(), Animals.end(), [=]( Animal* a) { return a->getId() == id; });
	if (position != Animals.end())
	{
		dynamic_cast<Predator*>(*position)->Eat();
	}
}

void Manager::PredatorHunger()
{

	auto starved = [&](Animal* animal) -> bool
	{
		auto temp = dynamic_cast<Predator*>(animal);

		if (temp)
		{
			return temp->getTurns() > 2;
		}

		return false;
	};

	for (auto& predator : Animals)
	{
		auto temp = dynamic_cast<Predator*>(predator);
		if (temp)
			temp->Hungry();
	}

	for (int i = 0; i < Animals.size();)
	{
		auto temp = dynamic_cast<Predator*>(Animals[i]);

		if (temp)
		{
			if (temp->getTurns() > 2)
			{
				delete Animals[i];
				Animals.erase(Animals.begin() + i);
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
}

void Manager::CreatePredator()
{
	int tempX{};
	int tempY{};

	tempX = rand() % Width;
	tempY = rand() % Height;

	AddAnimal(new Predator(tempX, tempY));

	std::cout << "New predator at " << tempX << ' ' << tempY << '\n';

}

void Manager::CreatePrey()
{
	int tempX{};
	int tempY{};

	tempX = rand() % Width;
	tempY = rand() % Height;

	AddAnimal(new Prey(tempX, tempY));
	std::cout << "New prey at " << tempX << ' ' << tempY << '\n';

}

void Manager::MakeMoves()
{
	int direction = 0;

	for (auto& animal : Animals)
	{
		direction = rand() % 4;

		switch (direction)
		{
		case 0:
			if (animal->getCoords()._y > 0)
				animal->MoveUp();
			break;
		case 1:
			if (animal->getCoords()._y < Height - 1)
				animal->MoveDown();
			break;
		case 2:
			if (animal->getCoords()._x > 0)
				animal->MoveLeft();
			break;
		case 3:
			if (animal->getCoords()._x < Width - 1)
				animal->MoveRight();
			break;
		default:
			break;
		}
	}
}

void Manager::CheckSimulation()
{
	auto AnimalCopy = Animals;

	for (size_t i = 0; i < AnimalCopy.size(); i++)
	{
		for (size_t j = 0; j < AnimalCopy.size(); j++)
		{
			auto tempA1 = AnimalCopy[i];
			auto tempA2 = AnimalCopy[j];

			if (i != j && tempA1->getCoords()._x == tempA2->getCoords()._x
				&& tempA1->getCoords()._y == tempA2->getCoords()._y)
			{

				//Two predators met Male & Female
				if (tempA1->isAggresive() && tempA2->isAggresive()
					&& tempA1->getGender() != tempA2->getGender())
				{
					//check if they didnt breed this turn
					if (!tempA1->getBreed() && !tempA2->getBreed())
					{
						tempA1->setBreed(true);
						tempA2->setBreed(true);
						CreatePredator();
					}
				}

				//predator met prey
				else if (tempA1->isAggresive() && !tempA2->isAggresive())
				{
					tempA1->Action(*tempA2);
					RemoveAnimal(Animals[j]);
				}

				//prey met predator
				else if (!tempA1->isAggresive() && tempA2->isAggresive())
				{
					tempA2->Action(*tempA1);
					//Hide?
				}

				//prey met prey
				else if (!tempA1->isAggresive() && !tempA2->isAggresive())
				{
					//check if they didnt breed this turn
					if (!tempA1->getBreed() && !tempA2->getBreed())
					{
						tempA1->setBreed(true);
						tempA2->setBreed(true);
						CreatePrey();
					}
				}
				
			}
		}
	}
}
