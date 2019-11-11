#include "VertexDataBuffer.h"

enum class DrawableType{SPHERE, CUBE};

class VertexDataFactory {
public:
	VertexDataBuffer* createVertexData(DrawableType type);
};