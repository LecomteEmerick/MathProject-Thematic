#include "Utils.h"
#include "GL\glew.h"
#include "OpenGl_Legacy.h"

const Color Utils::White(1.0f, 1.0f, 1.0f);
const Color Utils::Black(0.0f, 0.0f, 0.0f);
const Color Utils::Red(1.0f, 0.0f, 0.0f);
const Color Utils::Green(0.0f, 1.0f, 0.0f);
const Color Utils::Blue(0.0f, 0.0f, 1.0f);
const Color Utils::Yellow(1.0f, 1.0f, 0.0f);
const Color Utils::Cyan(0.0f, 1.0f, 1.0f);
const Color Utils::Magenta(1.0f, 0.0f, 1.0f);

void Utils::MouseScreenPosToWorldPos(double mouseX, double mouseY, float &posX, float &posY, float &posZ)
{
	GLfloat modelview[16], projection[16];
	GLint viewport[4];

	float outputCoord[3];

	glGetFloatv(GL_MODELVIEW_MATRIX, modelview);
	glGetFloatv(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	OpenGl_Legacy::glhUnProjectf((float)mouseX, (float)mouseY, (float)0, modelview, projection, viewport, outputCoord);

	posX = outputCoord[0];
	posY = outputCoord[1];
	posZ = outputCoord[2];
}
