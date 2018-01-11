
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

double Vector3::magnitude() {
	return sqrt(
		this->x * this->x + 
		this->y * this->y + 
		this->z * this->z
	);
}

Vector3 Vector3::normalize() {
	return *this / this->magnitude();
}

double Vector3::dot(Vector3 lhs, Vector3 rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
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

Vector3 Vector3::operator*(const double& right) {
	Vector3 result (
		this->x * right,
		this->y * right,
		this->z * right	
	);
	
	return result;
}

Vector3 Vector3::operator/(const double& right) {
	Vector3 result (
		this->x / right,
		this->y / right,
		this->z / right	
	);
	
	return result;
}

bool Vector3::operator==(const Vector3& right) {
	bool sameX = this->x && right.x;
	bool sameY = this->y && right.y;
	bool sameZ = this->z && right.z;
	
	return sameX && sameY && sameZ;
}
