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

}

void Game::mainMenu()
{
	cout << "Press ENTER to continue: " << "\n";
	cin.get();
	system("CLS");


	if (this->characters[activeCharacter].getExp() >=
		this->characters[activeCharacter].getExpNext())

	{
		cout << "Level Up Available!!! \n\n";
	}

	cout << "= Main Menu =" << "\n" << "\n";

	cout << "= Active character :" << 
		this->characters[activeCharacter].getName() << " Nr: " 
		<< this->activeCharacter+1 << "/" << this->characters.size() 
		<< " =" << "\n" << "\n";

	cout << "0: Quit" << "\n";
	cout << "1: Travel" << "\n";
	cout << "2: Shop" << "\n";
	cout << "3: Level up" << "\n";
	cout << "4: Rest" << "\n";
	cout << "5: Character sheet" << "\n";
	cout << "6: Create new character" << "\n";
	cout << "7: Load character" << "\n";
	cout << "8: Save characters" << "\n";
	cout << "9: Load characters" << "\n";
	cout << "\n";

	cout << "\n" << "Choice: ";
	cin >> this->choice;

	while (cin.fail())
	{
		cout << "Faulty input!" << "\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << "\n" << "Choice: ";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << "\n";

	switch (this->choice)
	{
	case 0: //QUIT
		playing = false;
		break;

	case 1: //Travel

		Travel();

		break;

	case 3: //Level Up

		this->levelUpCharacter();
		break;

	case 5: //Character sheet
		//system("cls");
		characters[activeCharacter].printStats();
		break;

	case 6: //Create new character
		//system("cls");
		createNewCharacter();
		saveCharacters();
		break;

	case 7: //Select character
	//system("cls");
		selectCharacter();
		break;

	case 8: //Save characters
		//system("cls");
		saveCharacters();
		break;

	case 9: //Load characters
		//system("cls");
		loadCharacters();
		break;

	

	default:
		break;
	}
}

void Game::createNewCharacter()
{
	string name = "";
	cout << "Enter name of character: ";
	getline(cin, name);

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			cout << "Error! There is already an character with this name. " << "\n";
			cout << "Enter name of character: ";
			getline(cin, name);
		}
	}
	
	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}

void Game::levelUpCharacter()
{
	this->characters[activeCharacter].levelUp();

	if (this->characters[activeCharacter].getStatPoints() > 0)
	{
		cout << "You have have stat points to assign!" << "\n\n";

		cout << "Stat to upgrade: " << "\n";
		cout << "0: Strength" << "\n";
		cout << "1: Vitality: " << "\n";
		cout << "2: Dexterity: " << "\n";
		cout << "3: Intelligence: " << "\n";

		cin >> this->choice;

		while (cin.fail() || this->choice > 3)
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Stat to upgrade : " << "\n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0: //Strengh
			this->characters[activeCharacter].addToStat(0, 1);
			break;

		case 1: //Vitality
			this->characters[activeCharacter].addToStat(1, 1);
			break;

		case 2: //Dexterity
			this->characters[activeCharacter].addToStat(2, 1);
			break;

		case 3: //Intelligence
			this->characters[activeCharacter].addToStat(3, 1);
			break;

		default :
			break;
		}
	}
}

void Game::saveCharacters()
{
	ofstream outFile(fileName);

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
	ifstream inFile(fileName);

	this->characters.clear();

	string name = "";
	int distanceTravelled = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	int strengh = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int hp = 0;
	int stamina = 0;
	int statPoints = 0;
	int skillPoints = 0;

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strengh;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;
			str >> skillPoints;

			Character temp(name, distanceTravelled, gold, level, exp, strengh,
				vitality, dexterity, intelligence, hp, stamina, statPoints, 
				skillPoints);

			this->characters.push_back(Character(temp));

			cout << "Character " << name << " loaded!\n";

			str.clear();
		}
	}

	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw "Error no Characters loaded or empty file";
	}
}

void Game::selectCharacter()
{
	cout << "Select character: " << "\n\n";

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		cout << "Index: " << i << " = " << this->characters[i].getName() 
			<< "Level: " << this->characters[i].getLevel() <<"\n";
	}

	cout << "\n";

	cout << "Choice: ";

	cin >> this->choice;

	while (cin.fail() || this->choice >= this->characters.size() || this->choice < 0)
	{
		cout << "Wrong input!" << "\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Select character: " << "\n";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << "\n";

	this->activeCharacter = this->choice;

	cout << this->characters[this->activeCharacter].getName() << "is selected" << "\n\n";
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event event;

	event.generateEvent(this->characters[activeCharacter], this->enemies);
}