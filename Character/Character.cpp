#include "Character.h"

Character::Character()
{
	std::cout << "Character created" << std::endl;
}

Character::~Character()
{
}

void Character::AddStat(Stat* _Stat)
{
	Stats.push_back(_Stat);
	_Stat->setParent(this);
	std::cout << "Added stat" << std::endl;
}

void Character::AddModifier(Modifier* _mod)
{
	Modifiers.push_back(_mod);
	_mod->setParent(this);
	std::cout << "Added Modifier" << std::endl;
}
void  Character::AddEquipment(class Equipment* _Equipment)
{
	Equipped.push_back(_Equipment);
	_Equipment->setParent(this);
	std::cout << "Added Equipment" << std::endl;
}
void  Character::AddAbility(class Ability* _Ability)
{
	Abilities.push_back(_Ability);
	_Ability->setParent(this);
	std::cout << "Added Ability" << std::endl;
}

Stat* Character::FindStat(std::string _Name)
{
	for (auto stat : Stats)
	{
		if (stat->getName() == _Name)
		{
			std::cout << _Name << ": " << stat->getModifiedValue() << std::endl;
			return stat;
		}
	}
	return nullptr;
}

Modifier* Character::FindMod(std::string _Name)
{
	for (auto mod : Modifiers)
	{
		if (mod->getName() == _Name)
		{
			return mod;
		}
	}
	return nullptr;
}


Ability*  Character::FindAbility(std::string _Name)
{
	for (auto ability : Abilities)
	{
		if (ability->getName() == _Name)
		{
			return ability;
		}
	}
	return nullptr;
}

Equipment*  Character::FindEquipment(std::string _Name)
{
	for (auto equip : Equipped)
	{
		if (equip->getName() == _Name)
		{
			return equip;
		}
	}
	return nullptr;
}

void Character::RemoveAllMods()
{
	for (auto mod : Modifiers)
	{
		mod->~Modifier();
		Modifiers.erase(Modifiers.begin());
	}
}
void Character::RemoveDeadMods()
{
	for (auto mod : Modifiers)
	{
		if (mod->isDead)
		{
			mod->~Modifier();
			Modifiers.erase(Modifiers.begin());
		}
	}
}
void Character::RemoveAllMods(std::string _Name)
{
	int iter = 0;
	for (auto mod : Modifiers)
	{
		if (mod->getName() == _Name)
		{
			mod->~Modifier();
			Modifiers.erase(Modifiers.begin() + iter);
		}
		iter++;
	}
}
void Character::RemoveMod(Modifier* _Mod)
{
	_Mod->~Modifier();
	Modifiers.erase(std::find(Modifiers.begin(), Modifiers.end(), _Mod));
}

void Character::RemoveAbility(std::string _Name)
{
	int iter = 0;
	for (auto ability : Abilities)
	{
		if (ability->getName() == _Name)
		{
			ability->~Ability();
			Abilities.erase(Abilities.begin() + iter);
		}
		iter++;
	}
}
void Character::RemoveAbility(Ability* _ability)
{
	_ability->~Ability();
	Abilities.erase(std::find(Abilities.begin(), Abilities.end(), _ability));
}
void Character::RemoveAllAbilities()
{
	for (auto ability : Abilities)
	{
		ability->~Ability();
		Abilities.erase(Abilities.begin());
	}
}
void Character::RemoveEquipment(std::string _Name)
{
	int iter = 0;
	for (auto equip : Equipped)
	{
		if (equip->getName() == _Name)
		{
			equip->~Equipment();
			Equipped.erase(Equipped.begin() + iter);
		}
		iter++;
	}
}
void Character::RemoveEquipment(Equipment* _Equipped)
{
	_Equipped->~Equipment();
	Equipped.erase(std::find(Equipped.begin(), Equipped.end(), _Equipped));
}