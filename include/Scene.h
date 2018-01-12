
#pragma once

#include <vector>

#include "Camera.h"
#include "SceneObject.h"
#include "Intersection.h"
#include "Ray.h"
#include "Light.h"

class Scene {
public:
	Scene();
	Scene(int w, int h, double fov);
		
	void setObjects(std::vector<SceneObject*> objects);
	void setLight(Light l);
	void setCamera(Camera c);
	
	std::vector<Intersection> trace(Ray r);
	void render();
	
public:
	int renderWidth;
	int renderHeight;
	double fov;
	double shadowBias = 1e-13;
	Camera camera;
	
	std::vector<SceneObject*> objects;
	Light light;
};