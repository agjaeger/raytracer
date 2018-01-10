
/*
 * Hello World
 */
 
#include <pngwriter.h>
#include <iostream>

#include "Ray.h"
#include "Sphere.h"
#include "Vector3.h"

int main() {
	int screenWidth = 300;
	int screenHeight = 300;

	int fov = 90;
	
	Sphere s;
	s.transform.position = Vector3(0, 0, -5);
	s.radius = 1;
	s.color = Vector3(1, 0, 0);

	pngwriter png(screenWidth, screenHeight,0,"test.png");
	
	for (int i = 1; i <= screenWidth; i++) {
		for (int j = 1; j <= screenHeight; j++) {
			Ray r ((double) i, (double) j, screenWidth, screenHeight);
			
			if (s.intersect(r)) {
				png.plot(i, j, s.color.x, s.color.y, s.color.z); 
			} else {
				png.plot(i, j, 1, 0, 1);
			}
		}
	}
     
	png.close();
   
	return 0;
}
