#pragma once
#ifndef _NUMBER_OF_ONE_BITS_H_
#define _NUMBER_OF_ONE_BITS_H_

/** 
 * Problem: Write a method that takes in an unsigned integer and returns the number
 * of '1' bits. 
 */
class NumberOfOneBits
{
public:
	int hammingWeight(int n) {
		int bitCount = 0;

		/* Note: n > 0 only works if the input is an unsigned integer. In languages
		 * like Java that do not have unsigned integers, n != 0 should be used instead. */
		while (n != 0)
		{
			/* There is no need to use a conditional statement to determine if 0 or 1
			 * should be added to the bit count, since n & 1 can only give 0 or 1. */
			bitCount += n & 1;
			n = n >> 1;
		}

		return bitCount;
	}
};

#endif	// _NUMBER_OF_ONE_BITS_H_