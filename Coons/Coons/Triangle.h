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

	Point* GetPoint_A() { return this->_a; }
	Point* GetPoint_B() { return this->_b; }
	Point* GetPoint_C() { return this->_c; }

private:
	Point* _a, *_b, *_c;
	Color _Color;
};

