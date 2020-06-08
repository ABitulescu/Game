#include "Character.h"

Character::Character()
{
	this->distanceTravelled = 0;

	this->gold = 0;

	this->name = "";
	this->level = 1;
	this->exp = 0;
	this->expNext = 0;

	this->strengh = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::Character(string name, int distanceTravelled, int gold, 
	int level, int exp, int strengh, int vitality, int dexterity, int intelligence,
	int hp, int stamina, int statPoints, int skillPoints)
{
	this->distanceTravelled = distanceTravelled;

	this->gold = gold;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strengh = strengh;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;

	this->statPoints = statPoints;
	this->skillPoints = skillPoints;

	this->updateStats();
}

Character::~Character()
{

}

//Functions
void Character::initialize(const string name)
{
	this->distanceTravelled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>
		((50 / 3) * ((pow(level, 3) -
			6 * pow(level, 2)) +
			17 * level - 12)) + 100;

	this->strengh = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	
	this->hpMax = (this->vitality * 2) + (this->strengh/2);
	this->hp = hpMax;
	this->staminaMax = this->vitality + (this->strengh/2) + (this->dexterity/3);
	this->stamina = this->staminaMax;
	this->damageMin = this->strengh;
	this->damageMax = this->strengh + 2;
	this->defence = this->dexterity + (this->intelligence/2);
	this->accuracy = this->dexterity / 2;
	this->luck = this->intelligence;

	this->statPoints = 0;
	this->skillPoints = 0;


}

    void Character::printStats() const
{
	cout << "= Character Sheet =" << endl;
	cout << "= Name: " << this->name << endl;
	cout << "= Level: " << this->level << endl;
	cout << "= Exp: " << this->exp << endl;
	cout << "= Exp to Next Level: " << this->expNext << endl;
	cout << endl;
	cout << "= Strengh: " << this->strengh << endl;
	cout << "= Vitality: " << this->vitality << endl;
	cout << "= Dexterity: " << this->dexterity << endl;
	cout << "= Intelligence: " << this->intelligence << endl;
	cout << endl;
	cout << "= Hp: " << this->hp << " / " << this->hpMax << endl;
	cout << "= Stamina: " << this->stamina <<" / " << this->staminaMax << endl;
	cout << "= Damage: " << this->damageMin << " - " <<this->damageMax << endl;
	cout << "= Defence: " << this->defence << endl;
	cout << "= Accuracy: " << this->accuracy << endl;
	cout << "= Luck: " << this->luck << endl;
	cout << endl;

}

void Character::updateStats()
{
	this->expNext = static_cast<int>
		((50 / 3) * ((pow(level, 3) -
			6 * pow(level, 2)) +
			17 * level - 12)) + 100;

	this->hpMax = (this->vitality * 2) + (this->strengh / 2);
	this->staminaMax = this->vitality + (this->strengh / 2) + (this->dexterity / 3);
	this->damageMin = this->strengh;
	this->damageMax = this->strengh + 2;
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = this->dexterity / 2;
	this->luck = this->intelligence;
}

void Character::addToStat(int stat, int value)
{
	if (this->statPoints < value)
	{
		cout << "You don't have any stat points to assign!" << "\n";
	}
	else
	{
		switch (stat)
		{
		case 0:
			this->strengh += value;
			cout << "Added 1 point to strengh" << "\n";
			break;

		case 1:
			this->vitality += value;
			cout << "Added 1 point to vitality" << "\n";
			break;

		case 2:
			this->dexterity += value;
			cout << "Added 1 point to dexterity" << "\n";
			break;

		case 3:
			this->intelligence += value;
			cout << "Added 1 point to intelligence" << "\n";
			break;

		default:
			cout << "Your choice is not a Stat option" << "\n";
			break;
		}

		this->statPoints -= value;
	}
}

void Character::levelUp()
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>
			((50 / 3) * ((pow(level, 3) -
				6 * pow(level, 2)) +
				17 * level - 12)) + 100;

		this->statPoints++;
		this->skillPoints++;

		this->updateStats();

		cout << "You are now Level " << this->level << "!" << "\n\n";
	}
	else
	{
		cout << "You need more EXP! \n\n";
	}
}

string Character::getAsString() const //for saving the character
{
	return name + " "
		+ to_string(distanceTravelled) + " "
		+ to_string(gold) + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(strengh) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(hp) + " "
		+ to_string(stamina) + " "
		+ to_string(statPoints) + " "
		+ to_string(skillPoints) + " ";
}

void Character::takeDamage(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;


	}
}
