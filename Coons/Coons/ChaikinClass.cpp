#include "ChaikinClass.h"
#define GLEW_STATIC 1
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\glm.hpp"
#include "ChaikinsClass.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>

ChaikinClass::ChaikinClass() {}
void ChaikinClass::AddVertex(Point p)
{
	this->vertex.push_back(p);
}

void ChaikinClass::ApplyChaikins() {
Point ControlPolygonI, ControlPolygonP, OriginI, OriginP;


}

ChaikinClass::~ChaikinClass() {}
