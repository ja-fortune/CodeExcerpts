#include "Equipment.h"

Equipment::Equipment()
{}
Equipment::~Equipment()
{}
void Equipment::setParent(class Character* _Parent)
{
	Parent = _Parent;
}
std::string Equipment::getName() const
{
	return Name;
}
int Equipment::getValue()
{
	return Value;
}
void Equipment::setValue(int _Value)
{
	Value = _Value;
}

void Equipment::Equip()
{}
void Equipment::Unequip()
{}