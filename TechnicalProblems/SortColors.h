#pragma once
#ifndef _SORT_COLORS_H_
#define _SORT_COLORS_H_

#include "pch.h"

/**
 * Problem: Given an array with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order of red, white, or blue. 
 *
 * Here, we will use the integers 0, 1, and 2 to represent red, white, and blue,
 * respectively. 
 * 
 * Notes:
 *	1. You cannot use a sort algorithm for this problem.
 *	2. A straightforward solution is a two-pass algorithm using counting sort.
 *		First, iterate through the array counting the number of 0s, 1s, and 2s,
 *		and then overwrite the array with the total numbers of 0s, 1s, and 2s.
 *	3. Could you come up with a one-pass algorithm using only constant space?
 */
class SortColors
{
public:
	void sortColors(std::vector<int> &nums)
	{
		/* Edge Case: No colors need to be sorted of arrays of size 1 or less. */
		if (nums.size() < 2)
		{
			return;
		}

		/* We can "sort" this array in one pass using three pointers:
		 *	1. One pointer marks the sorted zeroes subarray (the lower part of
		 *		the array). It specifically points to the element after the entire
		 *		sorted zeroes subarray.
		 *	2. One pointer marks the sorted twos subarray (the upper part of the
		 *		array). It specifically points to the element before the entire
		 *		sorted twos subarray. 
		 *	3. Last pointer is used to scan through unknown values. */
		int zeroesEnd = 0;
		int twosEnd = nums.size() - 1;
		int unknownValuePtr = zeroesEnd;

		/* We only need to continue scanning the "unknown" part of the array until
		 * the pointer enters the known twos subarray. */
		while (unknownValuePtr <= twosEnd)
		{
			/* If the left and middle pointer swap values, it's guaranteed that
			 * the left pointed to a 1, and the middle pointed to a 0. If the left
			 * pointed to a 2, then the middle would have already encountered it
			 * and swapped with the right pointer. Additionally, the left and
			 * middle pointer could be pointing to the same index. If the value
			 * was zero, then both pointers need to advance. */
			if (nums[unknownValuePtr] == 0)
			{
				nums[unknownValuePtr++] = nums[zeroesEnd];
				nums[zeroesEnd++] = 0;
			}
			/* Can't advance middle pointer after swapping with the right pointer,
			 * since we don't know if the right pointer has a 0 or 1. If it's a 0,
			 * then we need to swap that value with the left pointer. */
			else if (nums[unknownValuePtr] == 2)
			{
				nums[unknownValuePtr] = nums[twosEnd];
				nums[twosEnd--] = 2;
			}
			/* Else, the unknown value pointer is pointing to a 1. Move onto the
			 * next value. */
			else
			{
				++unknownValuePtr;
			}
		}
	}
};

#endif	// _SORT_COLORS_H_