
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Stores asthetic rendering options
 */

#pragma once

#include "glm/glm.hpp"

struct Material {
	glm::dvec3 diffuseColor;
	double albedo;
};
