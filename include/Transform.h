
#pragma once

#include <vector>

class Transform {
public:
	Transform();
	
	Transform(
		std::vector<double> position, 
		std::vector<double> rotation, 
		std::vector<double> scale
	);
	
	bool setPosition(std::vector<double> position);
	bool setRotation(std::vector<double> rotation);
	bool setScale(std::vector<double> scale);
	
	std::vector<double> getPosition();
	std::vector<double> getRotation();
	std::vector<double> getScale();
	
private:
	std::vector<double> position;
	std::vector<double> rotation;
	std::vector<double> scale;
};
