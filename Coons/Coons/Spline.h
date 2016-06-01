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
	void Spline::addSpline(Spline s);
	void Spline::Draw();
	void Spline::chaikin(int iteration);
	void Spline::coons();
	void Spline::ChangeColorOfVertex(Color col);
	~Spline();

	std::vector<Point> PointList;
private:
	std::vector<Point> TempCoonVec;
	std::vector<Point> CoonPatchVector;
	std::vector<Point> coonsVector2;
	std::vector<Point> coonsVector1;
	std::vector<Point> vertex;
	std::vector<Point> chaikinVertex;
	std::vector<Point> iteratorVector;

	std::vector<Spline> splineVector;
};

