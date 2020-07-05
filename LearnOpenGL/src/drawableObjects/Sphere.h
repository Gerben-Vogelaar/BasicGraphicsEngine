#include "DrawableObject.h"

class Sphere : public DrawableObject {

private:
	double radius = 1.0;

public: 
	Sphere();
	Sphere(glm::vec3 position, glm::vec3 direction, float mass, VertexDataBuffer& bdb, double radius);

	virtual void shout();

	virtual void sphereColisionReflection(Sphere& obj);
	virtual bool sphereCollision(Sphere& obj);
	virtual void collisionCorrection(Sphere& obj);


	void setRadius(double radius);
	double getRadius();
};