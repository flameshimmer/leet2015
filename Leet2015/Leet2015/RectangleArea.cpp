#include "stdafx.h"

//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.

namespace Solution1
{
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
	{
		int intersect = max((min(C, G) - max(A, E)), 0) * max((min(D, H) - max(B, F)), 0);
		return  (C - A) * (D - B) + (G - E) * (H - F) - intersect;
	}

	void RectangleArea()
	{
		print(computeArea(0, 0, 0, 0, -1, -1, 1, 1));
	}
}