
#pragma once

#include "SceneObject.h"

class Intersection {
public:
	Intersection(double dist, SceneObject *s);
	
	bool operator< (const Intersection &rhs);	
	
public:
	double distance;
	SceneObject *s;
};