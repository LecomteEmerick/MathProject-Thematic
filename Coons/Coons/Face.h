#pragma once

#include <vector>

#include "Triangle.h"

class Face
{
public:
	Face() {}
	Face(Triangle& T1, Triangle& T2) : _first(&T1), _second(&T2) 
	{
		this->_point.push_back(T1.GetPoint_A());
		this->_point.push_back(T1.GetPoint_B());
		this->_point.push_back(T1.GetPoint_C());
		this->_point.push_back(T2.GetPoint_C());
	}
	Face(Point a, Point b, Point c, Point d)
	{
		this->_point.push_back(a); this->_point.push_back(b); this->_point.push_back(c); this->_point.push_back(d);
		this->_first = &Triangle(a, b, c);
		this->_second = &Triangle(c, b, d);
	}
	void Draw();
	~Face() {}
private:
	Triangle* _first, *_second;
	std::vector<Point> _point;
};

