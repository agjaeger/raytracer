
#pragma once

#include "SceneObject.h"
#include "Ray.h"
#include "Transform.h"

class Plane : public SceneObject {
	
public:
	Plane(Transform t, Vector3 normal, Material m);
	bool intersect(Ray r);
	
public:
	Vector3 normal;
};
