#include "Spline.h"

#include "glm\gtc\type_ptr.hpp"

Spline::Spline()
{
	//this->Shader.LoadVertexShader("ShaderLib/basic.vs");
	//this->Shader.LoadFragmentShader("ShaderLib/basic.fs");
	//this->Shader.Create();

	//this->ShaderProgram = this->Shader.GetProgram();
}

void Spline::AddVertex(Point p)
{

	this->vertex.push_back(p);
	//this->indices.push_back(this->vertex.size() - 1);

	//this->ConstructEBO();
	//this->ConstructVBO();
}

//void Spline::ConstructEBO()
//{
	//glGenBuffers(1, &this->EBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), (void*)&indices.front(), GL_STREAM_DRAW);
//}

//void Spline::ConstructVBO()
//{
	//glGenBuffers(1, &this->VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	//glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(Point), (void*)&vertex.front(), GL_STREAM_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//}

void Spline::Draw()
{
	glPointSize(5.0f);

	glBegin(GL_POINTS);
	for (Point p : this->vertex)
		glVertex2f(p._x, p._y);
	glEnd();

	glBegin(GL_LINES);
	for (Point p : this->vertex)
	{
		glVertex2f(p._x, p._y);
	}
	glEnd();
}

Spline::~Spline()
{
}
