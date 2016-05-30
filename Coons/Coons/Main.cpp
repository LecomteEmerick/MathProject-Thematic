#include <iostream>

#include <vector>

#define GLEW_STATIC 1
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

#include "Spline.h"

#include "glm\gtc\matrix_transform.hpp"

int windowWidth = 800;
int windowHeight = 600;

float CameraVerticalAngle = 0.0f;
float CameraHorizontalAngle = 0.0f;

GLFWwindow* window;
bool isRunning = false;

std::vector<Spline> splineList;

double MousePosition_Y, MousePosition_X;

void Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glm::mat4 orientation;
	//orientation = glm::rotate(orientation, glm::radians(CameraVerticalAngle), glm::vec3(1, 0, 0));
	//orientation = glm::rotate(orientation, glm::radians(CameraHorizontalAngle), glm::vec3(0, 1, 0));

	//glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.01f, 100.0f);
	//glm::mat4 View = orientation * glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -10.0f));
	//glm::mat4 World = glm::mat4(1.0f);

	for (Spline s : splineList)
	{
		s.Draw();
	}

	glfwSwapBuffers(window);
}

void StartMainLoop()
{
	isRunning = true;
	while (isRunning)
	{
		glfwPollEvents();

		Draw();

		if (glfwWindowShouldClose(window))
			isRunning = false;
	}
	glfwTerminate();
}

void MouseMotionFunc(GLFWwindow* window, double x, double y)
{
	MousePosition_X = x;
	MousePosition_Y = y;
}

void MouseButtonFunc(GLFWwindow* window, int button, int action, int mods)
{
	splineList[0].AddVertex(Point(MousePosition_X, MousePosition_Y, 0.0f));
}

int main(int argc, char* argv)
{
	glfwInit();

	window = glfwCreateWindow(windowWidth, windowHeight, "Math Coons", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLenum error = glewInit();
	if (error != GL_NO_ERROR) {
		std::cout << error << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);

	// Change to the projection matrix, reset the matrix and set up orthagonal projection (i.e. 2D)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, 0, 1);

	glfwSetMouseButtonCallback(window, &MouseButtonFunc);
	glfwSetCursorPosCallback(window, &MouseMotionFunc);

	Spline s;
	splineList.push_back(s);

	StartMainLoop();

	return 0;
}