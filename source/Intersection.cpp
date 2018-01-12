
#include "Intersection.h"

Intersection::Intersection (
	double dist, 
	SceneObject *s
) {
	this->distance = dist;
	this->s = s;
}

bool 
Intersection::operator< (const Intersection &rhs) {
	return this->distance < rhs.distance;
}
