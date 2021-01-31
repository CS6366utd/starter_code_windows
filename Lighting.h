#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Lighting {

/*
 * TODO: Define lighting parameters
 */

	struct Direction_Light {
		/*
		* TODO: Define direct light parameters
		*/
	};


	struct Point_Light {
		/*
		* TODO: Define point light parameters
		*/
	};

public:

	Direction_Light direction_light;
	Point_Light point_light;

	Lighting() {}

	~Lighting() {}

	void init() 
	{
		/*
		* TODO: Init all lighting parameters
		*/
	};
};