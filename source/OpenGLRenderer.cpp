
#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer (
	glm::vec2 screenSize, 
	const char *windowTitle
) {
	if (!glfwInit())
		exit(EXIT_FAILURE);
	
	window = glfwCreateWindow(screenSize.x, screenSize.y, windowTitle, NULL, NULL);
    
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}	
	glfwMakeContextCurrent(window);

    glViewport(0, 0, screenSize.x, screenSize.y);

    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();   

    //Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();       

    glOrtho(0, screenSize.x, screenSize.y, 0, 0.1, 10);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);  
}

void
OpenGLRenderer::render (
	float *pixels,
	glm::vec2 textureSize
) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D (
		GL_TEXTURE_2D, 
		0, GL_RGB32F, 
		textureSize.x, textureSize.y, 
		0, GL_RGB,
		GL_FLOAT, pixels
	);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  0.0f); 
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
 //	glFlush();
	
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void 
OpenGLRenderer::close() {
	glDeleteTextures(1, &textureID);
	glfwDestroyWindow(window);
	glfwTerminate();
}