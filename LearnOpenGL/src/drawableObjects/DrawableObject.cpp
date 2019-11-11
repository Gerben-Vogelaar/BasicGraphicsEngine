#pragma once
#include "drawableObjects/DrawableObject.h"

#include <iostream>
DrawableObject::DrawableObject() : position(glm::vec3(0.0f)), velocity(glm::vec3(0.0f)), mass(0.0f), buffer(VertexDataBuffer()) {};

DrawableObject::DrawableObject(glm::vec3 possition, glm::vec3 velocity, float mass, VertexDataBuffer& bdb) :
	position(possition), velocity(velocity), mass(mass), buffer(bdb){};
	
	void DrawableObject::shout() {
		std::cout << "position: " <<  position.x << " " << position.y << " " << position.z << " " << std::endl;

		//std::cout << "Im a drawable" << std::endl;
	}

	/*
	Apply gravitational forces to the object
	*/
	void DrawableObject::update(float time) {
		time = time/5;
		glm::vec3 newPosition = getPosition();
		glm::vec3 newVelocity = getVelocity();

		//std::cout << "POS: " << newPosition.x << " " << newPosition.y << " " << newPosition.z << " " << std::endl;
		//std::cout << "VEL: " << newVelocity.x << " " << newVelocity.y << " " << newVelocity.z << " " << std::endl;

		//calculate how much the objects speed up afte
		const float force = mass * -9.81;

		glm::vec3 acceleration = time * glm::vec3(0.0f, force, 0.0f);

		newVelocity = newVelocity + acceleration;

		newPosition = newPosition + time * newVelocity;

		if (newPosition.y <= 0 && newVelocity.y < 0) {

			newPosition.y = 0.0f;

			newVelocity.y = newVelocity.y * -0.9;
		}

		newVelocity.x = newVelocity.x * .99f;
		newVelocity.z = newVelocity.z * .99f;

		setPosition(newPosition);		
		setVelocity(newVelocity);
	};

	void DrawableObject::draw() {
		buffer.drawBuffer();
	};

	glm::vec3 DrawableObject::getVelocity() {
		return velocity;
	}

	void DrawableObject::setVelocity(glm::vec3 newVelocity) {
		velocity = newVelocity;
	}

	glm::vec3 DrawableObject::getPosition() {
		return position;
	}

	void DrawableObject::setPosition(glm::vec3 newPosition) {
		position = newPosition;
	}

	void DrawableObject::setVertexDataBuffer(VertexDataBuffer& newBuffer) {
		buffer = newBuffer;
	}

	/*
	Update only this object, no need for updating the other since that will be done
	inside the call by that object.
	*/
	//void DrawableObject::sphereColisionReflection(DrawableObject& obj) {
	//	glm::vec3 pos = getPosition();
	//	glm::vec3 objPos = obj.getPosition();

	//	//distance of objects is smaller than the sum of the radius
	//	if (sphereCollision(obj)) {			
	//		glm::vec3 collisionPoint = pos - 0.5f * (pos - objPos);

	//		//std::cout << "collisionPoint = " << collisionPoint.x << " " << collisionPoint.y << " " << 
	//		//	collisionPoint.z << " " << std::endl;
	//		//N = normalize(C - O)
	//		glm::vec3 normal = glm::normalize(pos - objPos);
	//		glm::vec3 normal2 = pos - objPos; //tobe deleted

	//		glm::vec3 normVel = normalize(velocity);
	//		//R = V - 2(dot(V, N))N

	//		glm::vec3 reflection = normVel - 2.0f * (glm::dot(normalize(normVel), normal)) *normal;
	//		reflection = length(velocity) * reflection;

	//		setVelocity(0.99f * reflection);

	//		//std::cout << "reflection: " << reflection.x << " " << reflection.y << " " << reflection.z << " " << std::endl;
	//		//std::cout << "normal: " << normal2.x << " " << normal2.y << " " << normal2.z << " " << std::endl;
	//	}
	//}

	//bool DrawableObject::sphereCollision(DrawableObject& obj) {

	//	glm::vec3 pos = getPosition();
	//	glm::vec3 objPos = obj.getPosition();

	//	float distance = sqrt(pow((pos.x - objPos.x), 2) + pow((pos.y - objPos.y), 2) + pow((pos.z - objPos.z), 2));
	//	double sumRadius = radius + obj.getRadius();

	//	return distance <= sumRadius;
	//}

	//void DrawableObject::BoxCollisionReflection(DrawableObject& obj) {
	//		
	//}

	//bool DrawableObject::boxCollision(DrawableObject& box) {

	//	glm::vec3 pos = getPosition();
	//	glm::vec3 boxPos = box.getPosition();
	//	float boxEdgeLength = box.getRadius()/2;

	//	return false;


	//}
	//DrawableObject* getCollisionObject(DrawableObject* objects, int arraySize) const;

