#ifndef COLLIDER_H
#define COLLIDER_H
#include "../Rendering/3D/GameObject.h"

class Collider 
{
public:

	struct CollisionInfo
	{
		glm::vec3 CollisionAxis;
		float overlap;
	};

	enum ColliderType {

		SphereCollider,
		BoxCollider,
	};

	Collider(ColliderType type_);
	~Collider();
	ColliderType Type();

private: 

	ColliderType type;
};


#endif 