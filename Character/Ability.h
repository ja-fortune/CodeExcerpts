#ifndef ABILITY_H
#define ABILITY_H

#include "Character.h"

class Ability
{

public:
	Ability();
	virtual ~Ability();
	virtual void OnActivate() = 0;
	virtual void setParent(class Character* _Parent);
	std::string getName() const;
protected:
	std::string Name;
	std::string Description;
	Character * Parent;

};


#endif
