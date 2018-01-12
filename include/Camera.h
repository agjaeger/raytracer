
#pragma once

#include "Vector3.h"

struct Camera {
	int fov;
	
	int screenWidth;
	int screenHeight;
	
	Vector3 backgroundColor;
};
