#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <cmath>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/type_ptr.hpp>

#include "drawableObjects/DrawableObject.h"
#include "Textures.h"
#include "Shader.h"
#include "Camera.h"
#include "GenerateSpheres.h"

#include "glErrorHandling.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void createCircleVertices(const int radius, const int detail, float* points);
void createSphereVertices(const int detail, float* points);
float degreeToRadians(float i);

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

const int screenWidth = 800;
const int screenHeight = 600;

Camera ourCamera = Camera();

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
	Shader ourShader("src\\shaders\\sphere.vs","src\\shaders\\sphere.fs");
	
	//create sphere vertex data
	const int detail = 100;
	float points[(detail + 1) * detail * 18]; // 18 * detail * detail];
	createSphereVertices(detail, points);

	int settings[1] = { 3 };

	for (int i = 0; i < 5; i++) {
		std::cout << points[i] << " " << std::endl;
	}

	std::cout << "size: " << sizeof(points) << std::endl;
	std::cout << points << " " << sizeof(points) << " " << settings << " " << 1 << " " << (detail + 1) * detail * 18 << std::endl;

	VertexDataBuffer sphereData(points, sizeof(points), settings, 1, (detail + 1)*detail * 18);
	const int totalSpheres= 10;
	GenerateSpheres sphereGen;
	DrawableObject obj[totalSpheres]; // = new DrawableObject[totalSpheres];
	sphereGen.createSpheres(obj, totalSpheres, sphereData);

	obj->shout();

	//for (int i = 0; i < totalSpheres; i++) {
	//	(obj[i]).shout;
	//}

	//DrawableObject sphere(glm::vec3(1.0f, 10.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f), 1.0f, sphereData);
	//DrawableObject sphere2(glm::vec3(5.0f, 10.0f, 1.0f), glm::vec3(-0.4f, 0.0f, 0.0f), 1.0f, sphereData);
	//DrawableObject sphere3(glm::vec3(1.0f, 6.0f, 1.0f), glm::vec3(0.2f, 0.0f, 0.0f), 1.0f, sphereData);
	//DrawableObject sphere4(glm::vec3(5.0f, 3.0f, 1.0f), glm::vec3(-0.2f, 0.0f, 0.0f), 1.0f, sphereData);

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

	VertexDataBuffer boxData(vertices, sizeof(vertices), settings, 1, 108);

	DrawableObject box(glm::vec3(1.0f), glm::vec3(1.0f), 1.0f, boxData);

	ourShader.use();

	glEnable(GL_DEPTH_TEST);

	//int sizeOfVertices = 108 * 4;

	//unsigned int VAO, VBO;

	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, 432, vertices, GL_STATIC_DRAW);

	//glBindVertexArray(VAO);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0 * sizeof(float)));
	//glEnableVertexAttribArray(0);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = (float)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		ourCamera.processInput(window, deltaTime);

		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourShader.use();

		//glBindVertexArray(sphere.getVAO());
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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

		glm::mat4 projection = glm::perspective(glm::radians(ourCamera.fov), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);

		glm::mat4 view = glm::lookAt(ourCamera.cameraPos, ourCamera.cameraPos + ourCamera.cameraFront, ourCamera.cameraUp);
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
			   		

		model = glm::mat4(1.0f);
		model = glm::translate(model, box.getPosition());
		model = glm::translate(model, glm::vec3(0.0f, 10.0f, 0.0f));
		model = glm::scale(model, glm::vec3(20.0f));
		ourShader.setMat4("model", model);
		box.draw();		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	std::cout << "End";
	return 0;
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
	ourCamera.camera_mouse_callback(window, (float)xpos, (float)ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	void camera_scroll_callback(GLFWwindow* window, float xoffset, float yoffset);
}

/*
data points needed in points: detail * 6 
*/
void createCircleVertices(const int radius, const int detail, float* points) {
	int i = 0;
	const float increment = 360.0f / double(detail);

	float pi = 3.141592653589793238462643383279502884;

	for (float angle = 0; angle < 360; angle = angle + increment) {
		float radians = angle * pi / 180;
		float radians2 = radians + (increment * pi / 180);

		points[i] = cos(radians) * radius;
		points[i + 1] = sin(radians) * radius;
		points[i + 2] = 0.0f;
		points[i + 3] = 0.0f;
		points[i + 4] = cos(radians2) * radius;
		points[i + 5] = sin(radians2) * radius;
		i = i + 6;
	};
}
/*
MEMORY REQUIREMENT POINTS: (detail + 1) * detail * 18 */
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
	for (float z = 0.0f; z <= 180.0f; z += (increment/2.0f)) {

		//the radius of the current and next circle into radians
		const float radius =	 sin(z * pi / 180.0f);
		const float radiusNext = sin((z + increment/2.0f) * pi / 180.0f);

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
