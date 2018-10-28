#pragma once
#ifndef _FIRST_LAST_ELEMENT_SORTED_ARRAY_H_
#define _FIRST_LAST_ELEMENT_SORTED_ARRAY_H_

#include "pch.h"

/**
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 */
class FirstLastElementSortedArray
{
public:

	/* Binary Search Solution: Since the array is sorted, we won't need to
	 * perform a linear scan to determine where the starting and ending position
	 * of the given target value is.
	 *
	 * Instead, we can perform binary search on the array, continually recurse
	 * onto both sides, and stop recursing onto a side when the target value
	 * cannot exist in that subarray.
	 *
	 * If we detect the target during our recursion, determine if the target's
	 * index is smaller than the minimum index found, or greater than the
	 * maximum index found. In either case, mark the index down in its correct
	 * spot.
	 */
	std::vector<int> searchRange(std::vector<int> &nums, int target)
	{
		/* Edge Case: Target cannot be found inside an empty array. */
		if (nums.empty())
		{
			return std::vector<int>{-1, -1};
		}

		int minTargetIndex = -1;
		int maxTargetIndex = -1;

		/* Start searching between the two halves of the entire array. */
		searchRangeHelper(nums, target, 0, nums.size() - 1, &minTargetIndex,
			&maxTargetIndex);

		return std::vector<int>{minTargetIndex, maxTargetIndex};
	}

	void searchRangeHelper(std::vector<int> &nums, int target, int minIndex, 
		int maxIndex, int * minTargetIndex, int * maxTargetIndex)
	{
		/* Calculate midpoint of array. */
		int midpoint = (minIndex + maxIndex) / 2;

		/* Determine if target value has been hit. */
		if (nums[midpoint] == target)
		{
			/* Target value has not been hit before. */
			if (*minTargetIndex == -1 && *maxTargetIndex == -1)
			{
				*minTargetIndex = *maxTargetIndex = midpoint;
			}

			/* Target value is below the minimum index found. */
			else if (midpoint < *minTargetIndex)
			{
				*minTargetIndex = midpoint;
			}

			/* Target value is above the maximum index found. */
			else if (midpoint > *maxTargetIndex)
			{
				*maxTargetIndex = midpoint;
			}

			/* Else, target value is between the minimum and maximum index - 
			 * don't record anything. */
		}

		/* Only recurse to left and right halves if there is still two halves to
		 * look at. */
		if (minIndex < maxIndex)
		{
			/* If the max of the left side is greater than or equal to the 
			 * target, an instance of the target could exist in the left side. */
			if (nums[midpoint - 1] >= target)
			{
				searchRangeHelper(nums, target, minIndex, midpoint - 1, 
					minTargetIndex, maxTargetIndex);
			}

			/* If the min of the right side is less than or equal to the target, 
			 * an instance of the target could exist in the right side. */
			if (nums[midpoint + 1] <= target)
			{
				searchRangeHelper(nums, target, midpoint + 1, maxIndex, 
					minTargetIndex, maxTargetIndex);
			}
		}
	}
};

#endif	// _FIRST_LAST_ELEMENT_SORTED_ARRAY_H_