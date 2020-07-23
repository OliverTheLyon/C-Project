#ifndef CON
#define CON
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#endif

using namespace glm;
using namespace std;

bool ReadFile(const char* file, string& out);

GLuint LoadShaders(const char* vert_shader, const char * frag_shader);
