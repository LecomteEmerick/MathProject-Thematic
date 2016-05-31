#pragma once

#include "Face.h"

class Cube
{
private:
	Point basic_a = Point(0.0f, 0.0f, 0.5F);
	Point basic_b = Point(1.0f, 0.0f, 0.5F);
	Point basic_c = Point(0.0f, 1.0f, 0.5F);
	Point basic_d = Point(1.0f, 1.0f, 0.5F);
	Point basic_e = Point(0.0f, 0.0f, -0.5F);
	Point basic_f = Point(1.0f, 0.0f, -0.5F);
	Point basic_g = Point(0.0f, 1.0f, -0.5F);
	Point basic_h = Point(1.0f, 1.0f, -0.5F);

	Point a;
	Point b;
	Point c;
	Point d;
	Point e;
	Point f;
	Point g;
	Point h;

	Triangle T1 = Triangle(a, b, c, Utils::Red);
	Triangle T2 = Triangle(c, b, d, Utils::Red);
	Triangle T3 = Triangle(e, g, f, Utils::Green);
	Triangle T4 = Triangle(g, h, f, Utils::Green);
	Triangle T5 = Triangle(e, f, a, Utils::Blue);
	Triangle T6 = Triangle(a, f, b, Utils::Blue);
	Triangle T7 = Triangle(c, d, g, Utils::Yellow);
	Triangle T8 = Triangle(g, d, h, Utils::Yellow);
	Triangle T9 = Triangle(e, a, c, Utils::Cyan);
	Triangle T10 = Triangle(g, e, c, Utils::Cyan);
	Triangle T11 = Triangle(b, f, d, Utils::Magenta);
	Triangle T12 = Triangle(h, d, f, Utils::Magenta);


public:
	float baseScale, currentScale;

	Face F1 = Face(T1, T2);
	Face F2 = Face(T3, T4);
	Face F3 = Face(T5, T6);
	Face F4 = Face(T7, T8);
	Face F5 = Face(T9, T10);
	Face F6 = Face(T11, T12);

	void Cube::SetTransformPosition(Point center)
	{
		a = basic_a + center; b = basic_b + center; c = basic_c + center; d = basic_d + center; e = basic_e + center; f = basic_f + center; g = basic_g + center; h = basic_h + center;
	}

	void Cube::SetScale(float scale)
	{
		currentScale += scale;
		if (currentScale > 10.0f)
		{
			a = basic_a * currentScale; b = basic_b * currentScale; c = basic_c * currentScale; d = basic_d * currentScale;
			e = basic_e * currentScale; f = basic_f * currentScale; g = basic_g * currentScale; h = basic_h * currentScale;
		}
	}

	Cube() : a(basic_a), b(basic_b), c(basic_c), d(basic_d), e(basic_e), f(basic_f), g(basic_g), h(basic_h) {}
	Cube(Point center, float scale) { 
		this->baseScale = scale;
		currentScale = this->baseScale;
		SetTransformPosition(center);
		SetScale(scale);
	}

	void Draw() { F1.Draw(); F2.Draw(); F3.Draw(); F4.Draw(); F5.Draw(); F6.Draw(); }

	~Cube() {}



};