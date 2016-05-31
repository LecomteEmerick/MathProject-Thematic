#include <iostream>

#include <vector>

#define GLEW_STATIC 1
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"

#include "Spline.h"
#include "Utils.h"

#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

int windowWidth = 800;
int windowHeight = 600;
int depth = 800;
int iteration = 0;

GLFWwindow* window;
bool isRunning = false;
bool RotateCamera = false;
double OnClickMousePosX;
double OnClickMousePosY;

std::vector<Spline> splineList;

void Draw()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Camera::GetCamera();

	Landmark::Draw();

	for (Spline s : splineList) {
		//s.chaikin();
		s.Draw();
	}

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

void MouseWheelFunc(GLFWwindow* window, double x, double y) {
	Camera::Pos_Z += y * Camera::Speed;
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
		case GLFW_KEY_C:
			for (int i = 0; i < splineList.size(); ++i) {
				splineList[i].chaikin(iteration);
			}			
			break;
		case GLFW_KEY_P:
			if (action == GLFW_PRESS)
			{
				iteration = ++iteration;
				std::cout << "Niveau d'iteration : " << iteration << "\n";
				for (int i = 0; i < splineList.size(); ++i) {
					splineList[i].chaikin(iteration);
				}
			}
			break;
		case GLFW_KEY_SEMICOLON:
			if (action == GLFW_PRESS)
			{
				iteration = --iteration;
				std::cout << "Niveau d'iteration : " << iteration << "\n";
				for (int i = 0; i < splineList.size(); ++i) {
					splineList[i].chaikin(iteration);
				}
			}
			break;
		case GLFW_KEY_X:
			if (action == GLFW_PRESS)
			{				
				for (int i = 0; i < splineList.size(); ++i) {
					splineList[i].coons();
				}
			}
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
				splineList[3].AddVertex(Point(worldMouseX, -2 * Camera::Pos_Y + windowHeight - worldMouseY, worldMouseZ + depth));
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
	std::cout << " - zqsd pour bouger la cam�ra" << std::endl;
	std::cout << " - v pour remettre la cam�ra de face" << std::endl;
	std::cout << " ################################################" << std::endl;
	std::cout << " #-------------------- CHAIKINS  ---------------#" << std::endl;
	std::cout << " ################################################" << std::endl;
	std::cout << " # - C pour appliquer l'algorithme--------------#" << std::endl;
	std::cout << " # - P pour ajouter un niveau d'incr�mentation--#" << std::endl;
	std::cout << " # - M pour r�duire un niveau d'incr�mentation--#" << std::endl;
	std::cout << " ################################################" << std::endl;
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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;

	glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);
	glOrtho(0, windowWidth, windowHeight, 0, depth, -depth);

	glfwSetScrollCallback(window, &MouseWheelFunc);
	glfwSetMouseButtonCallback(window, &MouseButtonFunc);
	glfwSetCursorPosCallback(window, &MouseMotionFunc);
	glfwSetKeyCallback(window, &KeyboardFunc);

	Spline s,u,v,n,click;
	s.AddVertex(new Point(50, 100, 0));
	s.AddVertex(new Point(100, 200, 0));
	s.AddVertex(new Point(200, 300, 0));
	s.AddVertex(new Point(300, 400, 0));
	/*---------------------------------*/
	u.AddVertex(new Point(50, 100, 0));
	u.AddVertex(new Point(100, 110, 0));
	u.AddVertex(new Point(200, 95, 0));
	u.AddVertex(new Point(300, 90, 0));
	/*---------------------------------*/
	v.AddVertex(new Point(300, 90, 0));
	v.AddVertex(new Point(320, 200, 0));
	v.AddVertex(new Point(410, 300, 0));
	v.AddVertex(new Point(520, 400, 0));
	/*---------------------------------*/
	n.AddVertex(new Point(300, 400, 0));
	n.AddVertex(new Point(380, 420, 0));
	n.AddVertex(new Point(450, 390, 0));
	n.AddVertex(new Point(520, 400, 0));
	/*---------------------------------*/
	splineList.push_back(s);
	splineList.push_back(u);
	splineList.push_back(v);
	splineList.push_back(n);

	StartMainLoop();

	return 0;
}