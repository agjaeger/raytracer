
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a ray with an origin and direction
 */ 

#pragma once

#include "Vector3.h"

class Ray {
public:
	Ray(double x, double y, int sceneWidth, int sceneHeight);
	
public:
	Vector3 origin;
	Vector3 direction;
};
