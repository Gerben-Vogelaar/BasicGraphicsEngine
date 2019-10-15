
class VertexDataBuffer {
public:
	unsigned int VAO, VBO;
	int AMOUNT_VERTICIS;

	int shout = 333;

	VertexDataBuffer();
	VertexDataBuffer(float* vertices, int sizeOfvertice, int* vertexLayout, int vertexLayoutSize, int totalVertices);

	void drawBuffer();

	//changeVertexBuffer();

private:
	
};

