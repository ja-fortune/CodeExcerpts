#include "CollisionWorld.h"

std::unique_ptr<CollisionWorld> CollisionWorld::collisionWorldInstance = nullptr;
std::vector<GameObject*> CollisionWorld::objects = std::vector<GameObject*>();

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

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
			Collider::CollisionInfo colInfo;

			if (checkCollision(objects[iter], objects[next], &colInfo))
			{
				float dotProduct = glm::dot(objects[iter]->GetPosition() - objects[next]->GetPosition(), colInfo.CollisionAxis);
				if (dotProduct < 0)
					colInfo.CollisionAxis *= -1;



				if (objects[iter]->GetRigidBody() != nullptr)
				{
					if (objects[next]->GetRigidBody() != nullptr)
					{
						CollisionRigidRigid(objects[iter], objects[next], colInfo);
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

/*

Collision Response Functions

*/


void CollisionWorld::CollisionObjObj(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo)
{
}
void CollisionWorld::CollisionObjRigid(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo)
{
}
void CollisionWorld::CollisionRigidObj(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo)
{
}
void CollisionWorld::CollisionRigidRigid(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo)
{


	Rigidbody* r1 = first->GetRigidBody();
	Rigidbody* r2 = second->GetRigidBody();

	first->Translate(0.5f * colInfo.overlap * colInfo.CollisionAxis);
	r1->position += (0.5f * colInfo.overlap * colInfo.CollisionAxis);
	second->Translate(0.5f * colInfo.overlap * colInfo.CollisionAxis);
	r2->position += (-0.5f * colInfo.overlap * colInfo.CollisionAxis);

	float CoR = 0.5f * (r1->Restitution + r2->Restitution);
	glm::vec3 Vn = r2->velocity - r1->velocity;


	//r1->velocity = (CoR*r2->mass*Vn + r1->mass*r1->velocity + r2->mass*r2->velocity) / (r2->mass+r1->mass);
	//r2->velocity = (CoR*r1->mass*-Vn + r1->mass*r1->velocity + r2->mass*r2->velocity) / (r2->mass + r1->mass);
	r1->velocity = r1->velocity*(r1->mass - r2->mass) / (r1->mass + r2->mass) + 2 * r2->mass*r2->velocity / (r1->mass + r2->mass);
	r2->velocity = r2->velocity*(r2->mass - r1->mass) / (r1->mass + r2->mass) + 2 * r1->mass*r1->velocity / (r1->mass + r2->mass);

}


/*

Collision Detection Functions

*/


bool CollisionWorld::checkCollision(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo)
{
	if (first->GetCollider() != nullptr || second->GetCollider() != nullptr)
	{
		if (first->GetCollider()->Type() == Collider::ColliderType::SphereCollider && second->GetCollider()->Type() == Collider::ColliderType::SphereCollider)
		{
			return SphereSphere(first, second, colInfo);
		}
		else if (first->GetCollider()->Type() == Collider::ColliderType::SphereCollider && second->GetCollider()->Type() == Collider::ColliderType::BoxCollider)
		{
			return SphereBox(first, second, colInfo);
		}
		else if (first->GetCollider()->Type() == Collider::ColliderType::BoxCollider && second->GetCollider()->Type() == Collider::ColliderType::SphereCollider)
		{
			return BoxSphere(first, second, colInfo);
		}
		else if (first->GetCollider()->Type() == Collider::ColliderType::BoxCollider && second->GetCollider()->Type() == Collider::ColliderType::BoxCollider)
		{
			return BoxBox(first, second, colInfo);
		}
	}
	
		return false;
}

bool CollisionWorld::SphereSphere(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo)
{
	SphereCollider* col1 = (SphereCollider*)first->GetCollider();
	SphereCollider* col2 = (SphereCollider*)second->GetCollider();

	glm::vec3 dist = first->GetPosition() - second->GetPosition();

	float overlap = col1->Radius() + col2->Radius() - glm::length(dist);
	colInfo->CollisionAxis = dist; 
	colInfo->overlap = overlap;

	return overlap > 0.0f; 

}
bool CollisionWorld::SphereBox(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo)
{
	SphereCollider* col1 = (SphereCollider*)first->GetCollider();
	BoxCollider* col2 = (BoxCollider*)second->GetCollider();

	std::vector<glm::vec3> boxVerts = col2->GetVerts();
	glm::vec3 projectionAxis[8];

	glm::mat4 translation = glm::translate(glm::mat4(),second->GetPosition());
	glm::mat4 rotation = glm::rotate(glm::mat4(), second->GetRotation().z, glm::vec3(0.0f, 0.0f, 1.0f));

	for (int i = 0; i < 8; i++)
	{
		boxVerts[i] = glm::vec3(translation * rotation * glm::vec4(boxVerts[i], 1.0f));
	}
	for (int i = 0; i < 8; i++)
	{
		glm::vec3 v1 = boxVerts[i];
		glm::vec3 v2 = boxVerts[(i + 1) % 8];

		projectionAxis[i] = glm::normalize(glm::cross(v2 - v1, glm::vec3(0.0f, 0.0f, -1.0f)));
	}

	float sMin = 0.0f;
	float sMax = 0.0f;

	float bMin = 0.0f;
	float bMax = 0.0f;

	float sProjection = 0.0f;
	float bProjection = 0.0f;

	float lowestOverlap = 9999999;

	for (int i = 0; i < 8; i++) 
	{

		for (int j = 0; j < 8; j++) 
		{
			bProjection = glm::dot(boxVerts[i], projectionAxis[j]);
		
			if (j == 0) {

				bMin = bProjection;
				bMax = bProjection;

			}
			else {

				if (bProjection < bMin)
					bMin = bProjection;

				if (bProjection > bMax)
					bMax = bProjection;
			}
		
		}
		glm::vec3 p1 = first->GetPosition() + projectionAxis[i] * col1->Radius();
		glm::vec3 p2 = first->GetPosition() - projectionAxis[i] * col1->Radius();

		sProjection = glm::dot(p1, projectionAxis[i]);

		sMin = sProjection;
		sMax = sProjection;

		sProjection = glm::dot(p2, projectionAxis[i]);

		if (sProjection < sMin)
			sMin = sProjection;

		if (sProjection > sMax)
			sMax = sProjection;

		float highestMin = max(sMin, bMin);
		float lowestMax = min(sMax, bMax);
		float overlap = lowestMax - highestMin;

		if (overlap < lowestOverlap)
		{
			lowestOverlap = overlap;
			colInfo->CollisionAxis = projectionAxis[i];
			colInfo->overlap = overlap;
		}

		if ((sMin < bMin || sMin > bMax) && (sMax < bMin || sMax > bMax) &&
			(bMin < sMin || bMin > sMax) && (bMax < sMin || bMax > sMax)) {

			return false;
		}
	}

	return true;

}
bool CollisionWorld::BoxSphere(GameObject* collider1, GameObject* collider2, Collider::CollisionInfo* colInfo)
{
	return true;
}
bool CollisionWorld::BoxBox(GameObject* collider1, GameObject* collider2, Collider::CollisionInfo* colInfo)
{
	return true;
}