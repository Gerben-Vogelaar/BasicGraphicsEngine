#pragma once

#include "GenerateSpheres.h"
#include <iostream>

glm::vec3 randomPostion() {
	return glm::vec3(rand() % 20, rand() % 20, rand() % 20);
}

glm::vec3 randomVelocity() {
	return glm::vec3(rand() % 4 -2, rand() % 4 - 2, rand() % 4 - 2);
}

float randomRadius() {
	return rand() % 5 + 1;
}

GenerateSpheres::GenerateSpheres() {};

/*
TODO: The most inner for loop can loop infinitely, should get some basic methods to always have it terminte;
*/

Sphere* GenerateSpheres::createSpheresRandomly(Sphere* array, const int nrSpheres, VertexDataBuffer sphereData) {

	for (int i = 0; i < nrSpheres; i++) {

		bool loop = true;

		//generate a random position and radius
		glm::vec3 randPos = randomPostion();
		float radius = randomRadius();

		array[i] = Sphere(randPos, glm::vec3(0.0f), 1.0f, sphereData, 2.0f);

		for (int j = 0; i < j; j++) {

			if (array[j].sphereCollision(array[i])) {
				array[i].setPosition(randomPostion());
				j = 0;
			}
		}

		array[i].shout();
	}

	std::cout << "Generated " << nrSpheres << " sphere" << std::endl;

	return array;
}
	
/*
Test case where a sphere of higher mass drops on a sphere with lower mass both having a movement downwards.
-> currently the lower sphere moves in the wrong direction.
*/

Sphere* GenerateSpheres::createSpheresInGrid(Sphere* array, int nrSpheres, VertexDataBuffer sphereData)
{
	for (int i = 0; i < nrSpheres - 1; i++) {
		
		array[i] = Sphere(glm::vec3(i * 8.0f, 20, 2), randomVelocity(), 1.0f, sphereData, 2.0f);
			//array[i].setRadius(2.0f);
		
	}

	array[nrSpheres - 1] = Sphere(glm::vec3(2.0f, 30, 2), glm::vec3(0.0f), 2.0f, sphereData, 2.0f);
	//array[nrSpheres - 1] = Sphere(glm::vec3(20.0f, 30, 2), glm::vec3(0.0f), 2.0f, sphereData, 2.0f);

	return array;
}

/*
Requires an object of 2 spheres, additional spheres will be 
*/

Sphere* GenerateSpheres::createSpheresCollisionTestSimularMotion(Sphere* array, int sizeArray, VertexDataBuffer sphereData)
{
	if (sizeArray > 2) {
		return NULL;
	}

	array[0] = Sphere(glm::vec3(0.0f, 15.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.5f, sphereData, 2.0f);
	array[1] = Sphere(glm::vec3(0.0f, 9.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, sphereData, 2.0f);

}
