
#include "Vector3.h"

Vector3 Vector3::back (0, 0, -1);
Vector3 Vector3::down (0, -1, 0);
Vector3 Vector3::forward (0, 0, 1);
Vector3 Vector3::left (-1, 0, 0);
Vector3 Vector3::right (1, 0, 0);
Vector3 Vector3::up (0, 1, 0);
Vector3 Vector3::one (1, 1, 1);
Vector3 Vector3::zero (0, 0, 0);

Vector3::Vector3() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator+(const Vector3& right) {
	Vector3 result (
		this->x + right.x,
		this->y + right.y,
		this->z + right.z	
	);
	
	return result;
}

Vector3 Vector3::operator-(const Vector3& right) {
	Vector3 result (
		this->x - right.x,
		this->y - right.y,
		this->z - right.z	
	);
	
	return result;
}

Vector3 Vector3::operator*(const Vector3& right) {
	Vector3 result (
		this->x * right.x,
		this->y * right.y,
		this->z * right.z	
	);
	
	return result;
}

Vector3 Vector3::operator/(const Vector3& right) {
	Vector3 result (
		this->x / right.x,
		this->y / right.y,
		this->z / right.z	
	);
	
	return result;
}
