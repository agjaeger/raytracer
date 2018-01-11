
#pragma once

#include "Vector3.h"

class Camera {
public:
	Camera();
	
public:
	int fov;
	
	int screenWidth;
	int screenHeight;
	
	Vector3 backgroundColor;
};
