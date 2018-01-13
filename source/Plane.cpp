
#include "Plane.h"

Plane::Plane (
	Transform t,
	Material m,
	glm::dvec3 normal
) {
	this->transform = t;
	this->normal = normal;
	this->material = m;
}

bool
Plane::intersect (
	Ray r,
	double &distOut
) {
	distOut = -1.0;
	
	double denom = glm::dot(this->normal, r.direction);

	if (denom <= 1e-6)
		return false;

	glm::dvec3 delta = this->transform.position - r.origin;
	double deltaDistance = glm::dot(delta, this->normal) / denom;

	if (deltaDistance >= 0.0) {
		distOut = deltaDistance;
		return true;
	}
	
	return false;
}

glm::dvec3
Plane::surfaceNormal (
	glm::dvec3 surfacePoint
) {
	return this->normal * -1.0;
}

