#pragma once

#include "drawableObjects/DrawableObject.h"


class GenerateSpheres {

public:  
	GenerateSpheres();
	DrawableObject* createSpheres(DrawableObject* array, int nrSpheres, VertexDataBuffer sphereData);
};
