#include "Rigidbody.h"


Rigidbody::Rigidbody(GameObject* _Parent)
{
	parent = _Parent;
	position = _Parent->GetPosition();
	rotation = _Parent->GetRotation();
	velocity = glm::vec3(0,0,0);
	acceleration = glm::vec3(0,0,0);
	mass = 1.5f;
	drag = 0.2f; 
	angularDrag = 0;
	Restitution = 0.5f;
	parent->AttachRigidBody(this);
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::addForce(glm::vec3 _force)
{
	force += _force;
	
}
void Rigidbody::addTorque(glm::vec3 _torque)
{
	Torque += _torque;
}

void Rigidbody::Update(float _deltaTime)
{
	acceleration = force / mass;
	position += velocity * _deltaTime + 0.5f * (acceleration * pow(_deltaTime, 2)); 
	velocity += acceleration * _deltaTime; 
	if (glm::length(velocity) != 0.0f)
	{
		velocity += glm::length(velocity) * drag * -glm::normalize(velocity) * _deltaTime;
	}

	angularAcceleration = Torque / mass;
	rotation += angularVelocity * _deltaTime + 0.5f * (angularAcceleration * pow(_deltaTime, 2));
	angularVelocity += angularAcceleration * _deltaTime;

	force = glm::vec3();
	Torque = glm::vec3();
	parent->SetPosition(position);

	//parent->SetRotation(glm::normalize(rotation));
	//parent->SetAngle(glm::length(rotation));

}