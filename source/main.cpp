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
	Scene scene ("scene.json");

	pngwriter png (scene.camera.screenWidth, scene.camera.screenHeight, 0, "test.png");

	for (int i = 1; i <= scene.camera.screenWidth; i++) {
		for (int j = 1; j <= scene.camera.screenHeight; j++) {
			Ray r = Ray::createPrimaryRay((double) i, (double) j, scene.camera);
			std::vector<Intersection> intersections = scene.trace(r);
			Vector3 pixelColor = scene.camera.backgroundColor;
						
			for (Intersection intersection : intersections) {
				pixelColor = getColor(scene, r, intersection);
			}

			png.plot(i, j, pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}

	png.close();

	return 0;
}