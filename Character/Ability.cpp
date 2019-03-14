#include "Ability.h"

Ability::Ability()
{}
Ability::~Ability()
{}
void Ability::OnActivate()
{}
void Ability::setParent(class Character* _Parent)
{
	Parent = _Parent;
}
std::string Ability::getName() const
{
	return Name;
}