#pragma once

#include "drawableObjects/Sphere.h"


class GenerateSpheres {

public:  
	GenerateSpheres();
	Sphere* createSpheresRandomly(Sphere* array, int nrSpheres, VertexDataBuffer sphereData);
	Sphere* createSpheresInGrid(Sphere* array, int nrSpheres, VertexDataBuffer sphereData);
	Sphere* createSpheresCollisionTestSimularMotion(Sphere* array, int nrSpheres, VertexDataBuffer sphereData);
};
