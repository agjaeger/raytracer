
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a sphere that is traceable
 */

#pragma once

#include <cmath>
#include <algorithm>

#include "SceneObject.h"
#include "Transform.h"
#include "Material.h"

#include "Vector3.h"
#include "Ray.h"

class Sphere : public SceneObject {
public:
	Sphere();
	Sphere(Transform t, Material m, double r);
	
	bool intersect(Ray ray, double &distOut);
	Vector3 surfaceNormal(Vector3 point);
	
public:
	double radius;	
};

