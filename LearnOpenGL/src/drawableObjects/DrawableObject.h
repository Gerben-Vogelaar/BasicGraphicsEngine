#pragma once

#include <iostream>

#include "VertexDataBuffer.h"
#include "glm/glm/glm.hpp"
//#include <GL/glew.h>

//should later be a generic struct since this only can contain float vertex not of generic type;
struct VertexData {
	int totalVertex;
	float* vertex;
};

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

//forward delcaration inheriting the DrawableObject
class Sphere;

class DrawableObject {
private:
	VertexDataBuffer buffer;
		
	glm::vec3 position;
	glm::vec3 velocity;
	float mass;

public:
	DrawableObject();

	DrawableObject(glm::vec3 position, glm::vec3 direction, float mass, VertexDataBuffer& bdb);
	
	//virtual ~DrawableObject(); //we should consider a virtual deconstructor
	virtual void shout();

	// -- Basic 

	void update(float time);

	void draw();

	// -- Collision: 
	// (Should later be private since they should only be used in the local update functions)
	
	virtual void sphereColisionReflection(Sphere& obj) = 0;
	virtual bool sphereCollision(Sphere& obj) = 0;

	//virtual void boxCollisionReflection	(DrawableObject& obj);
	//virtual bool boxCollision(DrawableObject& obj);

	// -- Getter / Setters
	glm::vec3 getVelocity();
	void setVelocity(glm::vec3 newVelocity);

	glm::vec3 getPosition();
	void setPosition(glm::vec3 newPosition);
	
	void setVertexDataBuffer(VertexDataBuffer& newBuffer);


//DrawableObject* getCollisionObject(DrawableObject* objects, int arraySize) const;
}; 
