#pragma once
#include <GL/glew.h>
#include <iostream>

#include "VertexDataBuffer.h"
#include "glm/glm/glm.hpp"

VertexDataBuffer::VertexDataBuffer() : VAO(0), VBO(0), AMOUNT_VERTICIS(0) {};

VertexDataBuffer::VertexDataBuffer(float* vertices, int sizeOfvertice, int* vertexLayout, int lengthVertexLayout, int totalVertices) {

	for (int i = 0; i <= 9; i = i+3) {
		std::cout << vertices[i] << " " << vertices[i+1] << " " << vertices[i+2] << " " << std::endl;
	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeOfvertice, vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);

	int total = 0;

	for (int i = 0; i < lengthVertexLayout; i++) {
		total += vertexLayout[i];
	}

	//sets the values of each of the vertex attributes required to draw vertices properly.
	int count = 0;
	for (int i = 0; i < lengthVertexLayout; i++) {
		glVertexAttribPointer(i, vertexLayout[i], GL_FLOAT, GL_FALSE, total * sizeof(float), (void*)(count * sizeof(float)));
		glEnableVertexAttribArray(i);
		count += vertexLayout[i];
	}

	AMOUNT_VERTICIS = totalVertices;
}

void VertexDataBuffer::drawBuffer() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, AMOUNT_VERTICIS);
}