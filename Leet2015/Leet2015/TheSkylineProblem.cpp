#include "stdafx.h"

//A city's skyline is the outer contour of the silhouette formed by all the buildings in 
//that city when viewed from a distance. Now suppose you are given the locations and height
//of all the buildings as shown on a cityscape photo (Figure A), write a program to output 
//the skyline formed by these buildings collectively (Figure B).
//
//Buildings  Skyline Contour
//The geometric information of each building is represented by a triplet of integers[Li, Ri, Hi],
//where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively,
//and Hi is its height.It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0.
//You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
//For instance, the dimensions of all buildings in Figure A are recorded as :
//[[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]] .
//
//The output is a list of "key points" (red dots in Figure B) in the format of
//[[x1, y1], [x2, y2], [x3, y3], ...] that uniquely defines a skyline.A key point is the left
//endpoint of a horizontal line segment.Note that the last key point, where the rightmost building
//ends, is merely used to mark the termination of the skyline, and always has zero height.Also, the 
//ground in between any two adjacent buildings should be considered part of the skyline contour.
//
//For instance, the skyline in Figure B should be represented as : 
//[[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]].
//
//Notes :
//
//	  The number of buildings in any input list is guaranteed to be in the range[0, 10000].
//	  The input list is already sorted in ascending order by the left x position Li.
//	  The output list must be sorted by the x position.
//	  There must be no consecutive horizontal lines of equal height in the output skyline.
//	  For instance, 
//	  
//[...[2 3], [4 5], [7 5], [11 5], [12 7]...] 
//	  is not acceptable; 
//	  the three lines of height 5 should be merged into one in the final output as such : 
//[...[2 3], [4 5], [12 7], ...]

namespace Solution1
{
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
	{
		//vector<pair<int, int>> result;
		//int len = buildings.size();
		//int cur = 0;
		//int curX;
		//int curH = -1; 
		//priority_queue<pair<int, int>> liveBlg;

		//while (cur < len || !liveBlg.empty())
		//{
		//	curX = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;
		//	if (cur >= len || buildings[cur][0] > curX)
		//	{
		//		while (!liveBlg.empty() && (liveBlg.top().second <= curX))
		//		{
		//			liveBlg.pop();
		//		}
		//	}
		//	else
		//	{
		//		curX = buildings[cur][0];
		//		while (cur < len && buildings[cur][0] == curX)
		//		{
		//			liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
		//			cur++;
		//		}
		//	}

		//	curH = liveBlg.empty() ? 0 : liveBlg.top().first;
		//	if (result.empty() || result.back().second != curH)
		//	{
		//		result.push_back(make_pair(curX, curH));
		//	}
		//}
		//return result;

		vector<pair<int, int>> result;
		int len = buildings.size();
		int cur = 0;
		int curX = 0;
		int curH = -1;
		priority_queue<pair<int, int>> liveBlg;

		while (cur < len || !liveBlg.empty())
		{
			curX = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;
			if (cur >= len || buildings[cur][0] > curX)
			{
				while (!liveBlg.empty() && liveBlg.top().second <= curX)
				{
					liveBlg.pop();
				}
			}
			else
			{
				curX = buildings[cur][0];
				while (cur < len && buildings[cur][0] == curX)
				{
					liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
					cur++;
				}
			}

			curH = liveBlg.empty() ? 0 : liveBlg.top().first;
			if (result.empty() || result.back().second != curH)
			{
				result.push_back(make_pair(curX, curH));
			}
		}
		return result;

	}

	namespace bruteforce
	{
		static bool compFunc(pair<int, int>a, pair<int, int>b)
		{
			return a.first < b.first;
		}
		vector<int> getHighestBuildingContainsPoint(vector<vector<int>>& buildings, int point, int excludeIndex)
		{
			int len = buildings.size();

			int maxHeightIndex = -1;
			int maxHeight = -1;
			for (int i = 0; i < len; i++)
			{
				vector<int> cur = buildings[i];
				int left = cur[0];
				int right = cur[1];

				if (point < left || point > right || i == excludeIndex) { continue; }
				else
				{
					int height = cur[2];
					if (height > maxHeight)
					{
						height = maxHeight;
						maxHeightIndex = i;
					}
				}
			}
			vector<int> result;
			if (maxHeightIndex == -1)
			{
				return result;
			}
			else
			{
				return buildings[maxHeightIndex];
			}
		}

		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
		{
			vector<pair<int, int>> result;
			int len = buildings.size();
			if (len == 0) { return result; }

			for (int i = 0; i < len; i++)
			{
				vector<int> curBuilding = buildings[i];
				int left = curBuilding[0];
				int right = curBuilding[1];
				int top = curBuilding[2];

				vector<int> leftSideCompBuilding = getHighestBuildingContainsPoint(buildings, left, i);
				if (leftSideCompBuilding.size() == 0 || top > leftSideCompBuilding[2])
				{
					result.push_back(make_pair(left, top));
				}

				vector<int> rightSideCompBuilding = getHighestBuildingContainsPoint(buildings, right, i);
				if (rightSideCompBuilding.size() == 0)
				{
					result.push_back(make_pair(right, 0));
				}
				else if (top > rightSideCompBuilding[2])
				{
					result.push_back(make_pair(right, rightSideCompBuilding[2]));
				}
			}
			sort(result.begin(), result.end(), compFunc);
			return result;
		}
	}
	void TheSkylineProblem()
	{
		// [[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]
		vector<vector<int>> input = { { 2, 9, 10 }, { 3, 7, 15 }, { 5, 12, 12 }, { 15, 20, 10 }, { 19, 24, 8 } };
		print(getSkyline(input));
		cout << "[[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]\n";
	}
}