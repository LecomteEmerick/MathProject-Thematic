#define GLEW_STATIC 1
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "ChaikinsClass.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>

ChaikinsClass::ChaikinsClass(){}
void ChaikinsClass::AddVertex(Point p)
{
	this->vertex.push_back(p);
}

void ChaikinsClass::ApplyChaikins() {
	Point ControlPolygonI, ControlPolygonP, OriginI, OriginP;

}



ChaikinsClass::~ChaikinsClass(){}