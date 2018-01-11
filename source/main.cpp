
/*
 * Hello World
 */
 
#include <pngwriter.h>
#include <iostream>
#include <algorithm>
#include <vector>

#include "Ray.h"
#include "Sphere.h"
#include "Vector3.h"

struct Intersection {
	double distance;
	Sphere s;
};

bool compareIntersection(const Intersection &a, const Intersection &b) {
	return a.distance < b.distance;
}

int main() {
	Camera c;
	
	c.screenWidth = 600;
	c.screenHeight = 500;
	c.fov = 90;
	c.backgroundColor = Vector3(0.1, 1.0, 0.6);
	
	std::vector<Sphere> spheres = {
		Sphere(Transform(Vector3(0.0,0.0,-2.0)), Vector3(1.0,0.0,0.0), 1),
		Sphere(Transform(Vector3(1.0,-1.0,-5.0)), Vector3(1.0,1.0,1.0), 1),
		Sphere(Transform(Vector3(2.0,2.0,-5.0)), Vector3(1.0,0.4,0.0), 1)
	};

	pngwriter png (c.screenWidth, c.screenHeight, 0, "test.png");
	
	for (int i = 1; i <= c.screenWidth; i++) {
		for (int j = 1; j <= c.screenHeight; j++) {
			Ray r ((double) i, (double) j, c);
			
			Vector3 pixelColor = c.backgroundColor;;

			for (int s = 0; s < spheres.size(); s++) {
				if (spheres[s].intersect(r)) {
					pixelColor = spheres[s].color;
				}
			}
			
			png.plot(i, j, pixelColor.x, pixelColor.y, pixelColor.z);
		}
	}
     
	png.close();
   
	return 0;
}
