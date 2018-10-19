#pragma once
#ifndef _MAXIMUM_PRODUCT_SUBARRAY_H_
#define _MAXIMUM_PRODUCT_SUBARRAY_H_

#include "pch.h"

/**
 * Problem: Given an integer array nums, find the contiguous subarray within an
 * array (containing at least one number) which has the largest product.
 */
class MaximumProductSubarray
{
public:

	void swap(int * num1, int * num2)
	{
		int tmp = *num1;
		*num1 = *num2;
		*num2 = tmp;
	}

	/* First, create an integer that holds the global maximum found so far. Then,
	 * create two integer values, one that holds the minimum product found so far,
	 * and the other that holds the maximum product found so far.
	 *
	 * The idea is that if a negative number does exist in the array, the minimum
	 * value will hold a negative value, while the maximum value will hold a positive
	 * value. If another negative value exists, then multiplying the minimum value
	 * by that negative value could make it the maximum value. On the other hand,
	 * multiplying the maximum value by that negative value could make it the
	 * minimum value.
	 *
	 * Have the minimum and maximum start out at the first value. Then, loop from
	 * the 2nd number onwards to the last number in the array. If the current
	 * number is negative, then we need to swap the minimum and maximum values to
	 * account for the following:
	 *	1. Multiplying max * negative (if max is positive) could result in lowest
	 *		min value.
	 *	2. Multiplying min * negative (if min is negative) could result in highest
	 *		max value.
	 * Then, if the newly calculated product between the previous product and the
	 * current number is less than the current number, make that the new minimum.
	 * Else, make the current number the new minimum.
	 *
	 * Additionally, if the newly calculated product between the previous product
	 * and the current number is greater than the current number, make that the
	 * new maximum. Else, make the current number the new maximum.
	 *
	 * Update the global maximum from the new maximum as needed.
	 */
	int maxProduct(std::vector<int> &nums)
	{
		/* Store the maximum product that has been found so far. */
		int maxProduct = nums[0];

		/* iMax: Stores the maximum product of the subarray that ends with nums[i].
		 * iMin: Stores the minimum product of the subarray that ends with nums[i]. */
		for (int i = 1, iMax = maxProduct, iMin = maxProduct; i < nums.size(); ++i)
		{
			/* If the current value is negative, and iMax > iMin, then multiplying
			 * iMax * negativeValue and iMin * negativeValue means that iMax will
			 * now be less than iMin. Switch their positions of maximum and minimum. */
			if (nums[i] < 0)
			{
				swap(&iMin, &iMax);
			}

			/* The minimum of the contiguous subarray that ends with this number
			 * is the minimum between this number and the previous product multiplied
			 * by this number.
			 *
			 * The maximum of the contiguous subarray that ends with this number
			 * is the maximum between this number and the previous product multiplied
			 * by this number. */
			iMin = std::min(nums[i], iMin * nums[i]);
			iMax = std::max(nums[i], iMax * nums[i]);

			/* Update global max if possible. */
			maxProduct = std::max(maxProduct, iMax);
		}

		return maxProduct;
	}
};

#endif	// _MAXIMUM_PRODUCT_SUBARRAY_H_