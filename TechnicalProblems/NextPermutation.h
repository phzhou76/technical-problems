#pragma once
#ifndef _NEXT_PERMUTATION_H_
#define _NEXT_PERMUTATION_H_

#include "pch.h"

/**
 * Problem: Implement a method that obtains the next greater permutation of numbers.
 * It takes in a list of digits, and rearranges the digits into the next greater
 * permutation of numbers. If no such arrangement is possible (i.e. the current
 * arrangement is the maximum value permutation), then rearrange the numbers in 
 * lowest possible order (i.e. sorted in ascending order).
 *
 * Note: The replacement must be done in-place and use only constant extra memory.
 *
 * Examples:
 *	1. 1, 2, 3 -> 1, 3, 2
 *  2. 3, 2, 1 -> 1, 2, 3
 *  3. 4, 2, 0, 2, 3, 2, 0 -> 4, 2, 0, 3, 0, 2, 2
 */
class NextPermutation
{
public:

	/* Observe that in a permutation of decreasing digits, no larger permutation
	 * is possible (e.g. 951). Then, that means that if a number does have a next
	 * greater permutation of digits, there is one digit in the number that is
	 * less than the digit to its right. 
	 *
	 * So, we need to start looking at the ones place, and head towards the most
	 * significant digit. If we find a digit that is less than the digit on the
	 * right, then that place would be used for swapping digits. However, if we
	 * don't find any digits that are less than their respective digits on the
	 * right, we know that this is the greatest permutation of digits. Reverse
	 * the contents of the array to obtain the lowest value permutation.
	 *
	 * Assuming that we find the digit that is less than the digit on the right,
	 * we can get the next possible greater permutation by swapping that digit
	 * with the lowest value digit that is still greater than it to the right.
	 * 
	 * Then, sort the digits to the right of the swapped digit in ascending order
	 * so that the minimum value possible to the right of the swapped digit is 
	 * achieved. */
	void nextPermutation(std::vector<int> &nums)
	{

	}
};

#endif	// _NEXT_PERMUTATION_H_