#include "Collider.h"

Collider::Collider(ColliderType type_)
	: type(type_)
{}

Collider::~Collider() {

}

Collider::ColliderType Collider::Type()
{
	return type;
}