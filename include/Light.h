
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Describes how to render a light
 */

#pragma once

class Light {
public:
	Light();

public:
	Vector3 direction;
	Vector3 color;
	double intensity;
};
