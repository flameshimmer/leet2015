#include "stdafx.h"

//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

namespace Solution1
{

	int maxPoints(vector<Point>& points)
	{
		int len = points.size();
		if (len < 2) { return len; }

		int result = 0;
		for (int i = 0; i < len; i++)
		{
			Point cur = points[i];		
			int count = 1;
			unordered_map<double, int> map;
			int vertical = 0;
			int localMax = 0;
			for (int j = i + 1; j < len; j++)
			{
				Point test = points[j];
				if (test.x != cur.x)
				{
					double k = (double)(test.y - cur.y) / (double)(test.x - cur.x);
					map[k]++;
					localMax = max(localMax, map[k]);
				}
				else if (test.y != cur.y)
				{
					vertical++;
					localMax = max(localMax, vertical);
				}
				else
				{
					count++;
				}
			}
			result = max(result, count + localMax);
		}
		return result;
	}

	void MaxPointsOnALine()
	{
		vector<Point> points = {
			{ 0, 0 },
			{ 1, 1 },
			{ 0, 0 }
		};

		// Error: note that the vertical line case. 
		// Error: note that k is double. Need to get both denominator and numerator to double before doing the calcuation.
		// Error: count the duplicated points, and avoid recalculation of previously calculated points!
		points = { { 84, 250 }, { 0, 0 }, { 1, 0 }, { 0, -70 }, { 0, -70 }, { 1, -1 }, { 21, 10 }, { 42, 90 }, { -42, -230 } };
		print(maxPoints(points));
	}
}