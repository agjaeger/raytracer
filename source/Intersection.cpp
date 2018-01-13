
#include "Intersection.h"

Intersection::Intersection () {
	this->distance = -1.0;
	this->s = NULL;
}

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
