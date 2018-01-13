
#include "Sphere.h"

Sphere::Sphere() {}

Sphere::Sphere (
	Transform t,
	Material m,
	double r
) {
	this->transform = t;
	this->material = m;
	this->radius = r;
}

bool
Sphere::intersect (
	Ray ray,
	double &distOut
) {
	distOut = -1.0;
	
	glm::dvec3 dist = this->transform.position - ray.origin;

	double adjSideLength = glm::dot(dist, ray.direction);
	double oppSideLength = glm::dot(dist, dist) - (adjSideLength*adjSideLength);
	double radiusSquared = this->radius * this->radius;

	if (adjSideLength < 0)
		return false;

	if (oppSideLength > radiusSquared)
		return false;

	double thc = sqrt(radiusSquared - oppSideLength);
	double t0 = adjSideLength - thc;
	double t1 = adjSideLength + thc;

	if (t0 > t1)
		std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1;

		if (t1 < 0)
			return false;
	}

	distOut = t0;
	return true;
}

glm::dvec3
Sphere::surfaceNormal (
	glm::dvec3 surfacePoint
) {
	return glm::normalize(surfacePoint - this->transform.position);
}
