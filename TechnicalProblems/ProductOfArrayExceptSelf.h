#pragma once
#ifndef _PRODUCT_OF_ARRAY_EXCEPT_SELF_H_
#define _PRODUCT_OF_ARRAY_EXCEPT_SELF_H_

#include "pch.h"

/**
 * Problem: Given an array nums of n integers where n > 1, return an array output
 * such that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Note: Please solve it without division and in O(n).
 * Note: Try to solve the problem with constant space complexity. The output array
 *		does not count as extra space for the purpose of space complexity analysis.
 */
class ProductOfArrayExceptSelf
{
public:

	/* Since division cannot be used, multiplication and caching must be used.
	 * 
	 * In the following example, the factors in each product are listed:
	 *
	 *	[3, 2, 4, 10]
	 *   2  3  3   3
	 *	 4  4  2   2
	 *  10 10 10   4
	 *
	 * Notice that when we scan the 1st element for the first time, there's not
	 * much we can do with that number without scanning the rest of the array. 
	 * However, when we scan the 2nd element for the first time, we know that
	 * it will use the multiplication results of the 1st element (just 3). When
	 * we scan the 3rd element for the first time, we know that it will use the
	 * multiplication results of the 2nd element, multiplied by the second element.
	 * (At this point, the 2nd element has not encountered the third element, so
	 * it doesn't have the third element in its product.) The fourth element should
	 * then multiply the third element by the product that the third element
	 * currently has. 
	 *
	 *	[3, 2, 4, 10]
	 *   1  3  3   3
	 *	       2   2
	 *             4 
	 *
	 * We can then go backwards to fill in the missing factors. Starting with 
	 * the third element, we can cache the 4th element. Then, with the second 
	 * element, we can multiply the cache of the third element by the third element.
	 * Repeat until the two caches look like the following:
	 *
	 *	[3, 2, 4, 10]
	 *   1  3  3   3
	 *	       2   2
	 *   2         4 
	 *   4  4
	 *  10 10 10   1
	 *
	 * Then, for each respective element in the two caches, multiply the results
	 * together and return it as a new array.
	 */
	std::vector<int> productExceptSelf(std::vector<int> &nums)
	{
		/* Edge case: Cannot create a product without at least 2 elements. */
		if (nums.size() < 2)
		{
			return nums;
		}

		std::vector<int> forwardProductCache(nums.size(), 0);
		forwardProductCache[0] = 1;

		/* Start multiplying forwards and caching the known results. */
		for (int i = 1; i < nums.size(); ++i)
		{
			forwardProductCache[i] = forwardProductCache[i - 1] * nums[i - 1];
		}

		std::vector<int> backwardProductCache(nums.size(), 0);
		backwardProductCache[nums.size() - 1] = 1;

		/* Start multiplying backwards and caching the known results. */
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			backwardProductCache[i] = backwardProductCache[i + 1] * nums[i + 1];
		}

		/* Multiply the forward and backwards caches together and return it as
		 * the result. */
		for (int i = 0; i < forwardProductCache.size(); ++i)
		{
			forwardProductCache[i] *= backwardProductCache[i];
		}

		return forwardProductCache;
	}
};

#endif	// _PRODUCT_OF_ARRAY_EXCEPT_SELF_H_