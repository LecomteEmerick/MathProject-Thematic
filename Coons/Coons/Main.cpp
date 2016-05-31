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
#include "SplineManager.h"

#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

#define SPLINE_DEBUG

int windowWidth = 800;
int windowHeight = 600;
int depth = 800;
int iteration = 1;

GLFWwindow* window;
bool isRunning = false;
bool RotateCamera = false;
double OnClickMousePosX;
double OnClickMousePosY;

Cube* c;

SplineManager splineManager;

void Draw()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Camera::GetCamera();

	Landmark::Draw();

	splineManager.DrawSpline();

	if (c != nullptr)
	{
		std::vector<Point> barycenters;
 		c->Draw();
		//barycenters.push_back(c->F1.GetBarycentre());
		//barycenters.push_back(c->F2.GetBarycentre());
		//barycenters.push_back(c->F3.GetBarycentre());
		barycenters.push_back(c->F4.GetBarycentre());
		barycenters.push_back(c->F5.GetBarycentre());
		barycenters.push_back(c->F6.GetBarycentre());

		glPointSize(10.0f);
		glBegin(GL_POINTS);

		for (int i = 0; i < barycenters.size(); ++i)
		{
			glColor3f(barycenters[i]._Color._Red, barycenters[i]._Color._Green, barycenters[i]._Color._Blue);
			glVertex3f(barycenters[i]._x, barycenters[i]._y, barycenters[i]._z);
		}

		glEnd();
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

	c->SetScale(y * Camera::ZoomFactor);

	//glMatrixMode(GL_PROJECTION);
	//glLoadMatrixf(glm::value_ptr(glm::perspective(45.0f * Camera::ZoomFactor, (float)windowWidth / (float)windowHeight, 0.01f, 200.0f)));
}

void MouseMotionFunc(GLFWwindow* window, double x, double y)
{
	if(RotateCamera)
	{
		Camera::SetRot_X(Camera::AngleSpeed * -(OnClickMousePosX - x));
		Camera::SetRot_Y(Camera::AngleSpeed * -(OnClickMousePosY - y));
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
			splineManager.DoCheckInForAllSpline(iteration);		
			break;
		case GLFW_KEY_P:
			if (action == GLFW_PRESS && iteration < 15)
			{
				iteration = ++iteration;
				std::cout << "Niveau d'iteration : " << iteration << "\n";
				splineManager.DoCheckInForAllSpline(iteration);
			}
			break;
		case GLFW_KEY_SEMICOLON:
			if (action == GLFW_PRESS && iteration > 1)
			{
				iteration = --iteration;
				std::cout << "Niveau d'iteration : " << iteration << "\n";
				splineManager.DoCheckInForAllSpline(iteration);
			}
			break;
		case GLFW_KEY_X:
			if (action == GLFW_PRESS)
			{	
				splineManager.DoCheckInForAllSpline(iteration);
			}
			break;
		case GLFW_KEY_KP_ADD:
			if (action == GLFW_PRESS)
			{
				splineManager.SelectSpline(1);
			}
			break;
		case GLFW_KEY_KP_SUBTRACT:
			if (action == GLFW_PRESS)
			{
				splineManager.SelectSpline(-1);
			}
			break;
		case GLFW_KEY_O:
			if (action == GLFW_PRESS)
			{
				splineManager.CreateSpline();
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
				splineManager.SplineManagerAddPointToCurrentSpline(Point(worldMouseX, -2 * Camera::Pos_Y - worldMouseY, worldMouseZ + depth));
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
	std::cout << " - ZQSD pour bouger la camera" << std::endl;
	std::cout << " - V pour remettre la camera de face" << std::endl;
	std::cout << " ################################################" << std::endl;
	std::cout << " #-------------------- CHAIKINS  ---------------#" << std::endl;
	std::cout << " ################################################" << std::endl;
	std::cout << " # - C pour appliquer l algorithme (Compute)----#" << std::endl;
	std::cout << " # - P pour ajouter un niveau d incrementation--#" << std::endl;
	std::cout << " # - M pour reduire un niveau d incrementation--#" << std::endl;
	std::cout << " # - O pour creer un nouvelle spline -----------#" << std::endl;
	std::cout << " # - O pour creer un nouvelle spline -----------#" << std::endl;
	std::cout << " # - keypad + changer de spline courante -------#" << std::endl;
	std::cout << " # - keypad - changer de spline courante -------#" << std::endl;
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
	glCullFace(GL_BACK);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;
	//glLoadMatrixf(glm::value_ptr(glm::perspective(45.0f * Camera::ZoomFactor, (float)windowWidth / (float)windowHeight, depth, -depth)));

	glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);
	glOrtho(-windowWidth, windowWidth, -windowHeight, windowHeight, depth, -depth);

	glfwSetScrollCallback(window, &MouseWheelFunc);
	glfwSetMouseButtonCallback(window, &MouseButtonFunc);
	glfwSetCursorPosCallback(window, &MouseMotionFunc);
	glfwSetKeyCallback(window, &KeyboardFunc);

#ifdef SPLINE_DEBUG
	Spline s,u,v,n,click;
	s.AddVertex(new Point(50, 100, 10));
	s.AddVertex(new Point(100, 200, 20));
	s.AddVertex(new Point(200, 300, -25));
	s.AddVertex(new Point(300, 400, 8));
	/*---------------------------------*/
	u.AddVertex(new Point(50, 100, 5));
	u.AddVertex(new Point(100, 110, 12));
	u.AddVertex(new Point(200, 95, -25));
	u.AddVertex(new Point(300, 90, 21));
	/*---------------------------------*/
	v.AddVertex(new Point(300, 90, 0));
	v.AddVertex(new Point(320, 200, 35));
	v.AddVertex(new Point(410, 300, 0));
	v.AddVertex(new Point(520, 400, 0));
	/*---------------------------------*/
	n.AddVertex(new Point(300, 400, 0));
	n.AddVertex(new Point(380, 420, 20));
	n.AddVertex(new Point(450, 390, 0));
	n.AddVertex(new Point(520, 400, 0));
	/*---------------------------------*/
	//splineList.push_back(s);
	//splineList.push_back(u);
	//splineList.push_back(v);
	//splineList.push_back(n);
	splineManager.AddSpline(s);
	splineManager.AddSpline(u);
	splineManager.AddSpline(v);
	splineManager.AddSpline(n);
#else
	c = new Cube(Point(0.0f, 0.0f, 0.0f), 100.0f);
#endif
	StartMainLoop();

	delete c;

	return 0;
}