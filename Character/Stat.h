#ifndef STAT_H
#define STAT_H

#include "Character.h"


class Stat
{
public:
	Stat();
	Stat(int _init);
	~Stat();
	void setParent(class Character* _Parent);
	void ResetModifiedValue();
	std::string getName() const;
	int getBaseValue();
	int getModifiedValue();
	void setBaseValue(int _Value);
	void setModifiedValue(int _Value);

protected:
	std::string Name;
	Character * Parent;
	int baseValue;
	int modifiedValue;
};

#endif
