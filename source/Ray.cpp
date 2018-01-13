
#include "Ray.h"

Ray::Ray(glm::dvec3 origin, glm::dvec3 direction) {
	this->origin = origin;
	this->direction = direction;
}

Ray
Ray::createPrimaryRay(double x, double y, Camera c) {
	double aspect_ratio = c.screenSize.x / c.screenSize.y;
	double fov_adjustment = tan(glm::radians<double>(c.fov) / 2.0);
	
	double sensor_x = ((((x + 0.5) / c.screenSize.x) * 2.0 - 1.0) * aspect_ratio) * fov_adjustment;
	double sensor_y = (1.0 - ((y + 0.5) / c.screenSize.y) * 2.0) * fov_adjustment;

	return Ray(glm::dvec3(0.0), glm::normalize(glm::dvec3(sensor_x, sensor_y, -1.0)));
}
