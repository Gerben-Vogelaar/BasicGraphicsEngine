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
	

	//distance of objects is smaller than the sum of the radius
	if (sphereCollision(obj)) {
		
		

		glm::vec3 pos = getPosition();
		glm::vec3 vel = getVelocity();

		//retrieve object data
		glm::vec3 objPos = obj.getPosition();
		glm::vec3 objVel = obj.getVelocity();

		//normalized distance two objects
		glm::vec3 normal = glm::normalize(pos - objPos);
		
		glm::vec3 normVel = normalize(vel);

		glm::vec3 reflection = normVel - 2.0f * (glm::dot(normVel, normal)) * normal;
		reflection = length(vel) * reflection;

		//TODO: CASE; two objects move in the same direction but collide
		if (pos.y < objPos.y) {
			reflection *= -1;
		};

		addNewReflectionVector(reflection);

		collisionCorrection(obj);

			//setVelocity(0.99f * reflection);

			//std::cout << "reflection: " << reflection.x << " " << reflection.y << " " << reflection.z << " " << std::endl;
			//std::cout << "normal: " << normal2.x << " " << normal2.y << " " << normal2.z << " " << std::endl;
	};
}

void Sphere::collisionCorrection(Sphere& obj) {
	//displace objects such that they do not collide anymore
	//calc correct, still unindentified behavior
	glm::vec3 pos = getPosition();
	glm::vec3 objPos = obj.getPosition();

	glm::vec3 collidePoint = objPos - pos;
	glm::vec3 centerToCollisionPointThis = pos + glm::normalize(collidePoint) * (float)(getRadius());
	glm::vec3 centerToCollisionPointObj = objPos - glm::normalize(collidePoint) * (float)(obj.getRadius());

	glm::vec3 posOffset = (centerToCollisionPointThis - centerToCollisionPointObj) / 2.0f;

	pos -= posOffset;

	obj.setPosition(pos);
}

//currently only works for collison with spheres.
bool Sphere::sphereCollision(Sphere& obj) {

		glm::vec3 pos = getPosition();
		glm::vec3 objPos = obj.getPosition();

		float distance = sqrt(pow((pos.x - objPos.x), 2) + pow((pos.y - objPos.y), 2) + pow((pos.z - objPos.z), 2));
		double sumRadius = radius + obj.getRadius();

		return distance < sumRadius;
}

void Sphere::setRadius(double radius)
{
	this->radius = radius;
}

double Sphere::getRadius()
{
	return this->radius;
}





