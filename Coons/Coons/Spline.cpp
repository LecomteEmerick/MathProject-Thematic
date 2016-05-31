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

	glBegin(GL_LINE_STRIP);
	for (Point p : this->vertex)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();

	glBegin(GL_POINTS);
	for (Point p : this->chaitlinVertex)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (Point p : this->chaitlinVertex)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();
}

void Spline::Chaitlin(int iteration) {
	for (int j = 0; j < iteration;++j)
	{ 
		if (j == 0) {
			this->chaitlinVertex.clear();
			Point originI, originP, controlPolygonI, controlPolygonP, pointVector;
			for (int i = 0; i < ((int)this->vertex.size()) - 1; ++i) {
				originI = vertex[i];
				originP = vertex[i + 1];
				pointVector._y = (originP._y - originI._y)*0.75;
				pointVector._x = (originP._x - originI._x)*0.75;
				controlPolygonI._y = pointVector._y + originI._y;
				controlPolygonI._x = pointVector._x + originI._x;
				controlPolygonP._x = originP._x - pointVector._x;
				controlPolygonP._y = originP._y - pointVector._y;
				controlPolygonI._Color = Color(1, 0, 0);
				controlPolygonP._Color = Color(0, 0, 1);
				chaitlinVertex.push_back(controlPolygonP);
				chaitlinVertex.push_back(controlPolygonI);
			}
		}
		else{
			Point originI, originP, controlPolygonI, controlPolygonP, pointVector;
			for (int i = 0; i < ((int)this->chaitlinVertex.size()) - 1; ++i) {
				originI = chaitlinVertex[i];
				originP = chaitlinVertex[i + 1];
				pointVector._y = (originP._y - originI._y)*0.75;
				pointVector._x = (originP._x - originI._x)*0.75;
				controlPolygonI._y = pointVector._y + originI._y;
				controlPolygonI._x = pointVector._x + originI._x;
				controlPolygonP._x = originP._x - pointVector._x;
				controlPolygonP._y = originP._y - pointVector._y;
				controlPolygonI._Color = Color(1, 0, 0);
				controlPolygonP._Color = Color(0, 0, 1);
				iteratorVector.push_back(controlPolygonP);
				iteratorVector.push_back(controlPolygonI);
			}
			chaitlinVertex = iteratorVector;
			iteratorVector.clear();
		}
	}
}

Spline::~Spline()
{
}
