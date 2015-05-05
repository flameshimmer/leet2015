#include "stdafx.h"

//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//
namespace Solution1
{
	static bool _comp(int a, int b)
	{
		ostringstream ss;
		ss << a;
		string sa = ss.str();
		ss.clear();
		ss << b;
		string sb = ss.str();
		ss.clear();

		string ab = sa + sb;
		string ba = sb + sa;
		if (ab.compare(ba) >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string numToStr(int num)
	{
		ostringstream ss;
		ss << num;
		return ss.str();
	}
	string largestNumber(vector<int>& nums)
	{		
		string result;
		sort(nums.begin(), nums.end(), _comp);

		if (nums[0] == 0) { return "0"; }
		for (int val : nums)
		{
			result += numToStr(val);
		}
		return result;
	}
	
	
	void LargestNumber()
	{
		print(largestNumber(createVector({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 })));
		//print(largestNumber(createVector({ 74, 21, 33, 51, 77, 51, 90, 60, 5, 56 })));
		//print(largestNumber(createVector({ 3, 30, 34, 5, 9 })));
		//print(largestNumber(createVector({ 1, 1, 1 })));
	}
}