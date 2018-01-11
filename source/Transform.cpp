
#include "Transform.h"

Transform::Transform() {
	this->position = Vector3::zero;
	this->rotation = Vector3::zero;
	this->scale = Vector3::zero;
}

Transform::Transform (Vector3 position) {
	this->position = position;
	this->rotation = Vector3::zero;
	this->scale = Vector3::zero;
}

Transform::Transform(
	Vector3 position,
	Vector3 rotation,
	Vector3 scale
) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}
