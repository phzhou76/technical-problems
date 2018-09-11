#pragma once
#ifndef _REMOVE_ELEMENT_H_
#define _REMOVE_ELEMENT_H_

#include "pch.h"

/**
 * Problem: Given an array nums and a value val, remove all instances of that 
 * value in-place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying 
 * the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond 
 * the new length.
 */
class RemoveElements
{
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		/* Edge case - arrays with 0 elements have no elements to remove. */
		if (nums.empty())
		{
			return 0;
		}

		/* Holds the size of the array without the removed value. */
		int newArrayLength = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			/* Copy the value to the new "array" if the value is not the
			 * removed value. */
			if (nums[i] != val)
			{
				nums[newArrayLength++] = nums[i];
			}
		}

		return newArrayLength;
	}
};

#endif	// _REMOVE_ELEMENT_H_