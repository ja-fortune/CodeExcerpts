#include "SphereCollider.h"

SphereCollider::SphereCollider(float radius_)
	: Collider(Collider::ColliderType::SphereCollider), radius(radius_)
{}

SphereCollider::~SphereCollider() {

}

float SphereCollider::Radius() {

	return radius;
}