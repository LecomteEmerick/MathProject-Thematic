#pragma once
#include <vector>

#include "Spline.h"

class SplineManager
{
public:
	SplineManager() {}
	void CreateSpline();
	void AddSpline(Spline s);
	void SplineManagerAddPointToCurrentSpline(Point p);
	void DoCheckInForAllSpline(int iteration);
	void DrawSpline();
	void SelectSpline(int step);
	~SplineManager() {}
private:
	int indexCurrentSpline = 0;
	std::vector<Spline> SplineList;
};

