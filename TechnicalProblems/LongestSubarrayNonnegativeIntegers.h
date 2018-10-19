#pragma once
#ifndef _LONGEST_SUBARRAY_NONNEGATIVE_INTEGERS_H_
#define _LONGEST_SUBARRAY_NONNEGATIVE_INTEGERS_H_

#include "pch.h"

/**
 * Problem: Given an array, return the length of the longest subarray of
 * non-negative integers (i.e. all integers >= 0).
 */
class LongestSubarrayNonnegativeIntegers
{
public:

	/* Use a sliding window approach. */
	int getSubarray(std::vector<int> integers)
	{
		int longestSubarray = 0;
		int leftIndex = 0;

		for (int i = 0; i < integers.size(); ++i)
		{
			if (integers[i] >= 0)
			{
				int subarrayLength = i - leftIndex + 1;
				longestSubarray = std::max(longestSubarray, subarrayLength);
			}
			else
			{
				leftIndex = i + 1;
			}
		}

		return longestSubarray;
	}
};

#endif	// _LONGEST_SUBARRAY_NONNEGATIVE_INTEGERS_H_