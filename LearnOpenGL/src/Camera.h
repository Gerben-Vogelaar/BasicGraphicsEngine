#pragma once

#include "glm/glm/glm.hpp"
#include "GLFW/glfw3.h"

class Camera {
public:
	glm::vec3 cameraPos = glm::vec3(0.0f, 5.0f, 15.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -10.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	bool pause = true;
	bool pausePressed = false;


	bool firstMouse = true;
	float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch = 0.0f;
	float lastX = 800.0f / 2.0f;
	float lastY = 600.0 / 2.0f;
	float fov = 45.0f;

	void processInput(GLFWwindow *window, const float deltaTime);
	void camera_mouse_callback(GLFWwindow* window, float xpos, float ypos);
	void camera_scroll_callback(GLFWwindow* window, float xoffset, float yoffset);
	bool getPause();
};