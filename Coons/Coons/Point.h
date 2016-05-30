#pragma once
#include "Color.h"
class Point
{
public:
	Point() : _x(0), _y(0), _z(0), _Color(1.0f,1.0f,1.0f) {}
	Point(int x, int y) : _x(x), _y(y), _z(0) {}
	Point(int x, int y, int z) : _x(x), _y(y), _z(z) {}
	Point(Point* p) { this->_x = p->_x; this->_y = p->_y; this->_z = p->_z; }
	~Point() {}

	int _x, _y, _z;
	Color _Color;
};
