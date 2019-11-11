#pragma once

#include "DrawableObject.h"

class Cube : public DrawableObject {

public:
	Cube();
	Cube(glm::vec3 position, glm::vec3 direction, float mass, VertexDataBuffer& bdb);

	virtual void shout();

	virtual void sphereColisionReflection(Sphere& obj);
	virtual bool sphereCollision(Sphere& obj);
};