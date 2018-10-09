#pragma once
#ifndef _SQUARE_ROOT_H_
#define _SQUARE_ROOT_H_

/**
 * Problem: Implement int sqrt(int x). Compute and return the square root of x,
 * where x is guaranteed to be a non-negative integer. Since the return type is 
 * an integer, the decimal digits are truncated and only the integer part of the
 * result is returned. 
 */
class SquareRoot
{
public:

	/* First, notice that the square root of a number must be less than or equal
	 * to half of that number. Thus, we have a possible range for the square root
	 * from 1 to x/2. We can perform binary search on this range by starting at
	 * the middle number between 1 and x/2 (call it n). If n^2 is greater than
	 * x, then we can recurse over to the left side. If n^2 is lesser than x, then
	 * we can recurse over to the right side. Stop when the lower and upper numbers
	 * of the range are equal to each other. If n^2 is still greater than x by
	 * then, then subtract 1 from it to floor the value. */
	int sqrt(int x)
	{
		if (x == 0)
		{
			return 0;
		}
	}
};

#endif	// _SQUARE_ROOT_H_
