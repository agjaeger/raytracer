
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Describes how to render a light
 */

#pragma once

#include "Vector3.h"

struct Light {
	Vector3 direction;
	Vector3 color;
	double intensity;
};
