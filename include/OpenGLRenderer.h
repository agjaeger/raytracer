
#pragma once

#include "glm/glm.hpp"
#include "glfw/glfw3.h"

class OpenGLRenderer {
public:
	OpenGLRenderer (glm::vec2 screenSize, const char *windowTitle);
	
	void render (float *pixels, glm::vec2 textureSize);
	void close();
	
public:
	GLFWwindow* window;
private:
	GLuint textureID;
};