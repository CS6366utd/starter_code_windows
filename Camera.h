#pragma once

#include <algorithm> 

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ROTATE_X_UP,
	ROTATE_X_DOWN,
	ROTATE_Y_UP,
	ROTATE_Y_DOWN,
	ROTATE_Z_UP,
	ROTATE_Z_DOWN,
};

class Camera {
public:
	/*
	 * TODO: Define Camera parameters
	 */
	
	unsigned int width;
	unsigned int height;

	/*
	 * TODO: Initialize Camera parameters
	 */
	Camera(
		unsigned int width_ = 800,
		unsigned int height_ = 600
	)
	{
		this->width = width_;
		this->height = height_;
	}

	void init() {
		reset();
	};

	/*
	 * TODO: Implement camera reset
	 */
	void reset() {
	}

	/*
	 * TODO: Implement each movement
	 */
	void process_keyboard(Camera_Movement direction, GLfloat velocity)
	{
		if (direction == FORWARD) {

		}
		if (direction == BACKWARD) {

		}
		if (direction == LEFT) {

		}
		if (direction == RIGHT) {

		}
		if (direction == UP) {

		}
		if (direction == DOWN) {

		}
		if (direction == ROTATE_X_UP) {

		}
		if (direction == ROTATE_X_DOWN) {

		}
		if (direction == ROTATE_Y_UP) {

		}
		if (direction == ROTATE_Y_DOWN) {

		}
		if (direction == ROTATE_Z_UP) {

		}
		if (direction == ROTATE_Z_DOWN) {

		}
	}
};