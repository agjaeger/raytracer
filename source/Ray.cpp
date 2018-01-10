
#include "Ray.h"

Ray::Ray(double x, double y, int sceneWidth, int sceneHeight) {
	double sensor_x = ((x + 0.5) / sceneWidth) * 2.0 - 1.0;
	double sensor_y = 1.0 - ((y + 0.5) / sceneHeight) * 2.0;

	this->origin = Vector3::zero;
	this->direction = Vector3(sensor_x, sensor_y, -1.0).normalize();
}
