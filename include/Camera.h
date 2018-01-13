
#pragma once

#include "glm/glm.hpp"
#include "Transform.h"

class Camera {
public:
	int fov;
	int screenWidth;
	int screenHeight;
	
	Transform transform;
	glm::vec3 backgroundColor;
};
