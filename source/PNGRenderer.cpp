
#include "PNGRenderer.h"

PNGRenderer::PNGRenderer (
	glm::vec2 size,
	const char * filename
) : writer (size.x, size.y, 0, filename) {
	this->size = size;
}

void
PNGRenderer::render (float * pixels) {
	for (int i = 0; i < size.x * size.y; i++) {
		float red = pixels[i*3];
		float green = pixels[i*3+1];
		float blue = pixels[i*3+2];

		int x = i % (int) size.x;
		int y = i / (int) size.x;
		
		writer.plot(x, y, red, green, blue);
	}
}

void
PNGRenderer::close () {
	writer.close();
}

