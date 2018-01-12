
#pragma once

#include <vector>
#include <fstream>

#include "logger/easyloggingpp.h"
#include "json/json.hpp"
using json = nlohmann::json;

#include "Camera.h"
#include "SceneObject.h"
#include "Intersection.h"
#include "Ray.h"
#include "Light.h"

#include "Sphere.h" // only here for json loading, I should try to get rid of this
#include "Plane.h" // only here for json loading, I should try to get rid of this

class Scene {
public:
	Scene();
	Scene (std::string jsonPath);
		
	void setObjects(std::vector<SceneObject*> objects);
	void setLight(Light l);
	void setCamera(Camera c);
	
	std::vector<Intersection> trace(Ray r);
	void render();

public:
	double shadowBias = 1e-13;
	
	std::vector<SceneObject*> objects;
	Camera camera;
	Light light;
};