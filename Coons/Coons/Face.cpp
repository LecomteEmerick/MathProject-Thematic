#include "Face.h"

Point Face::GetBarycentre()
{
	Point barycentre;
	for (Point p : this->_point)
	{
		barycentre += p;
	}
	barycentre *= (1.0f / (float)this->_point.size());
	barycentre._Color = Color(0.75f,0.32f, 0.12f);
	return barycentre;
}

void Face::Draw()
{
	_first->Draw();
	_second->Draw();
}
