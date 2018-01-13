
#pragma once

#include "glm/glm.hpp"

class Transform {	
public:
	glm::dvec3 position = glm::dvec3(0.0);
	glm::dvec3 rotation = glm::dvec3(0.0);
	glm::dvec3 scale = glm::dvec3(0.0);
};
