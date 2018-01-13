
/*
 * Created by Alex Jaeger <agjaeger@ualr.edu>
 *
 * Describes how to render a light
 */

#pragma once

struct Light {
	glm::dvec3 direction;
	glm::dvec3 color;
	double intensity;
};
