#pragma once
#ifndef _SEARCH_INSERT_POSITION_H_
#define _SEARCH_INSERT_POSITION_H_

#include "pch.h"

/** 
 * Problem: Given a sorted array and a target value, return the index if the target
 * is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates are in the array.
 */
class SearchInsertPosition
{
	int searchInsert(std::vector<int> &nums, int target) 
	{
		/* Edge Case: Check if the target should be inserted or found at either
		 * end of the array. */
		if (nums.empty() || target <= nums[0])
		{
			return 0;
		}
		else if (target > nums[nums.size() - 1])
		{
			return nums.size();
		}

		/* Target should be inserted or found somewhere within the array. */
		return searchInsertHelper(nums, target, 0, nums.size() - 1);
	}

	int searchInsertHelper(std::vector<int> &nums, int target, int min, int max)
	{
		if (min >= max)
		{
			/* Target should always be placed before any duplicate or greater
			 * values, hence target should take the index of nums[min] if it is
			 * equal to it. */
			return (nums[min] >= target) ? min : min + 1;
		}

		int midpoint = (min + max) / 2;

		/* If the target value is less than or equal to the value at the midpoint,
		 * then the insertion index is the midpoint or before (in the event that
		 * multiple duplicate values exist before the midpoint). */
		if (target <= nums[midpoint])
		{
			/* Recurse on the lower half of the array. */
			return searchInsertHelper(nums, target, min, midpoint);
		}

		/* If the target value is greater than the minimum value of the right side
		 * of the array, then its insertion index must be after the index of the
		 * minimum value of the right side. */
		else if (target > nums[midpoint + 1])
		{
			return searchInsertHelper(nums, target, midpoint + 1, max);
		}

		/* The target value is between the maximum of the left side and the minimum
		 * of the right side of the array. Insert after the maximum of the left side
		 * of the array. */
		else
		{
			return midpoint + 1;
		}
	}
};

#endif	// _SEARCH_INSERT_POSITION_H_