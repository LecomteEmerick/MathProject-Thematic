#pragma once

class Color
{
public:
	Color() : _Red(1.0f), _Green(1.0f), _Blue(1.0f) { }
	Color(float r, float g, float b) : _Red(r), _Green(g), _Blue(b) {}

	float _Red, _Green, _Blue;

};