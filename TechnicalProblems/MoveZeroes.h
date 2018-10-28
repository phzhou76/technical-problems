#pragma once
#ifndef _MOVE_ZEROES_H_
#define _MOVE_ZEROES_H_

#include "pch.h"

/**
 * Given an array nums, write a function to move all 0s to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * Source: https://leetcode.com/problems/move-zeroes/description/
 */
class MoveZeroes
{
public:

	/* This problem can be solved by first marking the 0th index as the spot past
	 * the non-zero elements. Then, scan the array to start moving the non-zero
	 * elements to the non-zero subarray. After that, fill the rest of the array
	 * from the end of the non-zero subarray to the end of the array with 0s.
	 */
	void moveZeroes(std::vector<int> &nums)
	{
		/* Marks the end of the non-zero subarray. For reference, if this value
		 * is 1, then there is a non-zero element at the 0th index. */
		int nonZeroEndIndex = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				nums[nonZeroEndIndex++] = nums[i];
			}
		}

		/* Fill the rest of the array with 0s. */
		for (int i = nonZeroEndIndex; i < nums.size(); ++i)
		{
			nums[i] = 0;
		}
	}
};

#endif	// _MOVE_ZEROES_H_