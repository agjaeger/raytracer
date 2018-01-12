
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
#include "MathUtils.h"

#include "Scene.h"
#include "Intersection.h"
#include "SceneObject.h"
#include "Plane.h"
#include "Sphere.h"

#include "Light.h"

Vector3
getColor (
	Scene scene,
	Ray primaryRay,
	Intersection intersection
) {
	Vector3 hitPoint = primaryRay.origin + (primaryRay.direction * intersection.distance);
	Vector3 surfaceNormal = intersection.s->surfaceNormal(hitPoint);
	Vector3 directionToLight = scene.light.direction.normalize() * -1.0;
	
	Ray shadowRay (
		hitPoint + (surfaceNormal * scene.shadowBias), 
		directionToLight
	);
	
	std::vector<Intersection> intersections = scene.trace(shadowRay);
	bool inLight = intersections.empty();
	
	double lightIntensity = 0.0;
	
	if (inLight)
		lightIntensity = scene.light.intensity;
		
	double lightPower = (Vector3::dot(surfaceNormal, directionToLight)) * lightIntensity;	
	double lightReflected = intersection.s->material.albedo / MathUtils::PI;
	
	Vector3 color = intersection.s->material.diffuseColor;
	color = color * scene.light.color;
	color = color * lightPower;
	color = color * lightReflected;
	
	color.x = std::max(0.0, std::min(color.x, 1.0));
	color.y = std::max(0.0, std::min(color.y, 1.0));
	color.z = std::max(0.0, std::min(color.z, 1.0));

	return color;	
}

int
main () {
	Camera c;
	c.screenWidth = 600;
	c.screenHeight = 300;
	c.fov = 90;
	c.backgroundColor = Vector3(0.1, 1.0, 0.6);

	Light l;
	l.direction = Vector3(0.5, 0.5, -1.0);
	l.color = Vector3(1.0, 1.0, 1.0);
	l.intensity = 8;

	Material sphere1;
	sphere1.diffuseColor = Vector3(0.1, 0.0, 1.0);
	sphere1.albedo = 0.9;

	Material sphere2;
	sphere2.diffuseColor = Vector3(1.0, 0.0, 0.5);
	sphere2.albedo = 0.9;

	Material sphere3;
	sphere3.diffuseColor = Vector3(1.0, 1.0, 0.0);
	sphere3.albedo = 0.9;

	Material plane;
	plane.diffuseColor = Vector3(0.4, 0.4, 0.4);
	plane.albedo = 0.9;

	std::vector<SceneObject*> sceneObjects = {
		new Plane(Transform(Vector3(0.0,3.0,-5.0)), Vector3(0.0, 0.75, 0.0), plane),
		new Sphere(Transform(Vector3(0.0,0.0,-2.0)), sphere1, 1),
		new Sphere(Transform(Vector3(1.0,-1.0,-5.0)), sphere2, 1),
		new Sphere(Transform(Vector3(2.0,2.0,-5.0)), sphere3, 1)
	};

	Scene scene;
	scene.objects = sceneObjects;
	scene.light = l;
	scene.camera = c;

	pngwriter png (c.screenWidth, c.screenHeight, 0, "test.png");

	for (int i = 1; i <= c.screenWidth; i++) {
		for (int j = 1; j <= c.screenHeight; j++) {
			Ray r = Ray::createPrimaryRay((double) i, (double) j, c);
			std::vector<Intersection> intersections = scene.trace(r);
			Vector3 pixelColor = c.backgroundColor;
						
			for (Intersection intersection : intersections) {
				pixelColor = getColor(scene, r, intersection);
			}

			png.plot(i, j, pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}

	png.close();

	return 0;
}