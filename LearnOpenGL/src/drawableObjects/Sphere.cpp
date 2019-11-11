#include "Sphere.h"

Sphere::Sphere()
	: DrawableObject(), radius(0) {};

Sphere::Sphere(glm::vec3 position, glm::vec3 direction, float mass, VertexDataBuffer& bdb, double radius)
	: DrawableObject(position, direction, mass, bdb) {
	
	setRadius(radius);
}

void Sphere::shout()
{
	std::cout << "I'm a sphere" << std::endl;
};

//currently only works for collison with spheres.
void Sphere::sphereColisionReflection(Sphere& obj) {
	glm::vec3 pos = getPosition();
	glm::vec3 objPos = obj.getPosition();

	//distance of objects is smaller than the sum of the radius
	if (sphereCollision(obj)) {
		glm::vec3 collisionPoint = pos - 0.5f * (pos - objPos);

		//std::cout << "collisionPoint = " << collisionPoint.x << " " << collisionPoint.y << " " << 
		//	collisionPoint.z << " " << std::endl;
		//N = normalize(C - O)
		glm::vec3 normal = glm::normalize(pos - objPos);
		glm::vec3 normal2 = pos - objPos; //tobe deleted

		glm::vec3 normVel = normalize(this->getVelocity());
		//R = V - 2(dot(V, N))N

		glm::vec3 reflection = normVel - 2.0f * (glm::dot(normalize(normVel), normal)) * normal;
		reflection = length(this->getVelocity()) * reflection;	

		setVelocity(0.99f * reflection);

		//std::cout << "reflection: " << reflection.x << " " << reflection.y << " " << reflection.z << " " << std::endl;
		//std::cout << "normal: " << normal2.x << " " << normal2.y << " " << normal2.z << " " << std::endl;
	}
}

//currently only works for collison with spheres.
bool Sphere::sphereCollision(Sphere& obj) {

		glm::vec3 pos = getPosition();
		glm::vec3 objPos = obj.getPosition();

		float distance = sqrt(pow((pos.x - objPos.x), 2) + pow((pos.y - objPos.y), 2) + pow((pos.z - objPos.z), 2));
		double sumRadius = radius + obj.getRadius();

		return distance <= sumRadius;
}

void Sphere::setRadius(double radius)
{
	this->radius = radius;
}

double Sphere::getRadius()
{
	return this->radius;
}

