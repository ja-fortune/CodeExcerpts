#include "CharacterController.h"


CharacterController::CharacterController()
{
}

void CharacterController::Update(float deltaTime)
{
	if (Obj == nullptr)
		return;

	velocity = glm::vec3();
	if ((*KeyEventListener::getKeyMap())[SDLK_UP] == 1)
	{
		velocity += glm::vec3(0,0,-1);
	}
	if ((*KeyEventListener::getKeyMap())[SDLK_DOWN] == 1)
	{
		velocity += glm::vec3(0, 0, 1);
	}
	if ((*KeyEventListener::getKeyMap())[SDLK_LEFT] == 1)
	{
		velocity += glm::vec3(-1, 0, 0);
	}
	if ((*KeyEventListener::getKeyMap())[SDLK_RIGHT] == 1)
	{
		velocity += glm::vec3(1, 0, 0);
	}

	Obj->Translate(velocity * deltaTime);
}

void CharacterController::AttachObject(GameObject* _Obj)
{
	Obj = _Obj;
}