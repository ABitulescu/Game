#pragma once
#include "Item.h"

class Armor:public Item
{
private:
	int type;
	int defense;


public:
	Armor(int type = 0, int defense = 0,
		std::string name = "NONE", int level = 0, int buyValue = 0,
		int sellValue = 0, int rarity = 0);

	virtual ~Armor();

	//Pure virtual
	virtual Armor* clone()const;

	//Functions
	std::string toString();
};
