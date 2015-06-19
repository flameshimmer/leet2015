#include "stdafx.h"
#include <set>

//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time / space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.

namespace Solution1
{
	int maximumGap(vector<int>& nums) 
	{
		int len = nums.size();
		if (len < 2) { return 0; }
		
		int minVal = INT_MAX;
		int maxVal = INT_MIN;
		for (int val : nums)
		{
			minVal = min(minVal, val);
			maxVal = max(maxVal, val);
		}

		int interval = max(1, (maxVal - minVal) / len);
		int intervalCount = (maxVal - minVal) / interval + 1;
		vector<pair<int, int>> buckets(intervalCount, make_pair(-1, -1));
		for (int val : nums)
		{
			int bucketIndex = (val - minVal) / interval;
			buckets[bucketIndex].first = (buckets[bucketIndex].first == -1) ? val : min(buckets[bucketIndex].first, val);
			buckets[bucketIndex].second = (buckets[bucketIndex].second == -1) ? val : max(buckets[bucketIndex].second, val);
		}
		
		int maxGap = 0;
		int prev = buckets[0].second;
		for (int i = 1; i < buckets.size(); i++)
		{
			pair<int, int>bucket = buckets[i];
			if (bucket.first == -1) { continue; }
			maxGap = max(maxGap, bucket.first - prev);
			prev = bucket.second;
		}
		return maxGap;
	}


	void MaximumGap()
	{
		//print(maximumGap(createVector({ 1, 1, 1, 1, 1, 5, 5, 5, 5, 5 })));
		print(maximumGap(createVector({ 15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463, 20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740 })));
	}
}