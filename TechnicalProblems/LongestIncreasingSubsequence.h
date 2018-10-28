#pragma once
#ifndef _LONGEST_INCREASING_SUBSEQUENCE_H_
#define _LONGEST_INCREASING_SUBSEQUENCE_H_

#include "pch.h"

/**
 * Given an unsorted array of integers, find the length of longest increasing 
 * subsequence.
 *
 * Note:
 *	1. There may be more than one LIS combination; it is only necessary for you
 *		to return the length.
 *	2. Your algorithm should run in O(n^2) complexity.
 *
 * Follow-up: Could you improve it to O(n log n) time complexity?
 *
 * Source: https://leetcode.com/problems/longest-increasing-subsequence/description/
 */
class LongestIncreasingSubsequence
{
public:
	int lengthOfLIS(std::vector<int>& nums)
	{
		/* Edge Case: Longest increasing subsequence of an array of 0 or 1
		 * elements is just the array's size. */
		if (nums.size() < 2)
		{
			return nums.size();
		}

		/* Holds the max length of an increasing subsequence that ends with the
		 * corresponding number. I.e. the 5th element of this array holds the max
		 * length of an increasing subsequence that ends with the 5th element
		 * of nums. */
		std::vector<int> subsequenceLengths;

		/* Maximum length of subsequence ending with the first element will always
		 * be 1. */
		subsequenceLengths.push_back(1);
		int longestSubsequence = 1;

		/* Calculate the maximum length of subsequence ending with the number for
		 * the rest of the numbers in the array. */
		for (int i = 1; i < nums.size(); ++i)
		{
			/* Determine the maximum length of all valid subsequences that ended in
			 * previous numbers in the array. Valid subsequences are those that end
			 * with a previous number in the array in which the number is less than
			 * the current number being examined.
			 *
			 * Note: If the maxValidLength remains 0 by the end of the loop, then
			 * no valid subsequences could be found. Set the max length of the
			 * subsequence that ends with the current value to 1. 
			 *
			 * Note: If the algorithm can be improved to O(n log n), then it could
			 * possibly be done here. Instead of scanning backwards to find the
			 * maximum valid length, there should be a way to perform binary
			 * search onto the subarray. */
			int maxValidLength = 0;
			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[j] < nums[i] && subsequenceLengths[j] > maxValidLength)
				{
					maxValidLength = subsequenceLengths[j];
				}
			}

			/* Maximum length of subsequence that ends with this number is the
			 * maximum length of subsequence that ends with lesser number plus 1.
			 * If no such valid subsequence exists, just set it to 1. */
			subsequenceLengths.push_back(maxValidLength + 1);

			if (maxValidLength + 1 > longestSubsequence)
			{
				longestSubsequence = maxValidLength + 1;
			}
		}

		return longestSubsequence;
	}
};

#endif	// _LONGEST_INCREASING_SUBSEQUENCE_H_