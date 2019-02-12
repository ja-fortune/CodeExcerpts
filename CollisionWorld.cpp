#include "CollisionWorld.h"

std::unique_ptr<CollisionWorld> CollisionWorld::collisionWorldInstance = nullptr;
std::vector<GameObject*> CollisionWorld::objects = std::vector<GameObject*>();

CollisionWorld::CollisionWorld()
{}
CollisionWorld::~CollisionWorld()
{}

CollisionWorld* CollisionWorld::GetInstance()
{
	if (collisionWorldInstance.get() == nullptr)
	{
		collisionWorldInstance.reset(new CollisionWorld());
	}

	return collisionWorldInstance.get();
}

void CollisionWorld::AddObject(GameObject* go_)
{
	objects.push_back(go_);
}

void CollisionWorld::Update()
{
	for (int iter = 0; iter < objects.size() - 1; iter++)
	{
		for (int next = 1; next < objects.size(); next++)
		{
			BoundingBox::CollisionInfo colInfo;
			if (objects[iter]->GetBoundingBox().Intersects(&objects[next]->GetBoundingBox(), &colInfo))
			{
				float dotProduct = glm::dot(objects[iter]->GetPosition() - objects[next]->GetPosition(), colInfo.CollisionAxis);
				if (dotProduct < 0)
					colInfo.CollisionAxis *= -1;

				objects[iter]->Translate(colInfo.overlap * colInfo.CollisionAxis);
				objects[iter]->GetRigidBody()->position += (colInfo.overlap * colInfo.CollisionAxis);
				
				if (objects[iter]->GetRigidBody() != nullptr)
				{
					if (objects[next]->GetRigidBody() != nullptr)
					{
						CollisionRigidRigid(objects[iter], objects[next]);
					}
					else
					{
					}
				}
				else
				{
				}
			}
		}
	}
}

void CollisionWorld::CollisionObjObj(GameObject* first, GameObject* second)
{
}
void CollisionWorld::CollisionObjRigid(GameObject* first, GameObject* second)
{
}
void CollisionWorld::CollisionRigidObj(GameObject* first, GameObject* second)
{}
void CollisionWorld::CollisionRigidRigid(GameObject* first, GameObject* second)
{

	Rigidbody* r1 = first->GetRigidBody();
	Rigidbody* r2 = second->GetRigidBody();
	float CoR = 0.5f * (r1->Restitution + r2->Restitution);
	glm::vec3 Vn = r2->velocity - r1->velocity;


	//r1->velocity = (CoR*r2->mass*Vn + r1->mass*r1->velocity + r2->mass*r2->velocity) / (r2->mass+r1->mass);
	//r2->velocity = (CoR*r1->mass*-Vn + r1->mass*r1->velocity + r2->mass*r2->velocity) / (r2->mass + r1->mass);
	r1->velocity = r1->velocity*(r1->mass - r2->mass) / (r1->mass + r2->mass) + 2 * r2->mass*r2->velocity / (r1->mass + r2->mass);
	r2->velocity = r2->velocity*(r2->mass - r1->mass) / (r1->mass + r2->mass) + 2 * r1->mass*r1->velocity / (r1->mass + r2->mass);

}

