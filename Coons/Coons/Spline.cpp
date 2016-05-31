#include "Spline.h"

Spline::Spline()
{
}

void Spline::AddVertex(Point p)
{

	this->vertex.push_back(p);
}

void Spline::Draw()
{
	glPointSize(5.0f);

	glBegin(GL_POINTS);
	for (Point p : this->vertex)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (Point p : this->vertex)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();
}

Spline::~Spline()
{
}
