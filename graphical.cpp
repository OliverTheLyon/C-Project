

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <stdio.h>
#include "convenience.hpp"
#include "SOIL.h"

using namespace std;
using namespace glm;

float width = 768;
float height = 768;

mat4 model;
mat4 view;
mat4 projection;
GLFWwindow * window;

void Exit(){
	glfwTerminate();
}

void Pause(){
	do{
		if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
			Exit();
		}
	}
	while(glfwGetKey(window, GLFW_KEY_F) != GLFW_PRESS);
}

void Top_lefts(int** board, int side_length, vector<vec2> &top_lefts, 
		vector<vec3> &colours){
	float length = 2.0f/side_length;
	for(int i = 0; i < side_length; i += 1){
		for(int j = 0; j < side_length; j += 1){
			top_lefts.push_back(vec2(
						(i*length) -1 , 
						1-(j*length)
						));
			int val = board[i][j];
			colours.push_back(vec3(val, val, val));
		}
	}
}

void Prepare_vertices(int side_length, vector<vec2> &top_lefts, vector<vec2> &verts,
		vector<unsigned short> &inds){
	float length = 2.0f/side_length;
	float space = 0.025 * length;

	for(unsigned short i = 0; i < top_lefts.size(); i += 1){

		vec2 square = top_lefts[i];
		vec2 v_top_left = vec2(square.x + space, square.y - space);
		vec2 v_top_right = vec2(square.x + length - space , square.y - space);
		vec2 v_bottom_left = vec2(square.x + space, square.y - length + space );
		vec2 v_bottom_right = vec2(square.x + length - space, square.y - length + space);

		verts.push_back(v_bottom_left);
		verts.push_back(v_top_left);
		verts.push_back(v_bottom_right);
		verts.push_back(v_top_right);

		unsigned short start_i = i*4;
		inds.push_back(start_i);
		inds.push_back(start_i + 1);
		inds.push_back(start_i + 2);
		inds.push_back(start_i + 1);
		inds.push_back(start_i + 3);
		inds.push_back(start_i + 2);
	}
}

void Draw(int** board, int side_length){
	vector<vec2> top_lefts;
	vector<vec3> cols;
	vector<vec2> verts;
	vector<unsigned short> inds;

	Top_lefts(board, side_length, top_lefts, cols);
	Prepare_vertices(side_length, top_lefts, verts, inds);

	GLuint VBO;
	glGenVertexArrays(1, &VBO);
	glBindVertexArray(VBO);

	// create and bind buffers
	GLuint vertices;
	glGenBuffers(1, &vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vertices);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(vec2), 
			&verts[0], GL_STATIC_DRAW);

	GLuint indices;
	glGenBuffers(1, &indices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size() * sizeof(unsigned short),
			&inds[0], GL_STATIC_DRAW);

	GLuint colours;
	glGenBuffers(1, &colours);
	glBindBuffer(GL_ARRAY_BUFFER, colours);
	glBufferData(GL_ARRAY_BUFFER, cols.size() * sizeof(vec3), &cols[0], 
			GL_STATIC_DRAW);
	
	GLuint shaderID = LoadShaders("shader.vs", "shader.fs");
	
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderID);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertices);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colours);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);


	glDrawElements(GL_TRIANGLES, inds.size(), GL_UNSIGNED_SHORT, 0);

	glDisableVertexAttribArray(0);

	glfwSwapBuffers(window);
	glfwPollEvents();

	Pause();

}

void Setup(int argc, char** argv){

	if(!glfwInit()){
		fprintf(stderr, "Failed to init GLFW\n");
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Des Spiel die Lebens", NULL, NULL);
	if(NULL == window){
		fprintf(stderr, "Failed to create GLFW window.");
		fprintf(stderr, "If you have an intel GPU, they are not 3.3 compatible.");
		return;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if(glewInit() != GLEW_OK){
		fprintf(stderr, "Failed to init GLEW\n");
		return;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(1,1,1, 0);
	
}

