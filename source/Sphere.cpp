
#include "Sphere.h"

Sphere::Sphere() {
	
}

bool Sphere::intersect(Ray ray) {
	Vector3 dist = this->transform.position - ray.origin;
	double adjSideLength = Vector3::dot(dist, ray.direction);
	double oppSideLength = Vector3::dot(dist, dist) - (adjSideLength*adjSideLength);
		
	return oppSideLength < (this->radius * this->radius);
}
