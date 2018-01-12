
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Describes how to intersect a plane
 */

#pragma once

#include "SceneObject.h"
#include "Ray.h"
#include "Transform.h"

class Plane : public SceneObject {

public:
	Plane(Transform t, Vector3 normal, Material m);

	bool intersect(Ray r, double &distOut);
	Vector3 surfaceNormal(Vector3 surfacePoint);

public:
	Vector3 normal;
};
