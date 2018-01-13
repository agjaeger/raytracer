#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 
#include <time.h>

#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "pngwriter/pngwriter.h"
#include "logger/easyloggingpp.h"
INITIALIZE_EASYLOGGINGPP

#include "Material.h"
#include "Ray.h"

#include "Scene.h"
#include "Intersection.h"
#include "SceneObject.h"
#include "Plane.h"
#include "Sphere.h"
#include "Light.h"

glm::dvec3
getColor (
	Scene scene,
	Ray primaryRay,
	Intersection intersection
) {
	glm::dvec3 hitPoint = primaryRay.origin + (primaryRay.direction * intersection.distance);
	glm::dvec3 surfaceNormal = intersection.s->surfaceNormal(hitPoint);
	glm::dvec3 directionToLight = glm::normalize(scene.light.direction) * -1.0;
	
	Ray shadowRay (
		hitPoint + (surfaceNormal * scene.shadowBias), 
		directionToLight
	);
	
	std::vector<Intersection> intersections = scene.trace(shadowRay);
	bool inLight = intersections.empty();
	
	double lightIntensity = 0.0;
	
	if (inLight)
		lightIntensity = scene.light.intensity;
		
	double lightPower = (glm::dot(surfaceNormal, directionToLight)) * lightIntensity;	
	double lightReflected = intersection.s->material.albedo / glm::pi<double>();
	
	glm::dvec3 color = intersection.s->material.diffuseColor;
	color = color * scene.light.color;
	color = color * lightPower;
	color = color * lightReflected;
	
	color.x = std::max(0.0, std::min(color.x, 1.0));
	color.y = std::max(0.0, std::min(color.y, 1.0));
	color.z = std::max(0.0, std::min(color.z, 1.0));

	return color;	
}

std::string versionString = "v0.0.1"; 

int
main () {
	clock_t appStartTime;
	appStartTime = clock();
	
	LOG(INFO) << "Alex's Raytracer" << " " << versionString;

	Scene scene ("scene.json");
	
	pngwriter png (scene.camera.screenWidth, scene.camera.screenHeight, 0, "test.png");

	for (int i = 1; i <= scene.camera.screenWidth; i++) {
		for (int j = 1; j <= scene.camera.screenHeight; j++) {
			Ray r = Ray::createPrimaryRay((double) i, (double) j, scene.camera);
			std::vector<Intersection> intersections = scene.trace(r);
			glm::dvec3 pixelColor = scene.camera.backgroundColor;
						
			for (Intersection intersection : intersections) {
				pixelColor = getColor(scene, r, intersection);
			}

			png.plot(i, j, pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}

	png.close();

	clock_t appDeltaTime = clock() - appStartTime;
	LOG(INFO) << "Application Run Length:" << " " << (float) appDeltaTime / CLOCKS_PER_SEC << " " << "seconds";

	return 0;
}