
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

bool ReadFile(const char * file, string& out){
	
	ifstream f(file);

	bool ret = false;

	if(f.is_open()){
		string line;
		while(getline(f, line)){
			out.append(line);
			out.append("\n");

		}

		f.close();

		ret = true;
	}
	else{
		fprintf(stderr, "Provided file, %s, was not open\n", file);
		ret = false;
	}

	return ret;
}

GLuint LoadShaders(const char* vert_shader, const char * frag_shader){
	GLuint vert_ID = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag_ID = glCreateShader(GL_FRAGMENT_SHADER);

	string vert_code;
	ifstream VertexShaderStream(vert_shader, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		vert_code = sstr.str();
		VertexShaderStream.close();
	}
	else{
		fprintf(stderr, "Unable to open %s.\n", vert_shader);
		getchar();
		return 0;
	}

	string frag_code;
	ifstream FragStream(frag_shader, std::ios::in);
	if(FragStream.is_open()){
		stringstream sstr;
		sstr << FragStream.rdbuf();
		frag_code = sstr.str();
		FragStream.close();
	}

	GLint res = GL_FALSE;
	int loglen;

	char const * vert_src = vert_code.c_str();
	glShaderSource(vert_ID, 1, &vert_src, NULL);
	glCompileShader(vert_ID);

	glGetShaderiv(vert_ID, GL_COMPILE_STATUS, &res);
	glGetShaderiv(vert_ID, GL_INFO_LOG_LENGTH, &loglen);

	if(loglen > 0){
		std::vector<char> vert_error(loglen+1);
		glGetShaderInfoLog(vert_ID, loglen, NULL, &vert_error[0]);
		printf("%s\n", &vert_error[0]);
	}

	char const * frag_src = frag_code.c_str();
	glShaderSource(frag_ID, 1, &frag_src, NULL);
	glCompileShader(frag_ID);

	glGetShaderiv(frag_ID, GL_COMPILE_STATUS, &res);
	glGetShaderiv(frag_ID, GL_INFO_LOG_LENGTH, &loglen);

	if(loglen > 0){
		std::vector<char> frag_error(loglen+1);
		glGetShaderInfoLog(frag_ID, loglen, NULL, &frag_error[0]);
		printf("%s\n", &frag_error[0]);
	}
	
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, vert_ID);
	glAttachShader(ProgramID, frag_ID);
	glLinkProgram(ProgramID);

	glGetShaderiv(ProgramID, GL_COMPILE_STATUS, &res);
	glGetShaderiv(ProgramID, GL_INFO_LOG_LENGTH, &loglen);

	if(loglen > 0){
		std::vector<char> Program_error(loglen+1);
		glGetShaderInfoLog(ProgramID, loglen, NULL, &Program_error[0]);
		printf("%s\n", &Program_error[0]);
	}

	glDetachShader(ProgramID, vert_ID);
	glDetachShader(ProgramID, frag_ID);
	glDeleteShader(vert_ID);
	glDeleteShader(frag_ID);

	return ProgramID;

}
