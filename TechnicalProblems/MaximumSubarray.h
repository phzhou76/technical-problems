#pragma once
#ifndef _MAXIMUM_SUBARRAY_H_
#define _MAXIMUM_SUBARRAY_H_

#include "pch.h"

/**
 * Problem: Given an integer array nums, find the contiguous subarray (containing
 * at least one number) which has the largest sum and return its sum.
 */
class MaximumSubarray
{
public:
	int maxSubArray(std::vector<int> &nums) 
	{
		if (nums.empty())
		{
			return std::numeric_limits<int>::min();
		}

		int currentSum = nums[0];
		int maxSum = nums[0];

		/* This problem can be solved with a linear sweep. At each element, take
		 * a look at the value of the element along with the sum of the previous
		 * subarray. If the sum of the previous subarray and the current number
		 * is greater than the current number, then we will extend the subarray
		 * to include this number. Otherwise, we will just have the current number
		 * as the only element in the subarray. */
		for (int i = 1; i < nums.size(); ++i)
		{
			/* Find the max between the current number and the previous
			 * sum plus the current number. If the current number is greater
			 * than the sum of the two numbers, the sum can just be this
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