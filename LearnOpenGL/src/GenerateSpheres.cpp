#pragma once

#include "GenerateSpheres.h"
#include <iostream>

glm::vec3 randomPostion() {
	return glm::vec3(rand() % 5 + 2, rand() % 20 + 2, rand() % 5 + 2);
}

glm::vec3 randomVelocity() {
	return glm::vec3(rand() % 2 + -1, rand() % 2 - 1, rand() % 2 - 1);
}

float randomRadius() {
	return rand() % 5 + 1;
}

GenerateSpheres::GenerateSpheres() {};

Sphere* GenerateSpheres::createSpheres(Sphere* array, const int nrSpheres, VertexDataBuffer sphereData) {

	for (int i = 0; i < nrSpheres; i++) {

		bool loop = true;

		//generate a random position and radius
		glm::vec3 randPos = randomPostion();
		float radius = randomRadius();

		array[i] = Sphere(randPos, glm::vec3(0.0f), 1.0f, sphereData, 2.0f);

		while (loop) {

			loop = false;

			for (int j = 0; j < i; j++) {
				if (!loop) {
					if (array[j].sphereCollision(array[i])) {

						randPos = randomPostion();
						radius = randomRadius();

						array[i].setPosition(randPos);

						loop = true;
						continue;
					}
				}
				break;
			}
		}
		array[i].shout();
	}

	std::cout << "Generated " << nrSpheres << " sphere" << std::endl;

	return array;
}



