
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Describes how to intersect a plane
 */

#pragma once

#include <algorithm>

#include "SceneObject.h"
#include "Ray.h"
#include "Transform.h"

class Plane : public SceneObject {

public:
	Plane(Transform t, Material m, glm::dvec3 n);

	bool intersect(Ray r, double &distOut);
	glm::dvec3 surfaceNormal(glm::dvec3 surfacePoint);

public:
	glm::dvec3 normal;
};
