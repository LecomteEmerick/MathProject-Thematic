#pragma once
#include <vector>

#include "GL\glew.h"
#include "common\EsgiShader.h"
#include "Point.h"
#include "glm\gtc\matrix_transform.hpp"

class ChaikinClass
{
	public:
	ChaikinClass();
	void ChaikinClass::ApplyChaikins();
	void ChaikinClass::AddVertex(Point p);
	~ChaikinClass();
	std::vector<Point> PointList;

	private:
	std::vector<Point> vertex;
};
