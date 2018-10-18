#pragma once
#ifndef _THREE_SUM_CLOSEST_H_
#define _THREE_SUM_CLOSEST_H_

#include "pch.h"

/**
 * Problem: Given an array of n integers and an integer target, find three integers
 * in nums such that the sum is closest to the target. Return the sum of these
 * three integers. You may assume that each input has exactly one solution.
 */
class ThreeSumClosest
{
public:
	int threeSumClosest(std::vector<int> &nums, int target)
	{
		/* If there are three or less elements, then those elements are the
		 * closest to the target value. */
		if (nums.size() <= 3)
		{
			int result = 0;
			for (auto it : nums)
			{
				result += it;
			}

			return result;
		}

		/* To do comparisons, we need to sort our array in ascending order. */
		std::sort(nums.begin(), nums.end());

		/* Assume that there are three indices we will look at: i, j, and k, where
		 * i < j < k. Then, for each number nums[i], we will look for pairs nums[j],
		 * nums[k] such that the absolute value of target - nums[i] - nums[j] - nums[k]
		 * is minimalized. We do this by having j start out at the element after i,
		 * and k start out at the end of the array, and having j and k close in
		 * on each other to narrow down the sum towards the target.
		 *
		 * Because the array is sorted, we can do the following:
		 *	1. If the sum of the triplet is greater than the target, then we have
		 *		to reduce one of the values in the triplet. Decrease k, since that's
		 *		at the end of the array.
		 *	2. If the sum of the triplet is less than the target, then we have to
		 *		increase one of the values in the triplet. Increase j, since that's
		 *		at the start of the subarray. */
		int closestSum = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int j = i + 1;
			int k = nums.size() - 1;

			while (j < k)
			{
				int tripletSum = nums[i] + nums[j] + nums[k];
				
				/* No closer value than the target itself. */
				if (tripletSum == target)
				{
					return tripletSum;
				}

				if (std::abs(target - tripletSum) < std::abs(target - closestSum))
				{
					closestSum = tripletSum;
				}

				/* Adjust j or k based on if the current sum is smaller or larger
				 * than the target value. */
				(tripletSum < target) ? ++j : --k;
			}
		}

		return closestSum;
	}
};

#endif	// _THREE_SUM_CLOSEST_H_