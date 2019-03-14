#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "../Rendering/3D/GameObject.h"
#include "../Events/KeyEventListener.h"

class CharacterController
{
public:
	CharacterController();
	void Update(float deltaTime);
	void AttachObject(GameObject* _Obj);

protected: 

	glm::vec3 velocity;
	GameObject* Obj;
};



#endif
