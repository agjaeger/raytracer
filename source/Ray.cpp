
#include "Ray.h"

Ray::Ray(double x, double y, Camera c) {
	double aspect_ratio = c.screenWidth / c.screenHeight;
	double fov_adjustment = tan(MathUtils::toRadians(c.fov) / 2.0);
	
	double sensor_x = ((((x + 0.5) / c.screenWidth) * 2.0 - 1.0) * aspect_ratio) * fov_adjustment;
	double sensor_y = (1.0 - ((y + 0.5) / c.screenHeight) * 2.0) * fov_adjustment;

	this->origin = Vector3::zero;
	this->direction = Vector3(sensor_x, sensor_y, -1.0).normalize();
}
