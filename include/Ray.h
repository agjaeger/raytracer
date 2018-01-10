
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a ray with an origin and direction
 */ 

#pragma once

class Ray {
public:
	Ray();
	
public:
	Vector3 origin;
	Vector3 direction;
};
