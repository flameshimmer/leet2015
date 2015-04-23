#include "stdafx.h"

//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].

namespace Solution1
{
	static bool mySortFunc(Interval i1, Interval i2)
	{
		return i1.start < i2.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) 
	{
		int len = intervals.size();
		if (len < 2) { return intervals; }

		sort(intervals.begin(), intervals.end(), mySortFunc);
		vector<Interval> result;

		result.push_back(intervals[0]);
		for (int i = 1; i < len; i++)
		{
			Interval front = result.back();
			Interval back = intervals[i];

			if (front.end < back.start)
			{
				result.push_back(back);
			}
			else if (back.end < front.end)
			{
				continue;
			}
			else
			{
				result.pop_back();
				result.push_back(Interval(front.start, back.end));
			}
		}
		return result;
	}

	void MergeIntervals()
	{
		vector<Interval> intervals;
		intervals.push_back(Interval(1, 3));
		intervals.push_back(Interval(2, 6));
		intervals.push_back(Interval(8, 10));
		intervals.push_back(Interval(15, 18));
		print(merge(intervals));
	}
}