
#pragma once

#include "glm/glm.hpp"
#include "Transform.h"

class Camera {
public:
	int fov;
	
	Transform transform;
	glm::dvec3 backgroundColor;
	glm::dvec2 screenSize = glm::dvec2(0);
};
