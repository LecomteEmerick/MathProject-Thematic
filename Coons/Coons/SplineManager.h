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
	int SizeList();
	~SplineManager() {}

	static std::vector<Spline> SplineList;
	
private:
	int indexCurrentSpline = 0;
};

