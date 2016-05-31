#pragma once
#include "Color.h"
class Point
{
public:
	Point() : _x(0), _y(0), _z(0), _Color(1.0f,1.0f,1.0f) {}
	Point(float x, float y) : _x(x), _y(y), _z(0) {}
	Point(float x, float y, float z) : _x(x), _y(y), _z(z) {}
	Point(float x, float y, float z, Color c) : _x(x), _y(y), _z(z), _Color(c) {}
	Point(Point* p) { this->_x = p->_x; this->_y = p->_y; this->_z = p->_z; }
	~Point() {}

	Point operator+(Point p) { return Point(this->_x + p._x, this->_y + p._y, this->_z + p._z); }
	void operator+=(Point p) { this->_x += p._x; this->_y += p._y; this->_z += p._z; }

	Point operator*(float f) { return Point(this->_x * f, this->_y * f, this->_z * f); }
	void operator*=(float f) { this->_x *= f; this->_y *= f; this->_z *= f; }

	float _x, _y, _z;
	Color _Color;
};
