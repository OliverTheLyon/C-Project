#version 330 core

layout(location=0) in vec2 vertPos;
layout(location=1) in vec3 color;

out vec3 colour;

void main(){
		gl_Position = vec4(vertPos, 0, 1);
		colour = color;
}
