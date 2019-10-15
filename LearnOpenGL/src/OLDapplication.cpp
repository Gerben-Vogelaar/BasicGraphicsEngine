//#pragma once
//#define STB_IMAGE_IMPLEMENTATION
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <string>
//#include <iostream>
//#include <cmath>
//#include <glm/glm/gtc/matrix_transform.hpp>
//#include <glm/glm/glm.hpp>
//#include <glm/glm/gtc/type_ptr.hpp>
//
//#include "Textures.h"
//#include "Shader.h"
//#include "Camera.h"
////#include "drawableObjects/DrawableObject.h"
//#include "drawableObjects/Sphere.h";
////#include "ImageLoader.cpp"
//
//
//
//#include "glErrorHandling.h"
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void createCircleVertices(const int radius, const int detail, float* points);
//void createSphereVertices(const int detail, float* points);
//float degreeToRadians(float i);
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//const int screenWidth = 800;
//const int screenHeight = 600;
//
//Camera ourCamera = Camera();
//
//// lighting
//glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
//glm::vec3 lightPos(2.0f, 2.0f, 2.0f);
//const float ambient = 0.5;
//
//int main(int argc, char* argv[]) {
//
//	//--------------------------------------------------------------------------
//	/* Initialize the library */
//	if (!glfwInit()) {
//		std::cout << "glfwInit() failed" << std::endl;
//		return -1;
//	}
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window;
//	window = glfwCreateWindow(screenWidth, screenHeight, "Learn openGL", NULL, NULL);
//
//	if (!window)
//	{
//		std::cout << "ERROR: Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	//make the window the gl context
//	glfwMakeContextCurrent(window);
//	glViewport(0, 0, 800, 600);
//
//	if (glewInit() != GLEW_OK) {
//		std::cout << "ERROR: glewInit() failed" << std::endl;
//		return -1;
//	};
//
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	//--------------------------------------------------------------------------
//	//loading shaders
//	Shader ourShader("src\\shaders\\shader.vs", "src\\shaders\\shader.fs");
//	Shader lightShader("src\\shaders\\light.vs", "src\\shaders\\light.fs");
//	Shader groundShader("src\\shaders\\ground.vs", "src\\shaders\\ground.fs");
//	Shader sphereShader("src\\shaders\\sphere.vs", "src\\shaders\\sphere.fs");
//
//	//--------------------------------------------------------------------------
//	//Sphere sphere;
//	//DrawableObject obj;
//
//	//sphere.update(1.0f);
//	//obj.update(1.0f);
//
//	float vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
//	};
//
//	float groundVertices[] = {
//		 1.0f,  1.0f,
//		-1.0f,  1.0f,
//		-1.0f, -1.0f,
//		 1.0f,  1.0f,
//		-1.0f, -1.0f,
//		 1.0f, -1.0f
//	};
//
//	//10 points, all x,y, 0,0 and the next point on circle
//
//	const int detail = 10;
//	float points[(detail + 1) * detail * 18]; // 18 * detail * detail];
//
//	createSphereVertices(detail, points);
//
//	//for (int i = 0; i < 18 * detail * detail; i++) {
//	//	points[i] = points[i] * 100.0f;
//	//}
//
//	//for (int i = 0; i < 9 * detail * detail; i += 3) {
//	//	if (i % 9 == 0) {
//	//		std::cout << std::endl;
//	//	}
//
//	//	std::cout << "(" <<  points[i] << " , " << points[i + 1] << " , " << points[i + 2] << "),";	
//	//}
//
//
//	//createCircleVertices(1.0f, detail, points);
//
//
//
//	//for (int i = 0; i < 360; i = i + 5) {
//	//	std::cout << "sin: " << sin(i) << " cos: " << cos(i) << std::endl;
//	//}
//
//	//for (int i = 0; i < 60; i = i + 2) {
//	//	std::cout << points[i] << " " << points[i+1] << std::endl;
//	//}
//
//
//
//	//glm::vec3 cubePositions[] = {
//	//  glm::vec3(0.0f,  0.0f,  0.0f),
//	//  glm::vec3(2.0f,  5.0f, -15.0f),
//	//  glm::vec3(-1.5f, -2.2f, -2.5f),
//	//  glm::vec3(-3.8f, -2.0f, -12.3f),
//	//  glm::vec3(2.4f, -0.4f, -3.5f),
//	//  glm::vec3(-1.7f,  3.0f, -7.5f),
//	//  glm::vec3(1.3f, -2.0f, -2.5f),
//	//  glm::vec3(1.5f,  2.0f, -2.5f),
//	//  glm::vec3(1.5f,  0.2f, -1.5f),
//	//  glm::vec3(-1.3f,  1.0f, -1.5f)
//	//};
//
//	unsigned int indices[] = {  // note that we start from 0!
//		0, 1, 2,   // first triangle
//		2, 0, 3    // second triangle
//	};
//
//	/*
//	VAO: stores bindings and enables for vertex attrib as well as the binging for the index list
//	VBO: Contains the array of data, specify what is there by using glBufferData
//	EBO: see VBO but for elements in VBO
//	*/
//
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//	unsigned int cubeVAO, VBO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(cubeVAO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	unsigned int lightVAO;
//	glGenVertexArrays(1, &lightVAO);
//	glBindVertexArray(lightVAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glGenBuffers(1, &VBO);
//
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	unsigned int groundVAO, groundVBO;
//
//	glGenVertexArrays(1, &groundVAO);
//	glGenBuffers(1, &groundVBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, groundVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(groundVertices), groundVertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(groundVAO);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	unsigned int sphereVAO, sphereVBO;
//	glGenVertexArrays(1, &sphereVAO);
//	glGenBuffers(1, &sphereVBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//
//	glBindVertexArray(sphereVAO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	//glEnableVertexAttribArray(2);
//
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer
//	//object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	Textures textures = Textures();
//	textures.addTexture("src\\textures\\lightMap.png", false);
//	textures.addTexture("src\\textures\\specularMap.png", false);
//
//	//textures.addTexture("src\\textures\\wall.jpg", false);
//	//textures.addTexture("src\\textures\\face.png", true);
//
//	//------------------------------------------------------------------------------
//
//	//NOTE you have to use the shaders before you can retreive the texture locations
//	ourShader.use();
//	/*glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
//	glUniform1i(glGetUniformLocation(ourShader.ID, "texture2"), 1);*/
//
//	glEnable(GL_DEPTH_TEST);
//
//	float lightInt = 0.5;
//	float distance = 6;
//	float sign = 0.005f;
//
//	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
//	ourShader.setMat4("projection", projection);
//
//	glm::vec3 objectPos = glm::vec3(0.5f, 5.0f, 0.5f);
//	glm::vec3 velocity = glm::vec3(0.0f, 0.01f, 0.0f);
//
//	//Sphere sphere = Sphere();
//
//	//float sphereVertices[] = createSphereArray();
//
//	/* Loop until the user closes the window */
//	while (!glfwWindowShouldClose(window))
//	{
//		float currentFrame = (float)glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		ourCamera.processInput(window, deltaTime);
//
//		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//textures.activateTextures();
//		ourShader.use();
//		glBindVertexArray(cubeVAO);
//
//		//projection matrix -- maps from camera to screen coordinates
//		glm::mat4 projection = glm::perspective(glm::radians(ourCamera.fov), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
//		ourShader.setMat4("projection", projection);
//		// camera/view matrix -- maps from world space to camera space
//		glm::mat4 view = glm::lookAt(ourCamera.cameraPos, ourCamera.cameraPos + ourCamera.cameraFront, ourCamera.cameraUp);
//		ourShader.setMat4("view", view);
//		//model matrix -- maps from local to world cordinates
//		glm::mat4 model = glm::mat4(1.0f);
//		model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f));
//		ourShader.setMat4("model", model);
//
//		//morph light color each frame
//		//lightColor = glm::vec3(lightInt, lightInt, 0.1f);
//		//if (lightInt >= 1.0f || lightInt<= 0.0f) {
//		//	sign = sign * -1;
//		//}
//		//lightInt += sign;
//
//		//set camera position -- world coordinates
//		ourShader.setVec3("viewPos", ourCamera.cameraPos);
//
//		//print object locations -- FOR DEBUGGING
//		/*std::cout << "Camera: (" << ourCamera.cameraPos.x << "," << ourCamera.cameraPos.y << "," << ourCamera.cameraPos.z << ")" << std::endl;
//		std::cout << "Light: (" << lightPos.x << "," << lightPos.y << "," << lightPos.z << ")" << std::endl;*/
//
//		//set light properties in shader
//		ourShader.setVec3("light.position", lightPos);
//		/*glm::vec3 lightColor;
//		lightColor.x = sin(glfwGetTime() * 2.0f);
//		lightColor.y = sin(glfwGetTime() * 0.7f);
//		lightColor.z = sin(glfwGetTime() * 1.3f);*/
//		glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // decrease the influence
//		glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence
//		ourShader.setVec3("light.ambient", ambientColor);
//		ourShader.setVec3("light.diffuse", diffuseColor);
//		ourShader.setVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));
//
//		//set Material properties in shader
//		ourShader.setVec3("material.ambient", glm::vec3(1.0f, 0.5f, 0.31f));
//		//ourShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.5f, 0.31f));
//		ourShader.setInt("material.diffuse", 0);
//		ourShader.setInt("material.specular", 1);
//		textures.activateTextures();
//		//ourShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
//		ourShader.setFloat("material.shininess", 64.0f);
//
//		//draw object
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		//bind the new VAO and set all properties of the shader.
//		//glBindVertexArray(lightVAO);
//		lightShader.use();
//		//lightShader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
//		lightShader.setVec3("lightColor", lightColor);
//
//		model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f));
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.1));
//		lightShader.setMat4("model", model);
//		lightShader.setMat4("projection", projection);
//		lightShader.setMat4("view", view);
//		glBindVertexArray(lightVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glBindVertexArray(groundVAO);
//		groundShader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(1.0f, 1.0f, 1.0f));
//		groundShader.setMat4("model", model);
//		groundShader.setMat4("view", view);
//		groundShader.setMat4("projection", projection);
//		glDrawArrays(GL_TRIANGLES, 0, 8);
//
//		glBindVertexArray(lightVAO);
//		lightShader.use();
//
//
//		objectPos -= velocity;
//		if (objectPos.y - 0.5f <= 1.0f) {
//			velocity *= -1;
//		}
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, objectPos);
//		lightShader.setMat4("model", model);
//		lightShader.setMat4("projection", projection);
//		lightShader.setMat4("view", view);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//		glBindVertexArray(sphereVAO);
//		sphereShader.use();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f));
//		sphereShader.setMat4("model", model);
//		sphereShader.setMat4("view", view);
//		sphereShader.setMat4("projection", projection);
//
//		//glPointSize(10.0f);
//		//glDrawArrays(GL_POINTS, 0, (detail + 1) * detail * 18); // detail * detail * 6 * 3);
//		glDrawArrays(GL_TRIANGLES, 0, (detail + 1) * detail * 18); // detail * detail * 6 * 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &groundVBO);
//	glDeleteBuffers(1, &sphereVBO);
//
//	glfwTerminate();
//
//	std::cout << "End";
//	return 0;
//}
//
//void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
//	ourCamera.camera_mouse_callback(window, (float)xpos, (float)ypos);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
//	void camera_scroll_callback(GLFWwindow* window, float xoffset, float yoffset);
//}
//
///*
//data points needed in points: detail * 6
//*/
//void createCircleVertices(const int radius, const int detail, float* points) {
//	int i = 0;
//	const float increment = 360.0f / double(detail);
//
//	float pi = 3.141592653589793238462643383279502884;
//
//	for (float angle = 0; angle < 360; angle = angle + increment) {
//		float radians = angle * pi / 180;
//		float radians2 = radians + (increment * pi / 180);
//
//		points[i] = cos(radians) * radius;
//		points[i + 1] = sin(radians) * radius;
//		points[i + 2] = 0.0f;
//		points[i + 3] = 0.0f;
//		points[i + 4] = cos(radians2) * radius;
//		points[i + 5] = sin(radians2) * radius;
//		i = i + 6;
//	};
//}
///*
//MEMORY REQUIREMENT POINTS: (detail + 1) * detail * 18 */
//void createSphereVertices(int detail, float* points) {
//
//	//TODO: for a odd detail value, wierd things happen
//
//	const float pi = 3.141592653589793238462643383279502884;
//
//	int count = 0;
//	int i = 0;
//	int sign = 1;
//
//	//used to calculate radius of the circle
//	const float increment = 360.0f / detail;
//
//	//z equals the radius of the circle, which should go from 0 to 1 to 0, which equals sin in range[0,pi]
//	//as well as the radius of the current circle
//	for (float z = 0.0f; z <= 180.0f; z += (increment / 2.0f)) {
//
//		//the radius of the current and next circle into radians
//		const float radius = sin(z * pi / 180.0f);
//		const float radiusNext = sin((z + increment / 2.0f) * pi / 180.0f);
//
//		if (z >= 90.0f) {
//			sign = -1;
//		}
//
//		//the distance from 0,0 to a value on the circle equals 1. Given the radius of the current circle, we can calulate the value for z by 1^2 = r^2 + z^2, z = sqrt(1-r^2);
//		float zPoint = sign * sqrt(1 - radius * radius); //z/90; // (z - 90.0f) / 90.0f;
//		float zPoint2 = sign * sqrt(1 - radiusNext * radiusNext);
//
//		//move through 360 degrees
//		for (float angle = 0; angle < 360; angle += increment) {
//			//radians for current circle, Cn points
//			const float radians = angle * pi / 180;
//			//radiands for next circle, Nn points
//			const float radians2 = radians + (increment * pi / 180);
//
//			/*points[i] = cos(radians) * radius;
//			points[i + 1] = sin(radians) * radius;
//			points[i + 2] = zPoint;
//			points[i + 3] = 0.0f;
//			points[i + 4] = 0.0f;
//			points[i + 5] = zPoint;
//			points[i + 6] = cos(radians2) * radius;
//			points[i + 7] = sin(radians2) * radius;
//			points[i + 8] = zPoint;
//			i = i + 9;*/
//
//			//C1
//			points[i] = cos(radians) * radius;
//			points[i + 1] = sin(radians) * radius;
//			points[i + 2] = zPoint;
//			//N1
//			points[i + 3] = cos(radians) * radiusNext;
//			points[i + 4] = sin(radians) * radiusNext;
//			points[i + 5] = zPoint2;
//			//C2
//			points[i + 6] = cos(radians2) * radius;
//			points[i + 7] = sin(radians2) * radius;
//			points[i + 8] = zPoint;
//			//N1
//			points[i + 9] = cos(radians) * radiusNext;
//			points[i + 10] = sin(radians) * radiusNext;
//			points[i + 11] = zPoint2;
//			//C2
//			points[i + 12] = cos(radians2) * radius;
//			points[i + 13] = sin(radians2) * radius;
//			points[i + 14] = zPoint;
//			//N2
//			points[i + 15] = cos(radians2) * radiusNext;
//			points[i + 16] = sin(radians2) * radiusNext;
//			points[i + 17] = zPoint2;
//
//			//each square has 6 points xyz: 6*3 = 18;
//			i += 18;
//		};
//	}
//	std::cout << "amount points required for sphere: " << i << std::endl;
//}
//
//float degreeToRadians(float i) {
//
//	const float pi = 3.141592653589793238462643383279502884;
//
//	return i * pi / 180.0f;
//}
