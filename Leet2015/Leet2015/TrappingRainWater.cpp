#include "stdafx.h"

//Given n non - negative integers representing an elevation map where 
//the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.

namespace Solution1
{

	int trap(vector<int>& height)
	{
		int len = height.size();
		if (len < 2) { return 0; }

		int left = 0;
		int right = len - 1;
		int result = 0;
		while (left < right)
		{
			int minVal = min(height[left], height[right]);
			if (minVal == height[left])
			{
				left++;
				while (left < right && height[left] <= minVal)
				{
					result += minVal - height[left];
					left++;
				}
			}
			else
			{
				right--;
				while (left < right && height[right] <= minVal)
				{
					result += minVal - height[right];
					right--;
				}
			}
		}
		return result;
	}


	namespace other
	{
		int trap(vector<int>& height)
		{
			int len = height.size();
			if (len == 0){ return 0; }

			vector<int> leftSideLargest(len, 0);
			vector<int> rightSideLargest(len, 0);
			int curLeftMax = 0;
			int curRightMax = 0;
			for (int i = 0; i < len; i++)
			{
				leftSideLargest[i] = curLeftMax;
				curLeftMax = max(curLeftMax, height[i]);

				rightSideLargest[len - 1 - i] = curRightMax;
				curRightMax = max(curRightMax, height[len - 1 - i]);
			}

			int result = 0;
			for (int i = 0; i < len; i++)
			{
				int water = min(leftSideLargest[i], rightSideLargest[i]) - height[i];
				result += water > 0 ? water : 0;
			}
			return result;
		}
	}

	void TrappingRainWater()
	{
		print(trap(createVector({ 0, 2, 0 })));
		print(trap(createVector({ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 })));
	}
}