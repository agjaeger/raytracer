
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a sphere that is traceable
 */

#pragma once

#include "Transform.h"
#include "Vector3.h"
#include "Ray.h"

class Sphere {
public:
	Sphere();
	
	bool intersect(Ray ray);
	
public:
	int radius;
	Vector3 color;
	Transform transform;	
};

