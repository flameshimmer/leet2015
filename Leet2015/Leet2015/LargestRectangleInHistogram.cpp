#include "stdafx.h"

//Given n non - negative integers representing the histogram's bar
//height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given height = [2, 1, 5, 6, 2, 3],
//return 10.

namespace Solution1
{	
	int largestRectangleArea(vector<int>& height) {
		stack<int> s;
		height.push_back(0);

		int result = 0;
		for (int i = 0; i < height.size(); i++)
		{
			if (s.empty() || height[s.top()] <= height[i])
			{
				s.push(i);
			}
			else
			{
				int temp = s.top();
				s.pop();
				int startIndex = s.empty() ? -1 : s.top();
				result = max(result, height[temp] * (i - startIndex - 1));
				i--;
			}
		}
		return result;
	}


	namespace tooSlow{
		int largestRectangleArea(vector<int>& height) {
			int result = 0;
			int len = height.size();

			for (int i = 0; i < len; i++)
			{
				int curHeight = height[i];
				int lower = i - 1;
				int higher = i + 1;
				while (lower >= 0 && height[lower] >= curHeight)
				{
					lower--;
				}
				while (higher < len && height[higher] >= curHeight)
				{
					higher++;
				}
				int distance = higher - lower - 1;
				result = max(result, distance * curHeight);
			}
			return result;
		}
	}
	
	
	void LargestRectangleInHistogram()
	{
		print(largestRectangleArea(createVector({2,1,5,6,2,3})));
	}
}