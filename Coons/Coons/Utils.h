#pragma once

#include "Camera.h"
#include "Landmark.h"
#include "Color.h"

class Utils
{
public:
	static void MouseScreenPosToWorldPos(double mouseX, double mouseY, float &posX, float &posY, float &posZ);

	static const Color White;
	static const Color Black;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Cyan;
	static const Color Magenta;
};

