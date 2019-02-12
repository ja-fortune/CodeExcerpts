#ifndef COLLISIONWORLD_H
#define COLLISIONWORLD_H

#include "../Rendering/3D/GameObject.h"




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
	void CollisionObjObj(GameObject* first, GameObject* second);
	void CollisionObjRigid(GameObject* first, GameObject* second);
	void CollisionRigidObj(GameObject* first, GameObject* second);
	void CollisionRigidRigid(GameObject* first, GameObject* second);

private:
	CollisionWorld();
	~CollisionWorld();

	static std::unique_ptr<CollisionWorld> collisionWorldInstance;
	friend std::default_delete<CollisionWorld>;

	static std::vector<GameObject*> objects;

};

#endif // !COLLISIONWORLD_H

