#pragma once

#include <iostream>
#include "Cube.h"


Cube::Cube()
	: DrawableObject() {}

Cube::Cube(glm::vec3 position, glm::vec3 direction, float mass, VertexDataBuffer& bdb)
	: DrawableObject(position, direction, mass, bdb) {}

void Cube::shout()
{
	std::cout << "I am a Cube!" << std::endl;
}
void Cube::sphereColisionReflection(Sphere& obj)
{
	//DOES NOTHING RIGHT NOW!
}
bool Cube::sphereCollision(Sphere& obj)
{
	return false;
};

