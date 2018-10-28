#pragma once
#ifndef _DIVIDE_TWO_INTEGERS_H_
#define _DIVIDE_TWO_INTEGERS_H_

/**
 * Given two integers, dividend and divisor, divide two integers without using 
 * the multiplication, division, or mod operator.
 *
 * Return the quotient after dividing dividend by divisor. The integer division
 * should truncate toward zero.
 *
 * Example 1:
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 *
 * Example 2:
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2 
 *
 * Note: The divisor will never by 0.
 *
 * Source: https://leetcode.com/problems/divide-two-integers/description/
 */
class DivideTwoIntegers
{
public:
	int divide(int dividend, int divisor)
	{
		/* Note: The below solution is too slow to be of any use. */
#if 0
		if (divisor == 1)
		{
			return dividend;
		}

		/* Determines whether or not the division's result will be positive. */
		bool isResultPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

		/* Transform both inputs to negative numbers. In this situation, negative numbers
		 * can hold more "absolute value" than positive numbers (2^31 versus 2^31 - 1), so
		 * negative numbers need to be used to deal with possible overflows. */
		dividend = (dividend > 0) ? -dividend : dividend;
		divisor = (divisor > 0) ? -divisor : divisor;

		int divisionCounter = 0;

		/* Division between two negative numbers can be performed, and the division counter can
		 * be inverted based on whether or not the end result should have been negative or
		 * positive. */
		while (dividend <= divisor)
		{
			std::cout << dividend << " " << divisor << std::endl;
			dividend -= divisor;
			--divisionCounter;
		}

		/* Edge case: If the division counter is the most negative number (-2^31), and the
		 * division result should have been positive, then just return 2^31 - 1, since an
		 * overflow would have occurred. */
		if (divisionCounter == std::numeric_limits<int>::min() && isResultPositive)
		{
			return std::numeric_limits<int>::max();
		}

		return isResultPositive ? -divisionCounter : divisionCounter;
#endif
	}
};

#endif	// _DIVIDE_TWO_INTEGERS_H_