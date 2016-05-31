#include <iostream>

#include <vector>

#define GLEW_STATIC 1
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

#include "Shape.h"
#include "Spline.h"
#include "Utils.h"
#include "CommonPolygon.h"

#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

int windowWidth = 800;
int windowHeight = 600;
float depth = 800;

GLFWwindow* window;
bool isRunning = false;
bool RotateCamera = false;
double OnClickMousePosX;
double OnClickMousePosY;

Cube* c;

std::vector<Spline> splineList;

void Draw()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Camera::GetCamera();

	Landmark::Draw();

	for (Spline s : splineList)
	{
		s.Draw();
	}

	c->Draw();

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

void MouseWheelFunc(GLFWwindow* window, double x, double y) {

	c->Scale += y * Camera::ZoomFactor;;
	c->SetScale(c->Scale);

	//glMatrixMode(GL_PROJECTION);
	//glLoadMatrixf(glm::value_ptr(glm::perspective(45.0f * Camera::ZoomFactor, (float)windowWidth / (float)windowHeight, 0.01f, 200.0f)));
}

void MouseMotionFunc(GLFWwindow* window, double x, double y)
{
	if(RotateCamera)
	{
		Camera::SetRot_X(Camera::AngleSpeed * -(OnClickMousePosX - x));
		Camera::SetRot_Y(Camera::AngleSpeed * (OnClickMousePosY - y));
		OnClickMousePosX = x;
		OnClickMousePosY = y;
	}
}

void KeyboardFunc(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (key)
	{
		case GLFW_KEY_W:
			Camera::Pos_Y += Camera::Speed;
			break;
		case GLFW_KEY_A:
			Camera::Pos_X += Camera::Speed;
			break;
		case GLFW_KEY_S:
			Camera::Pos_Y -= Camera::Speed;
			break;
		case GLFW_KEY_D:
			Camera::Pos_X -= Camera::Speed;
			break;
		case GLFW_KEY_V:
			Camera::Rot_X = 0.0f;
			Camera::Rot_Y = 0.0f;
			break;
	}
}

void MouseButtonFunc(GLFWwindow* window, int button, int action, int mods)
{
	float worldMouseX, worldMouseY, worldMouseZ;
	double mousePos_X, mousePos_Y;
	glfwGetCursorPos(window, &mousePos_X, &mousePos_Y);

	switch (button)
	{
		case(GLFW_MOUSE_BUTTON_1):
			if (action == GLFW_PRESS)
			{
				Utils::MouseScreenPosToWorldPos(mousePos_X, mousePos_Y, worldMouseX, worldMouseY, worldMouseZ);
				splineList[0].AddVertex(Point(worldMouseX, -2 * Camera::Pos_Y - worldMouseY, worldMouseZ + depth));
			}
			break;
		case(GLFW_MOUSE_BUTTON_2):
			if (action == GLFW_PRESS)
			{
				OnClickMousePosX = mousePos_X;
				OnClickMousePosY = mousePos_Y;
				RotateCamera = true;
			}
			else if(action == GLFW_RELEASE)
			{
				RotateCamera = false;
			}
			break;
	}
}

int main(int argc, char* argv)
{
	std::cout << "Manuel : " << std::endl;
	std::cout << " - zqsd pour bouger la caméra" << std::endl;
	std::cout << " - v pour remettre la caméra de face" << std::endl;
	std::cout << "--- FIN ---" << std::endl;


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
	glCullFace(GL_BACK);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;
	//glLoadMatrixf(glm::value_ptr(glm::perspective(45.0f * Camera::ZoomFactor, (float)windowWidth / (float)windowHeight, depth, -depth)));

	glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);
	glOrtho(-windowWidth, windowWidth, windowHeight, -windowHeight, depth, -depth);

	glfwSetScrollCallback(window, &MouseWheelFunc);
	glfwSetMouseButtonCallback(window, &MouseButtonFunc);
	glfwSetCursorPosCallback(window, &MouseMotionFunc);
	glfwSetKeyCallback(window, &KeyboardFunc);

	Spline s;
	splineList.push_back(s);

	c = new Cube(Point(0.0f, 0.0f, 0.0f), 100.0f);
	StartMainLoop();

	delete c;

	return 0;
}