#pragma once

#include "VertexDataBuffer.h"
#include "glm/glm/glm.hpp"
//#include <GL/glew.h>


class VertexDataBuffer;

//TODO: create copy constructor and the copy assignment operator
//TODO  abstract the opengl data out of this object, now two objects with the same buffer data create the vertex twice in the buffer


// copy of this object now points to the same pointers as in this object, which in turn can be very bad.
//
// -Way to work better with passing arrays in cpp
//template<size_t N>
//void h(Sample(&arr)[N])
//{
//	size_t count = N; //N is 10, so would be count!
//	//you can even do this now:
//	//size_t count = sizeof(arr)/sizeof(arr[0]);  it'll return 10!
//}
//Sample arr[10];
//h(arr); //pass : same as before!
//
/*
drawing object wiht opengl requires:
1. vertex array
2. shaders
3. set VAO
4. set VBO -> what if multiple objects use same vao?
*/

//setting shaders should be done before drawing the object

class DrawableObject {
private:
	
	VertexDataBuffer buffer;

	glm::vec3 position;
	glm::vec3 velocity;
	float mass;

	double radius = 1.0;

public:
	DrawableObject();

	DrawableObject(glm::vec3 position, glm::vec3 direction, float mass, VertexDataBuffer& bdb);

	void shout();

	void update(float time);

	void sphereColisionReflection(DrawableObject& obj);
	bool sphereCollision(DrawableObject& obj);

	void BoxCollisionReflection	(DrawableObject& obj);
	bool boxCollision(DrawableObject& obj);
	

	void draw();

	glm::vec3 getVelocity();

	void setVelocity(glm::vec3 newVelocity);

	glm::vec3 getPosition();
	
	void setRadius(double radius) {
		this->radius = radius;
	}

	double getRadius() {
		return radius;
	}

void setPosition(glm::vec3 newPosition);

void setVertexDataBuffer(VertexDataBuffer& newBuffer);

	//DrawableObject* getCollisionObject(DrawableObject* objects, int arraySize) const;
	
}; 
