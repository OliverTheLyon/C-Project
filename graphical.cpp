

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include <stdio.h>

using namespace glm;

GLuint VBO; // vertex buffer object

static void RenderSceneCB(){
	glClear(GL_COLOR_BUFFER_BIT); // clean up scene (clear frame buffer)

	glEnableVertexAttribArray(0);
	// Enable index for attribute flags

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Bind the VBO so the GPU knows about it
	

	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 0, 0);
	// Set flags for the stytem call for drawing
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// System call to draw the points
	
	glDisableVertexAttribArray(0);
	// Disable the index for the attribute array

	glutSwapBuffers(); 
}

static void InitializeGlutCallbacks(){
	glutDisplayFunc(RenderSceneCB); // setup event callback for display
}


static void CreateVertexBuffer(){
	vec3 vertices[3];
	vertices[0] = vec3( -.5, -.5,  0);
	vertices[1] = vec3(   0, -.5,  0);
	vertices[2] = vec3(   0,   0,  0);
	// setup vertices and store in an array

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Generate and bind the handle for the vertex buffer

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// bind the data to the vbo

}

void setup(int argc, char** argv){

	glutInit(&argc, argv); // startup the glut system
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // enable double buffering
	// and rgba colour
	glutInitWindowSize(1024, 768); // set window dimensions and position
	glutInitWindowPosition(100,100);
	glutCreateWindow("Des spiel die Lebens"); // give window a title

	InitializeGlutCallbacks();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLenum res = glewInit(); // As our OS prof says, always check
	// sys call returns
	if(GLEW_OK != res){
		fprintf(stderr, "Failed to initialize glew; %s\n", 
				glewGetErrorString(res));
	}
	
	CreateVertexBuffer();

}


int main(int argc, char** argv){

	setup(argc, argv); 

	glutMainLoop(); // hand control over to glut

	return 0;
}
