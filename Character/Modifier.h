#ifndef MODIFIER_H
#define MODIFIER_H

#include "Character.h"

class Modifier
{
public:
	Modifier();
	virtual ~Modifier();
	virtual void Update() = 0;
	virtual void setParent(class Character* _Parent);
	std::string getName() const;
	bool isDead;
protected:
	std::string Name;
	Character * Parent;
};


#endif