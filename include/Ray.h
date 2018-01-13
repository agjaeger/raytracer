
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a ray with an origin and direction
 */ 

#pragma once

#include "glm/glm.hpp"
#include "Camera.h"

class Ray {
public:
	Ray(glm::dvec3 origin, glm::dvec3 direction);
	
	static Ray createPrimaryRay(double x, double y, Camera c);
	
public:
	glm::dvec3 origin;
	glm::dvec3 direction;
};