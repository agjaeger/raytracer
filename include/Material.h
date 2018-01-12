
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Stores asthetic rendering options
 */

#pragma once

#include "Vector3.h"

class Material {
public:
	Material();

public:
	Vector3 diffuseColor;
	double albedo;
};
