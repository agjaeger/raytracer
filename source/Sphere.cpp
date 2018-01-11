
#include "Sphere.h"

Sphere::Sphere() {}

Sphere::Sphere(Transform t, Material m, int r) {
	this->transform = t;
	this->material = m;
	this->radius = r;
}

bool Sphere::intersect(Ray ray) {
	Vector3 dist = this->transform.position - ray.origin;
	
	double adjSideLength = Vector3::dot(dist, ray.direction);
	double oppSideLength = Vector3::dot(dist, dist) - (adjSideLength*adjSideLength);
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
	
	return true;
}

Vector3 Sphere::surfaceNormal(Vector3 point) {
	(point - this->transform.position).normalize();
}
