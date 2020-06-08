#pragma once
#include "Character.h"
#include "Puzzle.h"
#include <stdlib.h>
#include "dArray.h"

class Event
{
private:
	int nrOfEvents;

public:
	Event();
	virtual ~Event();

	void generateEvent(Character& character, dArray<Enemy>& enemies);

	//Events
	void enemyEncounter(Character& character, dArray<Enemy>& enemies);
	void puzzleEncounter(Character& character);
};

