
/*
 * Hello World
 */

#include <pngwriter.h>
#include <iostream>
#include <algorithm>
#include <vector>

#include "Material.h"
#include "Ray.h"
#include "Vector3.h"

#include "SceneObject.h"
#include "Plane.h"
#include "Sphere.h"

#include "Light.h"

struct Intersection {
	double distance;
	Sphere s;
};

bool
compareIntersection (
	const Intersection &a,
	const Intersection &b
) {
	return a.distance < b.distance;
}

int
main () {
	Camera c;
	c.screenWidth = 600;
	c.screenHeight = 300;
	c.fov = 90;
	c.backgroundColor = Vector3(0.1, 1.0, 0.6);

	Material sphere1;
	sphere1.diffuseColor = Vector3(0.1, 0.0, 1.0);
	sphere1.albedo = 0.1;

	Material sphere2;
	sphere2.diffuseColor = Vector3(1.0, 0.0, 0.5);
	sphere2.albedo = 0.1;

	Material sphere3;
	sphere3.diffuseColor = Vector3(1.0, 1.0, 0.0);
	sphere3.albedo = 0.1;

	Material plane;
	plane.diffuseColor = Vector3(0.4, 0.4, 0.4);
	plane.albedo = 0.1;

	std::vector<SceneObject*> sceneObjects = {
		new Plane(Transform(Vector3(0.0,3.0,-5.0)), Vector3(0.0, 0.75, 0.0), plane),
		new Sphere(Transform(Vector3(0.0,0.0,-2.0)), sphere1, 1),
		new Sphere(Transform(Vector3(1.0,-1.0,-5.0)), sphere2, 1),
		new Sphere(Transform(Vector3(2.0,2.0,-5.0)), sphere3, 1)
	};

	pngwriter png (c.screenWidth, c.screenHeight, 0, "test.png");

	for (int i = 1; i <= c.screenWidth; i++) {
		for (int j = 1; j <= c.screenHeight; j++) {
			Ray r ((double) i, (double) j, c);

			Vector3 pixelColor = c.backgroundColor;;

			for (int s = 0; s < sceneObjects.size(); s++) {
				if (sceneObjects[s]->intersect(r)) {
					pixelColor = sceneObjects[s]->material.diffuseColor;
				}
			}

			png.plot(i, j, pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}

	png.close();

	return 0;
}
