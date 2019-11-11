#pragma once

#include "drawableObjects/Sphere.h"


class GenerateSpheres {

public:  
	GenerateSpheres();
	Sphere* createSpheres(Sphere* array, int nrSpheres, VertexDataBuffer sphereData);
};
