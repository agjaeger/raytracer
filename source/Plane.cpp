
#include "Plane.h"

Plane::Plane (
	Transform t,
	Vector3 normal,
	Material m
) {
	this->transform = t;
	this->normal = normal;
	this->material = m;
}

bool
Plane::intersect (
	Ray r
) {
	double denom = Vector3::dot(this->normal, r.direction);

	if (denom <= 1e-6)
		return false;

	Vector3 delta = this->transform.position - r.origin;

	double deltaDistance = Vector3::dot(delta, this->normal) / denom;

	if (deltaDistance >= 0.0)
		return true;
}

