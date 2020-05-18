#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "characters.txt";

}

Game::~Game()
{

}

//Functions
void Game::initGame()
{
	createNewCharacter();
	Puzzle p("lel.txt");
	std::cout << p.getAsString() << "\n";
}

void Game::mainMenu()
{
	std::cout << "= Main Menu =" << std::endl << std::endl;

	std::cout << "0: Quit" << std::endl;
	std::cout << "1: Travel" << std::endl;
	std::cout << "2: Shop" << std::endl;
	std::cout << "3: Level up" << std::endl;
	std::cout << "4: Rest" << std::endl;
	std::cout << "5: character sheet" << std::endl;
	std::cout << "6: Create new character" << std::endl;
	std::cout << "7: Save characters" << std::endl;
	std::cout << "8: Load characters" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Choice: ";
	std::cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
	case 0:
		playing = false;
		break;

	case 5:
		//system("cls");
		characters[activeCharacter].printStats();
		break;

	case 6:
		//system("cls");
		std::cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;

	case 7:
		//system("cls");
		saveCharacters();
		break;

	case 8:
		//system("cls");
		loadCharacters();
		break;

	default:
		break;
	}
}


void Game::createNewCharacter()
{
	std::string name = "";
	std::cout << "Enter name of character: ";
	std::getline(std::cin, name);
	
	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}
void Game::saveCharacters()
{
	std::ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}

	outFile.close();
}
void Game::loadCharacters()
{

}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event event;

	event.generateEvent(this->characters[activeCharacter]);
}