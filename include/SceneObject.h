
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Describes a base class for all objects in the scene
 */

#pragma once

#include "Transform.h"
#include "Material.h"
#include "Vector3.h"
#include "Ray.h"

class SceneObject {
public:
	virtual bool intersect(Ray r, double &distOut) = 0;
	virtual Vector3 surfaceNormal(Vector3 surfacePoint) = 0;

public:
	Transform transform;
	Material material;
};
