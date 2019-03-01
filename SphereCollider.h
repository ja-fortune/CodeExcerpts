#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include "Collider.h"

class SphereCollider : public Collider {

private:

	float radius;

public:

	SphereCollider(float radius_);
	~SphereCollider();

	float Radius();
};

#endif