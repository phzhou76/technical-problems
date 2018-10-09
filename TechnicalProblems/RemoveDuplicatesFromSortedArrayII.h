#pragma once
#ifndef _REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H_
#define _REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H_

#include "pch.h"

/**
 * Problem: Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appear at most twice and return the new length. Do not allocate
 * extra space for another array, you must do this by modifying the input array
 * in-place with O(1) extra memory. 
 */
class RemoveDuplicatesFromSortedArrayII
{
public:
	int removeDuplicates(std::vector<int> &nums)
	{
		/* No duplicates can be removed in arrays of size 2 or less. */
		if (nums.size() < 3)
		{
			return nums.size();
		}

		/* Use two pointers, one to mark the end of the new array, and one to
		 * mark the current element in the old array being looked at. */
		int newPointer = 1;
		int oldPointer = 1;
		int previousValue = nums[0];
		int previousValueCount = 1;

		while (oldPointer < nums.size())
		{
			/* Only add the current value being looked at if the count of the value
			 * so far is less than 2. Otherwise, just advance the pointer to the
			 * old array to find numbers of different value. */
			if (nums[oldPointer] == previousValue)
			{
				if (previousValueCount < 2)
				{
					++previousValueCount;
					nums[newPointer++] = nums[oldPointer++];
				}
				else
				{
					++oldPointer;
				}
			}
			/* If the current value being looked at is different from the previous
			 * value being looked at, just add the current value immediately to
			 * the new array.*/
			else
			{
				nums[newPointer++] = nums[oldPointer];
				previousValue = nums[oldPointer++];
				previousValueCount = 1;
			}
		}

		return newPointer;
	}
};

#endif	// _REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H_