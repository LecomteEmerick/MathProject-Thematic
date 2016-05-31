#include "Landmark.h"

void Landmark::Draw()
{
	glBegin(GL_POINTS);
	glColor3f(100.0f, 100.0f, 100.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 100.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(100.0f, 100.0f, 100.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);

	glColor3f(100.0f, 100.0f, 100.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);

	glColor3f(100.0f, 100.0f, 100.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 100.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();
}