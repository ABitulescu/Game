#pragma once

#include "Functions.h"
#include "Event.h"
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

class Game
{
private:
	int choice;
	bool playing;

	//Character related
	int activeCharacter;
	vector<Character> characters;
	string fileName;

	//Enemies
	dArray<Enemy> enemies;

public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void levelUpCharacter();
	void saveCharacters();
	void loadCharacters();
	void selectCharacter();
	void Travel();

	//Accesors
	inline bool getPlaying() const { return this->playing; }

	//Modifiers

};

