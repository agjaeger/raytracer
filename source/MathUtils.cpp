
#include "MathUtils.h"

double MathUtils::toRadians(double degrees) {
	return degrees * (MathUtils::PI / 180);
}

double MathUtils::toDegrees(double radians) {
	return radians * (180 / MathUtils::PI);
}
