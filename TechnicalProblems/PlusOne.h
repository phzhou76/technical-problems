#pragma once
#ifndef _PLUS_ONE_H_
#define _PLUS_ONE_H_

#include "pch.h"

/**
 * Given a non-negative number represented as an array of digits, add one to the
 * number (increment the number represented by the digits). The digits are stored
 * such that the most significant digit is at the head of the array.
 *
 * Questions:
 *	1. Can the input array have zeroes past the most significant digit (e.g.
 *		are values like 0123 allowed)? Assume no.
 *	2. Can the output have zeroes past the most significant digit (e.g. are
 *		values like 0124 allowed)? Assume no.
 *	3. Does error checking need to be done for the input (i.e. can it be assumed
 *		that the digits array is non-empty and is a valid input)?
 *	4. For arrays of empty digits, what should be returned?
 *
 * Source: https://leetcode.com/problems/plus-one/description/
 */
class AddOne
{
public:

	/* Iterative Solution: Scan through the array of digits, starting from the
	 * digit in the back, since that's the least significant digit. Add one to
	 * that digit, and calculate the sum and the carry.
	 *
	 * Then, pass the carry along towards the most significant digit. If the
	 * carry ever becomes 0, then stop immediately, since the carry cannot become
	 * 1 afterwards.
	 *
	 * If the carry is still 1 at the end of the loop, then a new digit must be
	 * added as the most significant digit. Push it to the front of the array
	 * (a O(n) operation, since all digits to the right need to be shifted by 1).
	 *
	 * Time Complexity: O(n), where n is the number of digits in the number.
	 * Space Complexity: O(1), since the original array is just modified.
	 */
	std::vector<int> plusOne(std::vector<int> &digits)
	{
		if (digits.empty())
		{
			return std::vector<int>();
		}

		/* A list can be used to avoid subpar performance when shifting digits 
		 * over for a new most significant digit. However, space complexity will
		 * then become O(n).
		 *
		 * std::list<int> addOneSum;
		 *
		 * Add one and start scanning from the ones digit to the most significant
		 * digit. */
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			/* If carry is 0, all digits from this digit onwards will remain the
			 * same. */
			if (carry == 0)
			{
				return digits;
			}

			int sum = digits[i] + carry;
			int digit = sum % 10;
			carry = sum / 10;
			digits[i] = digit;
		}

		/* Edge case: If sum of the number and one created a new most significant
		 * digit. */
		if (carry == 1)
		{
			digits.insert(digits.begin(), carry);
		}

		return digits;
	}
};

#endif	// _PLUS_ONE_H_