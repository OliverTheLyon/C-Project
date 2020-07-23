#ifndef GRAPHICAL
#define GRAPHICAL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <stdio.h>
#include "convenience.hpp"

#endif
/**
 * A function to exit the graphical system
 * Pre-conditions: Setup has been run and the window created has not been exited
 * Post-conditions: The opengl session is exited
 * Return: true on finishing
 */
bool Exit();

/*
 * A function to wait for the user to press f or q
 * Pre-conditions: Setup has been run, and the Draw call has been run at least
 * once
 * Post-conditions: Control is returned to the backend code
 * Return: true on finishing
 */
bool Pause();

/* 
 * A funciton to populate an array of top left coordinates and colours for drawing
 * Pre-conditions: board and side length are not null, and top_lefts and colours
 * are empty, and Draw has been called at least once.
 * Param board: an int** to a board of size nxn where n is given by side_length
 * Param side_length: the 'square root' of the board, i.e. one side length of the
 * square defined by the board, must only be 0 if the board is of size 0, must be
 * positive
 * Param top_lefts: a vector which holds vec2s defined by glm, to be empty when 
 * handed in
 * Param colours: a vector which holds vec3s defined by glm, to be empty when
 * handed in
 * Post-conditions: top_lefts and colours are populated with vec2s and vec3s
 * respectively
 * Return: nothing finishing
 */
void Top_lefts(int** board, 
		int side_length,
	   	vector<vec2> &top_lefts, 
		vector<vec3> &colours);

/*
 * A function to obtain and index the vertices of the squares to be drawn with a 
 * space of 5% between each square.
 * Pre-conditions: side length and top_lefts are not null, verts and inds are both
 * empty, and Draw has been called at least once
 * Param side_length: the 'square root' (side length of the square) of the board
 * referenced previously
 * Param top_lefts: a vector filled with vec2s which define the top left verticy,
 * prior to removal of spacing value, of each square
 * Param verts: a vector which stores vec2s defined by glm, which represent all
 * 4 verticies of all of the squares. Used for returning the vertices, and should
 * be empty when handed in
 * Param inds: a vector which stores sequences of unsigned shorts for the purposes
 * of indexed drawing. Used for returning, and should be handed in empty
 * Post-conditions: verts and inds are filled with a sequence of vec2s and
 * unsigned shorts respectively
 * Return: nothing
 */
void Prepare_vertices(
		int side_length, 
		vector<vec2> &top_lefts, 
		vector<vec2> &verts,
		vector<vec3> i_cols,
		vector<unsigned short> &inds,
		vector<vec3> &cols);

/* 
 * A function which draws squares to a screen in colour or greyscale depending on
 * the board handed in.
 * Pre-conditions: Setup has been called, and board and side_length are not null
 * Param board: an int** which holds a square set of ints of size nxn (where n is
 * defined by side_length)
 * Param side_length: the 'square root' of the board, i.e. the side length of the
 * board.
 * Post-conditions: the board in its current state is drawn to the screen, and
 * Pause is called.
 * Return: true on finishing
 */
bool Draw(int** board, int side_length);

/* 
 * A function which handles the necessary boilerplate for setting up an opengl
 * window.
 * Pre-conditions: None
 * Post-conditions: An opengl window is created, on failure an error message is 
 * printed out, pointing to the relevant issue
 * Returns: true on successful window creation, false on some issue stoping a 
 * window from being created
 */
bool Setup();

