#pragma once

#include <vector>

#include "Face.h"

class Shape
{
public:
	Shape() {}
	Shape(std::vector<Face> faces) : _faces(faces) {}
	void Draw();
	~Shape() {}
private:
	std::vector<Face> _faces;
};

