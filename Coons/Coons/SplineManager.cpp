#include "SplineManager.h"

#include "Utils.h"

void SplineManager::CreateSpline()
{
	if (this->SplineList.size() > 0)
		this->SplineList[this->indexCurrentSpline].ChangeColorOfVertex(Utils::White);
	this->indexCurrentSpline = this->SplineList.size();
	this->SplineList.push_back(Spline());
	this->SplineList[this->indexCurrentSpline].ChangeColorOfVertex(Utils::Green);
}

void SplineManager::AddSpline(Spline s)
{
	if(this->SplineList.size() > 0)
		this->SplineList[this->indexCurrentSpline].ChangeColorOfVertex(Utils::White);
	this->indexCurrentSpline = this->SplineList.size();
	this->SplineList.push_back(s);
	this->SplineList[this->indexCurrentSpline].ChangeColorOfVertex(Utils::Green);
}

void SplineManager::SplineManagerAddPointToCurrentSpline(Point p)
{
	this->SplineList[indexCurrentSpline].AddVertex(p);
}

void SplineManager::DoCheckInForAllSpline(int iteration)
{
	for(int i=0; i < this->SplineList.size(); ++i)
		this->SplineList[i].chaikin(iteration);
}

void SplineManager::DrawSpline()
{
	for (int i = 0; i < this->SplineList.size(); ++i)
	{
		this->SplineList[i].Draw();
	}
}
void SplineManager::SelectSpline(int step)
{
	if (this->SplineList.size() > 0)
		this->SplineList[this->indexCurrentSpline].ChangeColorOfVertex(Utils::White);
	this->indexCurrentSpline = (this->indexCurrentSpline + step) % this->SplineList.size();
	this->SplineList[this->indexCurrentSpline].ChangeColorOfVertex(Utils::Green);
}
