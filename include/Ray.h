
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a ray with an origin and direction
 */ 

#pragma once

#include <cmath>

#include "Vector3.h"
#include "MathUtils.h"
#include "Camera.h"

class Ray {
public:
	Ray(Vector3 origin, Vector3 direction);
	
	static Ray createPrimaryRay(double x, double y, Camera c);
	
public:
	Vector3 origin;
	Vector3 direction;
};