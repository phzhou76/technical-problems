#pragma once
#ifndef _SUM_OF_TWO_INTEGERS_H_
#define _SUM_OF_TWO_INTEGERS_H_

/** 
 * Problem: Calculate the sum of two integers a and b, but you are not allowed to
 * use the operator + and -. 
 */
class SumOfTwoIntegers
{
public:

	/* This problem can be solved by calculating the sum and carry of each bit
	 * place between the two number through bit manipulation. The sum between the
	 * two values, if the carry is not taken into factor, can be calculated with
	 * a ^ b. Then, the carry between the two values can be calculated with
	 * a & b
	 * 
	 * The sum between the two values, if the carry is not taken into factor, can
	 * be calculated with a ^ b. 
	 *		0 + 0 = 0
	 *		0 + 1 = 1
	 *		1 + 0 = 1
	 *		1 + 1 = 0 (with carry 1).
	 *
	 * The carry between the two values at each bit can be calculated with a & b.
	 *		0 + 0 = 0
	 *		0 + 1 = 0
	 *		1 + 0 = 0
	 *		1 + 1 = 0
	 *
	 * If the carry is then shifted to the left, the sum and carry values can
	 * then be added together with a ^ carry (without the carry of this current
	 * sum taken into account). The old sum and the old shifted carry can be ANDed
	 * together to calculate the new carry. Repeat until the carry is 0. */
	int getSum(int a, int b)
	{
		int sumWithoutCarry = a ^ b;
		int carry = a & b;

		/* Continue to calculate the sum and the shifted carry until there is no
		 * carry left to add to the sum. */
		while (carry != 0)
		{
			int newSumWithoutCarry = sumWithoutCarry ^ (carry << 1);
			carry = sumWithoutCarry & (carry << 1);
			sumWithoutCarry = newSumWithoutCarry;
		}

		return sumWithoutCarry;
	}
};

#endif	// _SUM_OF_TWO_INTEGERS_H_