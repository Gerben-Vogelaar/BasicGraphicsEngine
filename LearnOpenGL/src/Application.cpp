#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <cmath>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "Textures.h"
#include "Shader.h"
#include "Camera.h"
#include "drawableObjects/DrawableObject.h"
#include "drawableObjects/Cube.h"
#include "GenerateSpheres.h"
#include "VertexDataFactory.h"

#include "glErrorHandling.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

const int screenWidth = 800;
const int screenHeight = 600;

Camera camera = Camera();

int main(int argc, char* argv[]) {

	//--------------------------------------------------------------------------
	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "glfwInit() failed" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	window = glfwCreateWindow(screenWidth, screenHeight, "Learn openGL", NULL, NULL);

	if (!window)
	{
		std::cout << "ERROR: Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//make the window the gl context
	glfwMakeContextCurrent(window);
	glViewport(0, 0, 800, 600);

	if (glewInit() != GLEW_OK) {
		std::cout << "ERROR: glewInit() failed" << std::endl;
		return -1;
	};

	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	//loading shaders
	Shader ourShader("src\\shaders\\sphere.vs", "src\\shaders\\sphere.fs");

	VertexDataFactory facto = VertexDataFactory();

	VertexDataBuffer* vertexDataBuffer = facto.createVertexData(DrawableType::SPHERE);

	const int totalSpheres = 2;
	GenerateSpheres sphereGen;

	Sphere obj[totalSpheres];
	//sphereGen.createSpheresRandomly(obj, totalSpheres, *vertexDataBuffer);
	//sphereGen.createSpheresInGrid(obj, totalSpheres, *vertexDataBuffer);
	sphereGen.createSpheresCollisionTestSimularMotion(obj, totalSpheres, *vertexDataBuffer);

	ourShader.use();

	vertexDataBuffer = facto.createVertexData(DrawableType::CUBE);

	Cube cube = Cube(glm::vec3(0.0f), glm::vec3(0.0f), 0.0f, *vertexDataBuffer);


	glEnable(GL_DEPTH_TEST);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		float currentFrame = (float)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//std::cout << 1 / deltaTime << std::endl;

		camera.processInput(window, deltaTime);


		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourShader.use();

		//glBindVertexArray(sphere.getVAO());

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//pause updating of object to verify the different states of spheres
		if (!camera.getPause()) {

			//update the sphere positions
			for (int i = 0; i < totalSpheres; i++) {
				obj[i].update(deltaTime);
			}

			/* detect sphere collision

			Current solution is n^2.
			This is too slow, should later on be updated to atleast
			linear solution.
			*/
			for (int i = 0; i < totalSpheres; i++) {
				for (int j = 0; j < totalSpheres; j++) {
					if (i == j) {
						continue;
					}
					else {
						obj[i].sphereColisionReflection(obj[j]);
					}
				}
			}
		}

		glm::mat4 projection = glm::perspective(glm::radians(camera.fov), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);

		glm::mat4 view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);
		ourShader.setMat4("view", view);

		ourShader.setVec3("lightColor", glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 model;
		for (int i = 0; i < totalSpheres; i++) {
			model = glm::mat4(1.0f);
			model = glm::translate(model, obj[i].getPosition());
			model = glm::scale(model, glm::vec3(obj[i].getRadius()));
			ourShader.setMat4("model", model);
			obj[i].draw();
		}

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		model = glm::mat4(1.0f);
		ourShader.setMat4("model", model);
		cube.draw();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	std::cout << "End";
	return 0;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	camera.camera_mouse_callback(window, (float)xpos, (float)ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	void camera_scroll_callback(GLFWwindow * window, float xoffset, float yoffset);
}
