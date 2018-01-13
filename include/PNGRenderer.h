
#pragma once

#include "glm/glm.hpp"
#include "pngwriter/pngwriter.h"

#include "logger/easyloggingpp.h"

class PNGRenderer {
public:
	PNGRenderer(glm::vec2 size, const char * filename);
	
	void render(float *pixels);
	void close();
	
private:
	pngwriter writer;
	glm::vec2 size;

};