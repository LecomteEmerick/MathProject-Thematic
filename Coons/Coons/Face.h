#pragma once

#include "Triangle.h"

class Face
{
public:
	Face() {}
	Face(Triangle& T1, Triangle& T2) : _first(&T1), _second(&T2) {}
	void Draw();
	~Face() {}
private:
	Triangle* _first, *_second;
};

