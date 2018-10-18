#pragma once
#ifndef _MERGE_INTERVALS_H_
#define _MERGE_INTERVALS_H_

#include "pch.h"

/**
 * Problem: Given a collection of intervals, merge all overlapping intervals.
 *
 * Examples:
 *	1. [[1, 4], [4, 5]] -> [[1, 5]], since the intervals [1, 4] and [4, 5] are
 *		considered to be overlapping.
 */

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct IntervalComparator
{
	inline bool operator() (const Interval &interval1, const Interval &interval2)
	{
		return interval1.start < interval2.start;
	}
};

class MergeIntervals
{
public:

	/* If the Interval objects are sorted by their start value, then each set of
	 * intervals that can be merged will be next to each other in the sorted list.
	 *
	 * First, sort the intervals by their start value, and insert the first
	 * interval into the merged list, and start examining each interval afterwards.
	 *
	 * Possible scenarios:
	 *	1. If the current interval begins after the previous interval ends (i.e.
	 *		the current interval's start value is greater than the previous
	 *		interval's end value), then we know that the intervals do not overlap.
	 *		In this case, append the current interval to the merged array.
	 *	2. If the current interval begins before or at where the previous interval
	 *		ends (i.e. the current interval's start value is less than or equal
	 *		to the previous interval's end value), then we know that the intervals
	 *		overlap. In this case, update the last element in the merged array to
	 *		the greater of the end values between the merged interval and the
	 *		current interval.
	 *
	 * Repeat this process for every interval in the list, and return the result. */
	std::vector<Interval> merge(std::vector<Interval> &intervals)
	{
		if (intervals.empty())
		{
			return std::vector<Interval>();
		}
		
		/* Sort the intervals in ascending start values. */
		std::sort(intervals.begin(), intervals.end(), IntervalComparator());

		std::vector<Interval> mergedIntervals;
		mergedIntervals.push_back(intervals[0]);

		for (auto it : intervals)
		{
			/* Case: If the current interval is completely outside of the previous 
			 * interval, then just add this new interval to the list of merged 
			 * intervals. */
			if (it.start > mergedIntervals.back().end)
			{
				mergedIntervals.push_back(it);
			}

			/* Case: If the current interval overlaps with the previous interval,
			 * just update the end value of the merged interval to match the
			 * greater of the end values. */
			else
			{
				mergedIntervals.back().end = std::max(mergedIntervals.back().end, it.end);
			}
		}

		return mergedIntervals;
	}
};

#endif	// _MERGE_INTERVALS_H_