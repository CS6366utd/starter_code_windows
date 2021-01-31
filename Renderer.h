#pragma once

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <nanogui/nanogui.h>

#include "Shader.h"
#include "Camera.h"
#include "Object.h"
#include "Lighting.h"


class Renderer
{
public:
	GLFWwindow* m_window;

	static Camera* m_camera;
	// static Lighting* m_lightings;

	static nanogui::Screen* m_nanogui_screen;

	// std::vector<Object> obj_list;

	glm::vec4 background_color = glm::vec4(0.0,0.0,0.0,0.0);

	bool is_scene_reset = true;

	/*
	 * TODO: Define model name here.
	 * 
	 * You can also import CLI11 (https://github.com/CLIUtils/CLI11)
	 * to load model from command line		 
	 */
	std::string model_name;

	GLfloat delta_time = 0.0;
	GLfloat last_frame = 0.0;

	static bool keys[1024];

public:
	Renderer();
	~Renderer();

	void run();

private:

	void init();
	void nanogui_init(GLFWwindow* window);
	
	void display(GLFWwindow* window);
	
	void load_models();
	void draw_scene(Shader& shader);

	void camera_move();

	void draw_object(Shader& shader, Object& object);

	void bind_vaovbo(Object &cur_obj);

	void setup_uniform_values(Shader& shader);
	void scene_reset();
};

