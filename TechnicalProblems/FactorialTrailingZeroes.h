#pragma once
#ifndef _FACTORIAL_TRAILING_ZEROES_H_
#define _FACTORIAL_TRAILING_ZEROES_H_

/**
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * Source: https://leetcode.com/problems/factorial-trailing-zeroes/description/
 */
class FactorialTrailingZeroes
{
public:

	/* The trailing zeroes from multiplication comes from 10 being one of the
	 * factors. Thus, we need to find all possible products that have 2 * 5 in
	 * them, like 2 * 2 * 5 = 20, or 2 * 3 * 5 = 30. If we take all possible
	 * numbers in the factorial that have 5 as a factor, then the number of 5s
	 * in the factorial should translate directly to the number of trailing 
	 * zeroes, since there will be more even numbers with a factor of 2 than the
	 * number of numbers with a factor of 5. 
	 *
	 * Take for example, n = 100. How many 5s exist between 1 and 100, 
	 * inclusive? 100 / 5 = 20 numbers with 5 as a factor. However, we also need
	 * to account for the fact that numbers like 25 consist of two factors of 5,
	 * both of  which need to be accounted for in calculating trailing zeroes. 
	 *
	 * Then, we need to see how many times 5^2 fits into 100, which is 4, and 
	 * add those extra 4 factors of 5 into the count. Thus, there are 20 + 4 
	 * trailing zeroes in 100!. 
	 *
	 * Take another example, n = 4617. We start to calculate how many numbers 
	 * have 5^1, then 5^2, etc. until 5^x no longer fits into 4617 
	 * (i.e. n / 5^x = 0).
	 *
	 * 5^1: 4617 / 5 = 923.4, so there are 923 factors of 5. 
	 * 5^2: 4617 / 5^2 = 184.68, so there are 184 additional factors of 5.
	 * 5^3: 4617 / 5^3 = 36.936, so there are 36 additional factors of 5.
	 * ... continue.
	 * 5^6: 4617 / 5^6 = 0.295488, so we can just stop here.
	 *
	 * Add all of the previous factor counts to obtain how many trailing zeroes
	 * exist in n!. 
	 */
	int trailingZeroes(int n)
	{
		int factorCount = 0;
		for (long long i = 5; n / i > 0; i *= 5)
		{
			factorCount += (n / i);
		}

		return factorCount;
	}
};

#endif	// _FACTORIAL_TRAILING_ZEROES_H_