
#pragma once

#include "Transform.h"
#include "Material.h"
#include "Ray.h"

class SceneObject {
public:
	virtual bool intersect(Ray r) = 0;
	
public:
	Transform transform;
	Material material;
};
