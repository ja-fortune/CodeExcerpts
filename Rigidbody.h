#ifndef  RIGIDBODY_H
#define RIGIDBODY_H

#include "../Rendering/3D/GameObject.h"

class  Rigidbody
{
public:
	 Rigidbody(class GameObject* _Parent);
	~ Rigidbody();
	void addForce(glm::vec3 _force);
	void addTorque(glm::vec3 _torque);
	void Update(float _deltaTime);

	GameObject * parent;
	float mass;
	float drag;
	float angularDrag;
	float Restitution;
	bool useGravity;

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 velocity;
	glm::vec3 angularVelocity;
	glm::vec3 acceleration;
	glm::vec3 angularAcceleration;
	glm::vec3 force;
	glm::vec3 Torque;

};



#endif // ! RIGIDBODY_H

