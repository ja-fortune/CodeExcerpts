#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Character.h"
class Stat;

class Equipment
{
public:
	Equipment();
	~Equipment();
	void setParent(class Character* _Parent);
	std::string getName() const;
	int getValue();
	void setValue(int _Value);
	virtual void Equip();
	virtual void Unequip();
protected:
	std::string Name;
	Character * Parent;
	int Value;
	Stat* target;
};


#endif
