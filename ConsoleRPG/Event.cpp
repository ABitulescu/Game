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
	
}

void Event::puzzleEncounter(Character& character)
{
	
}
