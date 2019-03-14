#include "Stat.h"

Stat::Stat()
{
	baseValue = modifiedValue = 1;
}
Stat::Stat(int _init)
{
	baseValue = modifiedValue = _init;
}
Stat::~Stat()
{
}
void Stat::setParent(Character* _Parent)
{
	Parent = _Parent;
}
std::string Stat::getName() const
{
	return Name;
}
int Stat::getBaseValue()
{
	return baseValue;
}
int Stat::getModifiedValue()
{
	return modifiedValue;
}
void Stat::setBaseValue(int _Value)
{
	baseValue = _Value;
}
void Stat::setModifiedValue(int _Value)
{
	modifiedValue = _Value;
}

void Stat::ResetModifiedValue()
{
	modifiedValue = baseValue;
}