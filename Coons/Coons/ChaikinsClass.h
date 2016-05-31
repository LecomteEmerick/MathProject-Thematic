#pragma once
#include <vector>

#include "GL\glew.h"
#include "common\EsgiShader.h"
#include "Point.h"
#include "glm\gtc\matrix_transform.hpp"

class ChaikinsClass
{
public:
	ChaikinsClass();
	void ChaikinsClass::ApplyChaikins();
	void ChaikinsClass::AddVertex(Point p);
	~ChaikinsClass();
	std::vector<Point> PointList;

private:
	std::vector<Point> vertex;
};

