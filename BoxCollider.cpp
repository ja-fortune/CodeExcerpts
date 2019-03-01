#include "BoxCollider.h"

BoxCollider::BoxCollider(float width_, float height_, float depth_)
	: Collider(Collider::ColliderType::BoxCollider), width(width_), height(height_), depth(depth_)
{}

BoxCollider::~BoxCollider() {

}

std::vector<glm::vec3> BoxCollider::GetVerts() {

	
	verts->push_back(glm::vec3(-width * 0.5f, height * 0.5f, depth * 0.5f));
	verts->push_back(glm::vec3(width * 0.5f, height * 0.5f, depth * 0.5f));
	verts->push_back(glm::vec3(width * 0.5f, -height * 0.5f, depth * 0.5f));
	verts->push_back(glm::vec3(-width * 0.5f, -height * 0.5f, depth * 0.5f));
	verts->push_back(glm::vec3(-width * 0.5f, height * 0.5f, -depth * 0.5f));
	verts->push_back(glm::vec3(width * 0.5f, height * 0.5f, -depth * 0.5f));
	verts->push_back(glm::vec3(width * 0.5f, -height * 0.5f, -depth * 0.5f));
	verts->push_back(glm::vec3(-width * 0.5f, -height * 0.5f, -depth * 0.5f));


	return *verts;
}