#include "Shape.h"



void Shape::Draw()
{
	for (int i=0; i < this->_faces.size();++i)
		this->_faces[i].Draw();
}
