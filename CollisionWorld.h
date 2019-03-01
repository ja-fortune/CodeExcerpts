#ifndef COLLISIONWORLD_H
#define COLLISIONWORLD_H

#include "../Rendering/3D/GameObject.h"
#include "SphereCollider.h"
#include "BoxCollider.h"


class CollisionWorld
{
public:



	CollisionWorld(const CollisionWorld&) = delete;
	CollisionWorld(const CollisionWorld&&) = delete;
	CollisionWorld& operator=(const CollisionWorld&) = delete;
	CollisionWorld& operator=(CollisionWorld&&) = delete;

	static CollisionWorld* GetInstance();
	void AddObject(GameObject* go_);
	void Update();
	void CollisionObjObj(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo);
	void CollisionObjRigid(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo);
	void CollisionRigidObj(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo);
	void CollisionRigidRigid(GameObject* first, GameObject* second, Collider::CollisionInfo colInfo);

	bool checkCollision(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo);

	bool SphereSphere(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo);
	bool SphereBox(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo);
	bool BoxSphere(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo);
	bool BoxBox(GameObject* first, GameObject* second, Collider::CollisionInfo* colInfo);


private:
	CollisionWorld();
	~CollisionWorld();

	static std::unique_ptr<CollisionWorld> collisionWorldInstance;
	friend std::default_delete<CollisionWorld>;

	static std::vector<GameObject*> objects;

};

#endif // !COLLISIONWORLD_H

