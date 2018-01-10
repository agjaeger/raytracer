
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 * 
 * Describes a vector containing 3 doubles
 */ 

#pragma once

#include <cmath>

class Vector3 {
public:
	Vector3();
	Vector3(double x, double y, double z);
	
	double magnitude();
	Vector3 normalize();
	
	static double dot(Vector3 lhs, Vector3 rhs);
	
	// algebraic operators for Vector3 to Vector3
	Vector3 operator+(const Vector3& right);
	Vector3 operator-(const Vector3& right);
	Vector3 operator*(const double& right);
	Vector3 operator/(const double& right);

	// static properties
	static Vector3 back;
	static Vector3 down;
	static Vector3 forward;
	static Vector3 left;
	static Vector3 right;
	static Vector3 up;
	static Vector3 one;
	static Vector3 zero;
	
public:
	double x;
	double y;
	double z;
};