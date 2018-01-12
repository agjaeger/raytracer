
#include "Scene.h"

Scene::Scene () {}

Scene::Scene (std::string jsonPath) {
	std::ifstream jsonStream (jsonPath);
	json jsonObject;
	jsonStream >> jsonObject;
	
	// Light
	light.direction = Vector3(
		jsonObject["scene"]["light"]["direction"][0],
		jsonObject["scene"]["light"]["direction"][1],
		jsonObject["scene"]["light"]["direction"][2]
	);
	
	light.color = Vector3(
		jsonObject["scene"]["light"]["color"][0],
		jsonObject["scene"]["light"]["color"][1],
		jsonObject["scene"]["light"]["color"][2]	
	);
	
	light.intensity = jsonObject["scene"]["light"]["intensity"];
	
	// Camera
	camera.fov = jsonObject["scene"]["camera"]["fov"];
	camera.screenWidth = jsonObject["scene"]["camera"]["renderSize"][0];
	camera.screenHeight = jsonObject["scene"]["camera"]["renderSize"][1];
	camera.backgroundColor = Vector3(
		jsonObject["scene"]["camera"]["backgroundColor"][0],
		jsonObject["scene"]["camera"]["backgroundColor"][1],
		jsonObject["scene"]["camera"]["backgroundColor"][2]
	);
	
	// Scene Objects
	for (auto jsonSceneObject : jsonObject["scene"]["objects"]) {
		Material m;
		m.albedo = jsonSceneObject["material"]["albedo"];
		m.diffuseColor = Vector3 (
			jsonSceneObject["material"]["diffuse"][0],
			jsonSceneObject["material"]["diffuse"][1],
			jsonSceneObject["material"]["diffuse"][2]
		);
		
		Transform t;
		t.position = Vector3(
			jsonSceneObject["transform"]["position"][0],
			jsonSceneObject["transform"]["position"][1],
			jsonSceneObject["transform"]["position"][2]			
		);
		t.rotation = Vector3(
			jsonSceneObject["transform"]["rotation"][0],
			jsonSceneObject["transform"]["rotation"][1],
			jsonSceneObject["transform"]["rotation"][2]			
		);
		t.scale = Vector3(
			jsonSceneObject["transform"]["scale"][0],
			jsonSceneObject["transform"]["scale"][1],
			jsonSceneObject["transform"]["scale"][2]			
		);
		
		if (jsonSceneObject["primitive"] == "sphere") {
			double r = jsonSceneObject["radius"];
			objects.push_back(new Sphere(t, m, r));
		} 
		
		else if (jsonSceneObject["primitive"] == "plane") {
			Vector3 n = Vector3(
				jsonSceneObject["normal"][0],
				jsonSceneObject["normal"][1],
				jsonSceneObject["normal"][2]
			);
			objects.push_back(new Plane(t, m, n));
		}
	}
	
}

std::vector<Intersection>
Scene::trace (Ray r) {
	std::vector<Intersection> intersections;
	
	for (int s = 0; s < this->objects.size(); s++) {
		double dist;
		if (this->objects[s]->intersect(r, dist)) {
			Intersection intersection;
			intersection.distance = dist;
			intersection.s = this->objects[s];
								
			intersections.push_back(intersection);
		}
	}
	
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