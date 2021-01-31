#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object
{
public:
	struct Vertex {
		// Position
		glm::vec3 Position;
		// Normal
		glm::vec3 Normal;
		// TexCoords
		glm::vec2 TexCoords;
	};

	struct Vertex_Index {
		int pos_idx;
		int normal_idx;
		int texcoord_idx;
	};

	struct Face_Index {
		Vertex_Index vertex[3];
	};

	// veo and vao vector
	std::vector<Vertex> vao_vertices;
	std::vector<unsigned int> veo_indices;

	// obj original data vector
	std::vector<glm::vec3> ori_positions;
	std::vector<glm::vec3> ori_normals;
	std::vector<glm::vec2> ori_texcoords;

	// obj face index vector
	std::vector<Face_Index> indexed_faces;

	glm::vec3 obj_center;

	glm::vec3 max_bound = glm::vec3(INT_MIN);
	glm::vec3 min_bound = glm::vec3(INT_MAX);

	glm::vec4 obj_color = glm::vec4(0.7, 0.7, 0.7, 1.0);
	GLfloat shininess = 32.0f;

	std::string m_obj_path;
	std::string obj_name;

	GLuint vao, vbo;

public:
	Object(std::string obj_path) { 
		this->m_obj_path = obj_path; 
		load_obj(this->m_obj_path);
	};

	~Object() {};

	void load_obj(std::string obj_path)
	{
		int path_str_length = obj_path.size();
		std::string suffix = obj_path.substr(path_str_length - 3, path_str_length);

		if (suffix == "obj") {
			this->vao_vertices.clear();
			this->veo_indices.clear();
			this->indexed_faces.clear();

			this->ori_positions.clear();
			this->ori_normals.clear();
			this->ori_texcoords.clear();

			std::ifstream ifs;
			// Store original data vector
			try {
				ifs.open(obj_path);
				std::string one_line;
				while (getline(ifs, one_line)) {
					std::stringstream ss(one_line);
					std::string type;
					ss >> type;
					if (type == "v") {
						glm::vec3 vert_pos;
						ss >> vert_pos[0] >> vert_pos[1] >> vert_pos[2];
						this->ori_positions.push_back(vert_pos);
					}
					else if (type == "vt") {
						glm::vec2 tex_coord;
						ss >> tex_coord[0] >> tex_coord[1];
						this->ori_texcoords.push_back(tex_coord);
					}
					else if (type == "vn") {
						glm::vec3 vert_norm;
						ss >> vert_norm[0] >> vert_norm[1] >> vert_norm[2];
						this->ori_normals.push_back(vert_norm);
					}
					else if (type == "f") {
						Face_Index face_idx;
						// Here we only accept face number 3
						for (int i = 0; i < 3; i++) {
							std::string s_vertex;
							ss >> s_vertex;
							int pos_idx = -1;
							int tex_idx = -1;
							int norm_idx = -1;
							sscanf(s_vertex.c_str(), "%d/%d/%d", &pos_idx, &tex_idx, &norm_idx);
							// We have to use index -1 because the obj index starts at 1
							// Incorrect input will be set as -1
							face_idx.vertex[i].pos_idx = pos_idx > 0 ? pos_idx - 1 : -1;
							face_idx.vertex[i].texcoord_idx = tex_idx > 0 ? tex_idx - 1 : -1;
							face_idx.vertex[i].normal_idx = norm_idx > 0 ? norm_idx - 1 : -1;
						}
						indexed_faces.push_back(face_idx);
					}
				}
			}
			catch (const std::exception&) {
				std::cout << "Error: Obj file cannot be read\n";
			}

			/*
			 * TODO: Retrieve data from index and assign to vao and veo
			 */
		}
	};
};