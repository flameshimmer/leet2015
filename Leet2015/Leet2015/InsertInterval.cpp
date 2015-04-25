#include "stdafx.h"

//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
//
//Example 2 :
//Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
//
//This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].

namespace Solution1
{
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval> result;
		if (intervals.size() == 0)
		{
			result.push_back(newInterval);
			return result;
		}
		int i = 0;		
		while (i < intervals.size() && intervals[i].end < newInterval.start)
		{
			result.push_back(intervals[i]);
			i++;
		}
		if (i < intervals.size())
		{
			newInterval.start = min(intervals[i].start, newInterval.start);
			
			while (i<intervals.size() && intervals[i].start <= newInterval.end)
			{
				newInterval.end = max(newInterval.end, intervals[i].end);
				i++;
			}			
		}
		
		result.push_back(newInterval);
		for (i; i < intervals.size(); i++)
		{
			result.push_back(intervals[i]);
		}
		return result;
	}

	namespace other2
	{
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
		{
			vector<Interval> result;
			bool merged = false;
			for (Interval cur : intervals)
			{
				if (merged || cur.end < newInterval.start)
				{
					result.push_back(cur);
				}
				else if (newInterval.end < cur.start)
				{
					result.push_back(newInterval);
					result.push_back(cur);
					merged = true;
				}
				else
				{
					newInterval.start = min(cur.start, newInterval.start);
					newInterval.end = max(cur.end, newInterval.end);
				}
			}
			if (!merged)
			{
				result.push_back(newInterval);
			}
			return result;
		}
	}

	void InsertInterval()
	{
		//[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
		vector<Interval> intervals;
		intervals.push_back(Interval(1, 5));
		print(insert(intervals, Interval(6, 8)));
		//Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
		vector<Interval> intervals2;
		intervals2.push_back(Interval(1, 2));
		intervals2.push_back(Interval(3, 5));
		intervals2.push_back(Interval(6, 7));
		intervals2.push_back(Interval(8, 10));
		intervals2.push_back(Interval(12, 16));
		//print(insert(intervals2, Interval(4, 9)));
	}
}