#pragma once

#include "Point.h"

class Triangle
{
public:
	Triangle() : _a(), _b(), _c() {}
	Triangle(Point& a, Point& b, Point& c) : _a(&a), _b(&b), _c(&c) {}
	Triangle(Point& a, Point& b, Point& c, Color col) : _a(&a), _b(&b), _c(&c), _Color(col) {}
	void Draw();
	~Triangle() {}
private:
	Point* _a, *_b, *_c;
	Color _Color;
};

