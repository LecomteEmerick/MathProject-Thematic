#include "Triangle.h"

#include "GL\glew.h"

void Triangle::Draw()
{
	//glBegin(GL_POINTS);
	////
	//glColor3f(this->_a->_Color._Red, this->_a->_Color._Green, this->_a->_Color._Blue);
	//glVertex3f(this->_a->_x, this->_a->_y, this->_a->_z);
	////
	//glColor3f(this->_b->_Color._Red, this->_b->_Color._Green, this->_b->_Color._Blue);
	//glVertex3f(this->_b->_x, this->_b->_y, this->_b->_z);
	////
	//glColor3f(this->_c->_Color._Red, this->_c->_Color._Green, this->_c->_Color._Blue);
	//glVertex3f(this->_c->_x, this->_c->_y, this->_c->_z);
	////
	//glEnd();

	glBegin(GL_TRIANGLES);
	//
	glColor3f(this->_Color._Red, this->_Color._Green, this->_Color._Blue);
	//
	glVertex3f(this->_a->_x, this->_a->_y, this->_a->_z);
	glVertex3f(this->_b->_x, this->_b->_y, this->_b->_z);
	glVertex3f(this->_c->_x, this->_c->_y, this->_c->_z);
	//
	glEnd();
}