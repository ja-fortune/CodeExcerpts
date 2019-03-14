#include "Modifier.h"

Modifier::Modifier()
{
}
Modifier::~Modifier()
{
}

void Modifier::setParent(Character* _Parent)
{
	Parent = _Parent;
}

void Modifier::Update()
{
}

std::string Modifier::getName() const
{
	return Name;
}

