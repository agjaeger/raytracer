
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a sphere that is traceable
 */

#pragma once

#include <algorithm>

#include "SceneObject.h"
#include "Transform.h"
#include "Material.h"

#include "Ray.h"

class Sphere : public SceneObject {
public:
	Sphere();
	Sphere(Transform t, Material m, double r);
	
	bool intersect(Ray ray, double &distOut);
	glm::dvec3 surfaceNormal(glm::dvec3 point);
	
public:
	double radius;	
};

