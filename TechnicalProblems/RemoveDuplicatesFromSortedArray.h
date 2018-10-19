#pragma once
#ifndef _REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H_
#define _REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H_

#include "pch.h"

/**
 * Problem: Given a sorted array nums, remove the duplicates in-place such that
 * each element appears only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 */
class RemoveDuplicatesFromSortedArray
{
	/* Have a pointer point to the current value being examined for duplicates.
	 * Then:
	 *	1. Sweep through the array until a different value is found.
	 *		1a. "Push" the different value to the end of the unique values subarray.
	 *		1b. Have the pointer point to the newly pushed different value.
	 *	2. Repeat step 1 until the end of the array has been reached. */
	int removeDuplicates(std::vector<int>& nums)
	{
		/* No duplicates can exist if there are less than 2 elements. */
		if (nums.size() < 2)
		{
			return nums.size();
		}

		/* Greatest non-duplicate value found. */
		int currentValue = nums[0];

		/* Number of unique elements found so far. */
		int uniqueSize = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			/* Non-duplicate value found. */
			if (nums[i] > currentValue)
			{
				nums[uniqueSize] = nums[i];
				currentValue = nums[i];
				++uniqueSize;
			}
		}

		return uniqueSize;
	}
};

#endif	// _REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H_