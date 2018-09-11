#pragma once
#ifndef _MAXIMUM_SUBARRAY_H_
#define _MAXIMUM_SUBARRAY_H_

#include "pch.h"

/**
 * Problem: Given an interger array nums, find the contiguous subarray (containing
 * at least one number) which has the largest sum and return its sum
 */
class MaximumSubarray
{
public:
	int maxSubArray(std::vector<int>& nums) {
		if (nums.empty())
		{
			return std::numeric_limits<int>::min();
		}

		int currentSum = nums[0];
		int maxSum = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			/* Find the max between the current number and the previous
			 * sum plus the current number. If the current number is greater
			 * than the sum of the two numbers, replace the sum with this
			 * number. */
			currentSum = std::max(nums[i], currentSum + nums[i]);

			if (currentSum > maxSum)
			{
				maxSum = currentSum;
			}
		}

		return maxSum;
	}
};

#endif	// _MAXIMUM_SUBARRAY_H_