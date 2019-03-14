#ifndef CHARACTER_H
#define CHARACTER_H

#include "../Rendering/3D/GameObject.h"
#include "Stat.h"
#include "Modifier.h"
#include "Ability.h"
#include "Equipment.h"

class Character
{
public:
	Character();
	~Character();
	void AddStat(class Stat* stat);
	Stat* FindStat(std::string _Name);
	void AddModifier(class Modifier* _mod);
	Modifier* FindMod(std::string _Name);
	void AddAbility(class Ability* _Ability);
	Ability* FindAbility(std::string _Name);
	void AddEquipment(class Equipment* _Equipment);
	Equipment* FindEquipment(std::string _Name);
	void RemoveAllMods();
	void RemoveDeadMods();
	void RemoveAllMods(std::string _Name);
	void RemoveMod(Modifier* _Mod);
	void RemoveAbility(std::string _Name);
	void RemoveAbility(Ability* _ability);
	void RemoveAllAbilities();
	void RemoveEquipment(std::string _Name);
	void RemoveEquipment(Equipment* _Equipped);

private:
	//holds character constant statistical information
	std::vector<Stat*> Stats;
	//Holds battle relevant modifiers
	std::vector<Modifier*> Modifiers;
	//Holds abilities
	std::vector<Equipment*> Equipped;
	//Holds equipment
	std::vector<Ability*> Abilities;


};

#endif
