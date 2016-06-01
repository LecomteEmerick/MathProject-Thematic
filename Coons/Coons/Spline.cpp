#include "Spline.h"
#include "SplineManager.h"



Spline::Spline()
{
}

void Spline::AddVertex(Point p)
{
	this->vertex.push_back(p);
}

void Spline::addSpline(Spline s) {
	this->splineVector.push_back(s);
}

void Spline::Draw()
{
	glPointSize(5.0f);

	//glBegin(GL_POINTS);
	//for (Point p : this->vertex)
	//{
	//	glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
	//	glVertex3f(p._x, p._y, p._z);
	//}
	//glEnd();

	glBegin(GL_LINE_STRIP);
	for (Point p : this->vertex)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();

	//glBegin(GL_POINTS);
	//for (Point p : this->chaikinVertex)
	//{
	//	glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
	//	glVertex3f(p._x, p._y, p._z);
	//}
	//glEnd();

	//glBegin(GL_LINE_STRIP);
	//for (Point p : this->chaikinVertex)
	//{
	//	glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
	//	glVertex3f(p._x, p._y, p._z);
	//}
	//glEnd();

	glBegin(GL_POINTS);
	for (Point p : this->coonsVector1)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();

	glBegin(GL_POINTS);
	for (Point p : this->TempCoonVec)
	{
		glColor3f(p._Color._Red, p._Color._Green, p._Color._Blue);
		glVertex3f(p._x, p._y, p._z);
	}
	glEnd();
}

void Spline::ChangeColorOfVertex(Color col)
{
	for (int i = 0; i < this->vertex.size(); ++i)
	{
		this->vertex[i]._Color = col;
	}
}

void Spline::chaikin(int iteration) {
	for (int j = 0; j < iteration;++j)
	{ 
		if (j == 0) {
			this->chaikinVertex.clear();
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
				controlPolygonI._Color = Color(1, i, i);
				controlPolygonP._Color = Color(i, i, 1);
				chaikinVertex.push_back(controlPolygonP);
				chaikinVertex.push_back(controlPolygonI);
			}
		}
		else{
			Point originI, originP, controlPolygonI, controlPolygonP, pointVector;
			for (int i = 0; i < ((int)this->chaikinVertex.size()) - 1; ++i) {
				originI = chaikinVertex[i];
				originP = chaikinVertex[i + 1];
				pointVector._y = (originP._y - originI._y)*0.75;
				pointVector._x = (originP._x - originI._x)*0.75;
				controlPolygonI._y = pointVector._y + originI._y;
				controlPolygonI._x = pointVector._x + originI._x;
				controlPolygonP._x = originP._x - pointVector._x;
				controlPolygonP._y = originP._y - pointVector._y;
				controlPolygonI._Color = Color(1, i, i);
				controlPolygonP._Color = Color(i, i, 1);
				iteratorVector.push_back(controlPolygonP);
				iteratorVector.push_back(controlPolygonI);
			}
			chaikinVertex = iteratorVector;
			iteratorVector.clear();
		}
	}
	coons();
}

void Spline::coons() {
	//Interpolation lineaire AB + Interpolation lineaire de CD - interpolation billineaire de ABCD i.25
	Point temp;
	float iter = 0.25;
	
	splineVector = SplineManager::SplineList;
	//Interpolation lineaire AB
	int count=0;
	for (int i = 0; i < ((int)this->vertex.size())-1;i++) {
		for (float inc = 0; inc <= 1; inc=inc+iter) {
			count++;
			temp._x = (1 - inc)*splineVector[1].vertex[i]._x + inc*splineVector[3].vertex[i]._x;
			temp._y = (1 - inc)*splineVector[1].vertex[i]._y + inc*splineVector[3].vertex[i]._y;
			temp._z = (1 - inc)*splineVector[1].vertex[i]._z + inc*splineVector[3].vertex[i]._z;
			coonsVector1.push_back(temp);
		}
		//Interpolation lineaire CD
		for (float inc = i; inc <= 1; inc = inc + iter) {
			temp._x = (1 - inc)*splineVector[0].vertex[i]._x + inc*splineVector[2].vertex[i]._x;
			temp._y = (1 - inc)*splineVector[0].vertex[i]._y + inc*splineVector[2].vertex[i]._y;
			temp._z = (1 - inc)*splineVector[0].vertex[i]._z + inc*splineVector[2].vertex[i]._z;
			coonsVector1.push_back(temp);
		}
	}

	for (int i = 0; i < ((int)this->vertex.size()) - 1; i++)
	{
		for (int j = i; j < ((int)this->vertex.size())-1; ++j)
		{
			Point _pp;
			float t = i / vertex.size() - 1;
			float s = j / vertex.size() - 1;
			_pp._x = vertex[i]._x * (1 - s)*(1 - t) + vertex[3]._x * s * (1 - t) + vertex[i]._x * (1 - s)*t + vertex[3]._x * s * t;
			_pp._x = vertex[i]._x * (1 - s)*(1 - t) + vertex[3]._x * s * (1 - t) +vertex[i]._x * (1 - s)*t + vertex[3]._x * s * t;
			_pp._x = vertex[i]._x * (1 - s)*(1 - t) + vertex[3]._x * s * (1 - t) +vertex[i]._x * (1 - s)*t + vertex[3]._x * s * t;
			TempCoonVec.push_back(_pp);
		};
		//coonsVector3.push_back(TempCoonVec);
	}
}

Spline::~Spline()
{
}
