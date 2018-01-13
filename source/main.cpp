#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 
#include <time.h>

#include "pngwriter/pngwriter.h"

#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "logger/easyloggingpp.h"
INITIALIZE_EASYLOGGINGPP

#include "PNGRenderer.h"
#include "OpenGLRenderer.h"

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
	
	Intersection closest;
	std::vector<Intersection> intersections = scene.trace(shadowRay, closest);
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
	
	std::vector<float> pixels; 
	for (int j = 0; j < scene.camera.screenSize.y; j++) {
		for (int i = 0; i < scene.camera.screenSize.x; i++) {
			Ray r = Ray::createPrimaryRay((double) i, (double) j, scene.camera);
			glm::dvec3 pixelColor = scene.camera.backgroundColor;
			
			Intersection closest;
			std::vector<Intersection> intersections = scene.trace(r, closest);
						
			for (Intersection intersection : intersections) {
				pixelColor = getColor(scene, r, intersection);
			}
	
			if (closest.distance >= 0 && closest.distance < 900000.0)
				pixelColor = getColor(scene, r, closest);

			pixels.push_back(pixelColor.x);
			pixels.push_back(pixelColor.y);
			pixels.push_back(pixelColor.z);
		}
	}
	
	float* pixelData = pixels.data();
	
	//~ PNGRenderer pngRenderer (
		//~ glm::vec2(scene.camera.screenSize.x, scene.camera.screenSize.y), 
		//~ "test.png"
	//~ );
	//~ pngRenderer.render(pixelData);
	//~ pngRenderer.close();
	
	clock_t appDeltaTime = clock() - appStartTime;
	LOG(INFO) << "Application Run Length:" << " " << (float) appDeltaTime / CLOCKS_PER_SEC << " " << "seconds";

	//~ glm::vec2 screenSize (1920, 1080);
	//~ glm::vec2 textureSize (1920, 1080);

	//~ OpenGLRenderer oglRenderer (screenSize, "customApp");
		
	//~ while (!glfwWindowShouldClose(oglRenderer.window)) {	
		//~ oglRenderer.render(pixelData, textureSize);
	//~ }
	


	return 0;
}