#pragma once
#ifndef _ADD_ONE_H_
#define _ADD_ONE_H_

#include "pch.h"

/**
 * Problem: Given a non-negative number represented as an array of digits, add
 * one to the number (increment the number represented by the digits). The digits
 * are stored such that the most significant digit is at the head of the array.
 *
 * Questions:
 *	1. Can the input array have zeroes past the most significant digit (e.g.
 *		are values like 0123 allowed)? Assume no.
 *	2. Can the output have zeroes past the most significant digit (e.g. are
 *		values like 0124 allowed)? Assume no.
 *	3. Does error checking need to be done for the input (i.e. can it be assumed
 *		that the digits array is non-empty and is a valid input)?
 *	4. For arrays of empty digits, what should be returned?
 */
class AddOne
{
public:
	std::vector<int> addOne(std::vector<int> &digits)
	{
		if (digits.empty())
		{
			return std::vector<int>();
		}

		/* Use a list to avoid subpar performance when shifting digits over for
		 * a possible carry. 
		 *
		 * Note: Another approach is to just add one to the number, and continue
		 * to shift the carry towards the most significant bit. If the carry isn't
		 * one by the time the addition has finished processing the most signficant
		 * bit, then an increased size of the array isn't needed. However, if it
		 * is one, then just push the carry to the front of the vector. 
		 *
		 * If this method was used, it may take two sweeps, one for adding one to
		 * the number, and another one when all the digits in the array shift
		 * right for the carry in the most significant digit. However, its space
		 * complexity becomes O(1) instead of O(n). */
		std::list<int> addOneSum;

		/* Add one and start scanning backwards, from the ones digit to the most
		 * significant digit. */
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			int sum = digits[i] + carry;
			int digit = sum % 10;
			carry = sum / 10;
			addOneSum.push_front(digit);
		}

		/* Edge case: If sum of the number and one created a new most significant
		 * digit. */
		if (carry == 1)
		{
			addOneSum.push_front(1);
		}

		/* Convert the list into a vector. */
		return std::vector<int> {std::make_move_iterator(std::begin(addOneSum)),
			std::make_move_iterator(std::end(addOneSum))};
	}
};

#endif	// _ADD_ONE_H_