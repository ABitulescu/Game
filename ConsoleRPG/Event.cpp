#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character)
{
	int i = rand() % this->nrOfEvents;

	switch (i)
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character);
		break;
	case 1:
		//Puzzle
		puzzleEncounter(character);
		break;
	case 2:
		//Quiz
		break;
	default:
		break;
	}
}

//Different events
void Event::enemyEncounter(Character& character)
{
	//while()
}

void Event::puzzleEncounter(Character& character)
{
	bool completed = false;
	int userAnswer = 0;
	int chances = 3;
	int gainExp = (chances * character.getLevel() * (rand() % 10 + 1)) ;

	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 1)
	{
		std::cout << "Chances: " << chances << "\n\n";

		chances--;

		std::cout << puzzle.getAsString() << "\n";

		std::cout << "\nYour Answer: ";
		std::cin >> userAnswer;

		while (cin.fail())
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\nYour answer: ";
			cin >> userAnswer;
		}

		cin.ignore(100, '\n');
		std::cout << "\n";

		if (puzzle.getCorrectAnswer() == userAnswer)
		{
			completed = true;

			character.gainExp(gainExp);
			std::cout << "You gained " << gainExp << " Exp!" << "\n\n";
		}
	}

	if (completed)
	{
		std::cout << "Congratulations you have completed the Puzzle! \n\n";
	}
	else
	{
		std::cout << "You have failed to solve the Puzzle. \n\n";
	}
}
