
#include "Scene.h"

Scene::Scene () {}

Scene::Scene (
	int w, 
	int h, 
	double fov
) {
	this->renderWidth = w;
	this->renderHeight = h;
	this->fov = fov;
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