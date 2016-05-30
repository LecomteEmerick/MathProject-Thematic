#pragma once
#include <vector>

#include "GL\glew.h"
#include "common\EsgiShader.h"
#include "Point.h"
#include "glm\gtc\matrix_transform.hpp"

class Spline
{
public:
	Spline();
	void Spline::AddVertex(Point p);
	void Spline::Draw();
	~Spline();

	std::vector<Point> PointList;
private:
	//void			ConstructEBO();
	//void			ConstructVBO();
	//GLuint			EBO;
	//GLuint			VBO;
	//GLuint			ShaderProgram;
	//EsgiShader		Shader;

	std::vector<Point> vertex;
	//std::vector<int> indices;
};

