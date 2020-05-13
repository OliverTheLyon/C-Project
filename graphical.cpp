

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <Eigen/Dense>

using namespace Eigen;

static void RenderSceneCB(){
	glClear(GL_COLOR_BUFFER_BIT); // clean up scene
	glutSwapBuffers(); 
}

static void InitializeGlutCallbacks(){
	glutDisplayFunc(RenderSceneCB); // setup event callback for display
}


void setup(int argc, char** argv){

	glutInit(&argc, argv); // startup the glut system
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // enable double buffering
	// and rgba colour
	glutInitWindowSize(1024, 768); // set window dimensions and position
	glutInitWindowPosition(100,100);
	glutCreateWindow("Des spiel die Lebens"); // give window a title

	InitializeGlutCallbacks();

}




int main(int argc, char** argv){

	setup(argc, argv); 

	glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // set background

	glutMainLoop(); // hand control over to glut

	return 0;
}
