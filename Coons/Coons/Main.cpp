#include <iostream>

#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

int windowWidth = 800;
int windowHeight = 600;

GLFWwindow* window;

int main(int argc, char* argv)
{
	glfwInit();

	window = glfwCreateWindow(windowWidth, windowHeight, "Math Coons", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	system("pause");
	return 0;
}