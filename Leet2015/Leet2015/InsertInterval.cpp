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
	int lookForIndex(vector<Interval>& intervals, Interval newInterval, bool isHeadLookup)
	{
		int start = 0;
		int end = intervals.size() - 1;
		int target = isHeadLookup ? newInterval.start : newInterval.end;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			int value = isHeadLookup ? intervals[mid].start : intervals[mid].end;

			if (value == target)
			{
				return mid;
			}
			else if (value < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return end;
	}
	
	int merge(vector<Interval>& intervals, int mergeLocation, Interval back)
	{
		Interval front = intervals[mergeLocation];
		if (front.end < back.start)
		{
			intervals.insert(intervals.begin() + mergeLocation+1, back);
			return mergeLocation + 1;
		}
		else if (back.end < front.end)
		{
			return mergeLocation;
		}
		else
		{
			intervals[mergeLocation] = Interval(front.start, back.end);
			return mergeLocation;
		}
	}
	
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
	{
		int startIndex = lookForIndex(intervals, newInterval, true);
		int endIndex = lookForIndex(intervals, newInterval, false);

		int mergedIndex = merge(intervals, startIndex, newInterval);
		merge(interval, mergedIndex, intervals[endIndex])

	}

	void InsertInterval()
	{
	
	}
}