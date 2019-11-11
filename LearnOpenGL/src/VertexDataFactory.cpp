#include <cmath>
#include <iostream>

#include "VertexDataFactory.h"

//TODO: detail of the sphere data is still hardcoded, should be variable implementation.

void createSphereVertices(int detail, float* points);
float* createBoxVertices();

VertexDataBuffer* VertexDataFactory::createVertexData(DrawableType type)
{
	switch (type) {
		case DrawableType::SPHERE: 
		{
			//setup data required for createSphereVertices
			const int detail = 10;
			float points[(detail + 1) * detail * 18];
			int settings[1] = { 3 };

			createSphereVertices(detail, points);

			return &VertexDataBuffer(points, sizeof(points), settings, 1, (detail + 1) * detail * 18);

			break;
		}
		case DrawableType::CUBE:
		{
			//float* vertices = createBoxVertices();

			float vertices[108] = {
				// positions         
				-0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f,  0.5f, -0.5f,
				 0.5f,  0.5f, -0.5f,
				-0.5f,  0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,

				-0.5f, -0.5f,  0.5f,
				 0.5f, -0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,
				-0.5f, -0.5f,  0.5f,

				-0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,

				 0.5f,  0.5f,  0.5f,
				 0.5f,  0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,

				-0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				 0.5f, -0.5f,  0.5f,
				 0.5f, -0.5f,  0.5f,
				-0.5f, -0.5f,  0.5f,
				-0.5f, -0.5f, -0.5f,

				-0.5f,  0.5f, -0.5f,
				 0.5f,  0.5f, -0.5f,
				 0.5f,  0.5f,  0.5f,
				 0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f, -0.5f
			};

			int settings[1] = { 3 };

			return &VertexDataBuffer(vertices, sizeof(float) * 108, settings, 1, 108);

			break;
		}
	}
}

void createSphereVertices(int detail, float* points) {

	//TODO: for a odd detail value, wierd things happen

	const float pi = 3.141592653589793238462643383279502884;

	int count = 0;
	int i = 0;
	int sign = 1;

	//used to calculate radius of the circle
	const float increment = 360.0f / detail;

	//z equals the radius of the circle, which should go from 0 to 1 to 0, which equals sin in range[0,pi]
	//as well as the radius of the current circle
	for (float z = 0.0f; z <= 180.0f; z += (increment / 2.0f)) {

		//the radius of the current and next circle into radians
		const float radius = sin(z * pi / 180.0f);
		const float radiusNext = sin((z + increment / 2.0f) * pi / 180.0f);

		if (z >= 90.0f) {
			sign = -1;
		}

		//the distance from 0,0 to a value on the circle equals 1. Given the radius of the current circle, we can calulate the value for z by 1^2 = r^2 + z^2, z = sqrt(1-r^2);
		float zPoint = sign * sqrt(1 - radius * radius); //z/90; // (z - 90.0f) / 90.0f;
		float zPoint2 = sign * sqrt(1 - radiusNext * radiusNext);

		//move through 360 degrees
		for (float angle = 0; angle < 360; angle += increment) {
			//radians for current circle, Cn points
			const float radians = angle * pi / 180;
			//radiands for next circle, Nn points
			const float radians2 = radians + (increment * pi / 180);

			//C1
			points[i] = cos(radians) * radius;
			points[i + 1] = sin(radians) * radius;
			points[i + 2] = zPoint;
			//N1
			points[i + 3] = cos(radians) * radiusNext;
			points[i + 4] = sin(radians) * radiusNext;
			points[i + 5] = zPoint2;
			//C2
			points[i + 6] = cos(radians2) * radius;
			points[i + 7] = sin(radians2) * radius;
			points[i + 8] = zPoint;
			//N1
			points[i + 9] = cos(radians) * radiusNext;
			points[i + 10] = sin(radians) * radiusNext;
			points[i + 11] = zPoint2;
			//C2
			points[i + 12] = cos(radians2) * radius;
			points[i + 13] = sin(radians2) * radius;
			points[i + 14] = zPoint;
			//N2
			points[i + 15] = cos(radians2) * radiusNext;
			points[i + 16] = sin(radians2) * radiusNext;
			points[i + 17] = zPoint2;

			//each square has 6 points xyz: 6*3 = 18;
			i += 18;
		};
	}
	std::cout << "amount points required for sphere: " << i << std::endl;
}

float* createBoxVertices() {

	//Currently unable to store the vertex data here.

	return 0;
}

