#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "Collider.h"

	class BoxCollider : public Collider {

	private:

		float width;
		float height;
		float depth;

		std::vector<glm::vec3> verts[8];

	public:

		BoxCollider(float width_, float height_, float depth_);
		~BoxCollider();
		std::vector<glm::vec3> GetVerts();
	};

#endif

