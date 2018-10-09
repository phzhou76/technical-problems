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

	/* Observe that in a permutation of decreasing numbers, no larger permutation
	 * is possible (e.g. 951). Then, in a permutation of numbers, we need to start
	 * from the ones place, and head towards the most significant bit until we 
	 * find a digit that is less than the previous digit. 
	 * 
	 * Swap places between that digit and the least-value digit that is still 
	 * greater than it, which gives the next lexicographically greater value for
	 * that digit's place. 
	 * 
	 * Then, sort all digits to the right of that digit such that the values are
	 * in increasing value, which minimizes the value of the digits to the right
	 * of the swapped digit. */
	void nextPermutation(std::vector<int> &nums)
	{

	}
};

#endif	// _NEXT_PERMUTATION_H_