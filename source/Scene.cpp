
#include "Scene.h"

Scene::Scene () {}

Scene::Scene (std::string jsonPath) {
	LOG(INFO) << "Reading scene file located at" << " " << jsonPath;
	
	std::ifstream jsonStream (jsonPath);
	json jsonObject;
	jsonStream >> jsonObject;
	
	// Light
	light.direction = glm::dvec3 (
		jsonObject["scene"]["light"]["direction"][0],
		jsonObject["scene"]["light"]["direction"][1],
		jsonObject["scene"]["light"]["direction"][2]
	);
	
	light.color = glm::dvec3 (
		jsonObject["scene"]["light"]["color"][0],
		jsonObject["scene"]["light"]["color"][1],
		jsonObject["scene"]["light"]["color"][2]	
	);
	
	light.intensity = jsonObject["scene"]["light"]["intensity"];
	
	// Camera
	camera.fov = jsonObject["scene"]["camera"]["fov"];
	camera.screenSize.x = jsonObject["scene"]["camera"]["renderSize"][0];
	camera.screenSize.y = jsonObject["scene"]["camera"]["renderSize"][1];
	camera.backgroundColor = glm::dvec3(
		jsonObject["scene"]["camera"]["backgroundColor"][0],
		jsonObject["scene"]["camera"]["backgroundColor"][1],
		jsonObject["scene"]["camera"]["backgroundColor"][2]
	);
	
	// Scene Objects
	for (auto jsonSceneObject : jsonObject["scene"]["objects"]) {
		Material m;
		m.albedo = jsonSceneObject["material"]["albedo"];
		m.diffuseColor = glm::dvec3 (
			jsonSceneObject["material"]["diffuse"][0],
			jsonSceneObject["material"]["diffuse"][1],
			jsonSceneObject["material"]["diffuse"][2]
		);
		
		Transform t;
		t.position = glm::dvec3 (
			jsonSceneObject["transform"]["position"][0],
			jsonSceneObject["transform"]["position"][1],
			jsonSceneObject["transform"]["position"][2]			
		);
		t.rotation = glm::dvec3 (
			jsonSceneObject["transform"]["rotation"][0],
			jsonSceneObject["transform"]["rotation"][1],
			jsonSceneObject["transform"]["rotation"][2]			
		);
		t.scale = glm::dvec3 (
			jsonSceneObject["transform"]["scale"][0],
			jsonSceneObject["transform"]["scale"][1],
			jsonSceneObject["transform"]["scale"][2]			
		);
		
		if (jsonSceneObject["primitive"] == "sphere") {
			double r = jsonSceneObject["radius"];
			objects.push_back(new Sphere(t, m, r));
		} 
		
		else if (jsonSceneObject["primitive"] == "plane") {
			glm::dvec3 n = glm::dvec3 (
				jsonSceneObject["normal"][0],
				jsonSceneObject["normal"][1],
				jsonSceneObject["normal"][2]
			);
			objects.push_back(new Plane(t, m, n));
		}
	}
}

std::vector<Intersection>
Scene::trace (
	Ray r,
	Intersection &closestOut
) {
	std::vector<Intersection> intersections;
	
	Intersection closest (1000000.0, new Sphere());
	
	for (int s = 0; s < this->objects.size(); s++) {
		double dist;
		if (this->objects[s]->intersect(r, dist)) {
			Intersection intersection (
				dist,
				this->objects[s]
			);
			
			if (intersection.distance < closest.distance) {
				closest.distance = intersection.distance;
				closest.s = this->objects[s];
			}
			
			intersections.push_back(intersection);
		}
	}
	
	closestOut = closest;
	
	return intersections;
}

void
Scene::setObjects (std::vector<SceneObject*> objects) {
	this->objects = objects;
}

void
Scene::setLight (Light l) {
	this->light = l;
}

void
Scene::setCamera (Camera c) {
	this->camera = c;
}