#include "stdafx.h"

//Given a sorted integer array where the range of elements are[lower, upper] inclusive, return its missing ranges.
//
//For example, given[0, 1, 3, 50, 75], lower = 0 and upper = 99, return["2", "4->49", "51->74", "76->99"].
//
namespace Solution1
{
	string getRange(int num, int lastNum)
	{
		string range;
		if (num - lastNum == 2)
		{
			range = to_string(lastNum + 1);
		}
		else if(num - lastNum > 2)
		{
			range = to_string(lastNum + 1) + "->" + to_string(num - 1);
		}
		return range;
	}
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string>result;

		nums.insert(nums.begin(), lower-1);
		nums.push_back(upper+1);
		for (int i = 1; i < nums.size(); i++)
		{
			string range = getRange(nums[i], nums[i - 1]);
			if (range.length() > 0)
			{
				result.push_back(range);
			}
		}
		return result;
	}

	void MissingRanges()
	{
		print(findMissingRanges(createVector({ 0, 1, 3, 50, 75 }), 0, 99));
	}
}