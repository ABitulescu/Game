#pragma once

#include "Inventory.h"
#include "Enemy.h"

using namespace std;

class Character
{
public: 
	Character();
	Character(string name, int distanceTravelled, int gold,
		int level, int exp, int strengh, int vitality, int dexterity, int intelligence,
		int hp, int stamina, int statPoints, int skillPoints);
	virtual ~Character();

	//Functions
	void initialize(const string name);
	void printStats() const;
	string getAsString()const;
	void levelUp();
	void updateStats();
	void addToStat(int stat, int value);

	//Accessors
	inline const int& getDistTravel() const { return this->distanceTravelled; }
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getStatPoints() const { return this->statPoints; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getHPMax() const { return this->hpMax; }
	bool isAlive() { return this->hp > 0; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDamage()const { return rand() % this->damageMax - this->damageMin;  }
	inline const int& getAccuracy() const { return this->accuracy; }
	inline const int& getDefence() const { return this->defence; }


	//Modifier
	inline void setDistTravelled(const int& distance) { this->distanceTravelled = distance ; }
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int& exp) { this->exp += exp; }
	void takeDamage(const int damage);

private:

	int distanceTravelled;

	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
	int gold;

	string name;
	int level;
	int exp;
	int expNext;

	int strengh;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;

};

