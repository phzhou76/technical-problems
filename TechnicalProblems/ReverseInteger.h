#pragma once
#ifndef _REVERSE_INTEGER_H_
#define _REVERSE_INTEGER_H_

#include "pch.h"

/**
 * Problem: Given a 32-bit signed integer, reverse the digits of the integer, and 
 * return the result as an integer.
 *
 * Note: Assume that the problem is given in an environment which stores 32-bit
 * integers in the range [-2^31, 2^31 - 1]. If the reversed integer would overflow,
 * return 0 instead.
 */
class ReverseInteger
{
public:
	int reverse(int inputInt)
	{
		/* Count the number of digits first to parse in reverse order. */
		int numDigits = countDigits(inputInt);
		int reversedInput = 0;

		std::cout << numDigits << std::endl;
		for (int i = numDigits - 1; i >= 0; --i)
		{
			/* Negative numbers work with modulus; i.e. -4 % 10 is -4. */
			int digit = inputInt % 10;

			/* Check if digit * 10^i will overflow. */
			if (checkOverflow(digit, i))
			{
				return 0;
			}

			int toAddValue = digit * (int)std::pow(10, i);

			/* Check if adding the two numbers would overflow. */
			if (checkAddOverflow(reversedInput, toAddValue))
			{
				return 0;
			}

			reversedInput += toAddValue;
			inputInt /= 10;
		}

		return reversedInput;
	}

	bool checkOverflow(int digit, int exponent)
	{
		int digitAbs = std::abs(digit);

		/* Error: Input digit's absolute value was 10 or greater. */
		if (digitAbs < 0 || digitAbs >= 10)
		{
			std::cerr << "Error: Input digit's absolute value was greater or equal to 10." << std::endl;
			return true;
		}

		/* Digit * 10^i should only overflow if total is greater than 2,000,000,000;
		 * i.e. i must be greater than 8, and the absolute value of the digit must
		 * be greater than 2. */
		return exponent > 8 && digitAbs > 2;
	}

	bool checkAddOverflow(int originalValue, int toAddValue)
	{
		/* Case 1: If the value that will be added onto the original value is 
		 * positive, then a positive overflow needs to be checked, since a negative
		 * overflow is not possible.
		 * Case 2: If the value that will be added onto the original value is 
		 * negative, then a negative overflow needs to be checked, since a positive
		 * overflow is not possible. */
		int bufferValueRemaining = toAddValue < 0 ? std::numeric_limits<int>::min()
			: std::numeric_limits<int>::max();
		bufferValueRemaining -= toAddValue;

		/* Case 1: If the buffer value is positive, then the original value must
		 * be less than the buffer value, since it would result in a positive 
		 * overflow if the original value was greater than the buffer value and 
		 * if the value was added onto by the positive toAddValue.
		 * Case 2: If the buffer value is negative, then the original value must
		 * be greater than the buffer value, since it would result in a negative
		 * overflow if the original value was less than the buffer value and if 
		 * the value was "subtracted" by the negative toAddValue. */
		return bufferValueRemaining < 0 ? (originalValue < bufferValueRemaining) :
			(originalValue > bufferValueRemaining);
	}

	int countDigits(int inputInt)
	{
		/* Because the input integer can be negative, the digit counting must 
		 * continue while the input integer's division by 10 result is not 
		 * explicitly 0; i.e. inputInt > 0 doesn't work for negative integers 
		 * because the condition will fail on the first digit. */
		int digitCount = 0;
		do
		{
			++digitCount;
			inputInt /= 10;
		} while (inputInt != 0);

		return digitCount;
	}
};

#endif	// _REVERSE_INTEGER_H_