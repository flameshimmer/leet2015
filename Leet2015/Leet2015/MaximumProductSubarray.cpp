#include "stdafx.h"

//Find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//For example, given the array[2, 3, -2, 4],
//the contiguous subarray[2, 3] has the largest product = 6.

namespace Solution1
{

		int maxProduct(vector<int>& nums) 
		{
			int len = nums.size();
			int maxProduct = nums[0];
			if (len == 1) { return maxProduct; }
			
			int curProduct = 1;
			int firstNeg = 1;

			for (int cur : nums)
			{
				if (cur != 0)
				{
					curProduct *= cur;
					if (curProduct < 0)
					{
						if (firstNeg > 0)
						{
							firstNeg = curProduct;
						}
						else
						{
							maxProduct = max(maxProduct, curProduct / firstNeg);
						}						
					}
					else
					{
						maxProduct = max(maxProduct, curProduct);
					}
				}
				else
				{
					curProduct = 1;
					maxProduct = max(0, maxProduct);
					firstNeg = 1;
				}
			}
			return maxProduct;
		}

		namespace other
		{
			int findLocalMax(vector<int>& nums, int start, int end)
			{
				if (start > end) { return 0; }
				if (start == end) { return nums[start]; }
				int product = 1;
				int negCount = 0;
				for (int i = start; i <= end; i++)
				{
					product *= nums[i];
					if (nums[i] < 0) { negCount++; }
				}

				if (negCount % 2 == 0) { return product; }
				else
				{
					int productLeft = product;
					for (int i = end; i >= start; i--)
					{
						productLeft /= nums[i];
						if (nums[i] < 0) { break; }
					}

					int productRight = product;
					for (int i = start; i <= end; i++)
					{
						productRight /= nums[i];
						if (nums[i] < 0) { break; }
					}

					return max(productLeft, productRight);
				}
			}

			int maxProduct(vector<int>& nums) {
				int len = nums.size();
				int maxProduct = INT_MIN;
				int start = 0;
				int end = 0;

				while (end < len)
				{
					while (end < len && nums[end] == 0)
					{
						end++;
					}
					start = end;
					while (end < len && nums[end] != 0)
					{
						end++;
					}
					end--;
					int localResult = findLocalMax(nums, start, end);
					maxProduct = max(maxProduct, localResult);
					if (end < len - 1)
					{
						maxProduct = max(maxProduct, 0);
					}
					end++;
				}
				return maxProduct;
			}
		}
	void MaximumProductSubarray()
	{
		vector<int> nums = { -2, 0, 1};
		print(maxProduct(nums));
	}
}