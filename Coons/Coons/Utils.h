#pragma once

#include "Camera.h"
#include "Landmark.h"

class Utils
{
public:
	static void MouseScreenPosToWorldPos(double mouseX, double mouseY, float &posX, float &posY, float &posZ);
};

