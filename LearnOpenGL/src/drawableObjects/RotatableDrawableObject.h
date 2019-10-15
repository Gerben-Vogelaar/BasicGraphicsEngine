#pragma once
#include "drawableObjects/DrawableObject.h"

//TODO: make an object rotatable

class RotatableDrawableObject : public DrawableObject {
public:
	RotatableDrawableObject(glm::vec3 possition, glm::vec3 velocity, float mass, VertexDataBuffer& bdb, int ) : DrawableObject(possition, velocity, mass, bdb) {
		
	}
};