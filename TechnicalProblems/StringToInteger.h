#pragma once
#ifndef _STRING_TO_INTEGER_H_
#define _STRING_TO_INTEGER_H_

#include "pch.h"

/**
 * Problem: Implement atoi which converts a string to an integer.
 *
 * First, the method should discard as many whitespace characters as necessary
 * until the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral
 * number, which are just ignored.
 *
 * If the first sequence of non-whitespace characters in the string don't form a
 * valid integral number (i.e. (+/-)[0-9]+), or if no such sequence exists because
 * the string is empty or contains only whitespace characters, just return 0.
 *
 * Notes:
 *	1. Only the space character ' ' is considered as a whitespace character.
 *	2. Assume that the range of the 32-bit ints is [-2^31, 2^31 - 1]. If the
 *		numerical value would fall out of the range of these values, return
 *		-2^31 if the number is negative, or 2^31 - 1 if the number is positive.
 */
class StringToInteger
{
public:
	static int myAtoi(std::string inputStr)
	{
		/* Clear through any whitespace first. */
		int numberStartIndex = findNumberStartIndex(inputStr);
		if (numberStartIndex == -1)
		{
			std::cerr << "Error: Invalid non-whitespace characters found at beginning of string." << std::endl;
			return 0;
		}

		/* Determine if the number is positive or negative, and shift the
		 * number start index to a digit. */
		bool isPositive = determineSign(inputStr, &numberStartIndex);
		int convertedInt = 0;

		/* Keep scanning the string for digits until a non-digit char is found. */
		while (numberStartIndex < inputStr.length() && isDigit(inputStr[numberStartIndex]))
		{
			int digit = digitCharToInt(inputStr[numberStartIndex]);

			/* Before shifting the converted int one place to the left, check for overflow. */
			if (checkMultiplyOverflow(convertedInt, 10))
			{
				return isPositive ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
			}

			convertedInt *= 10;

			/* Before adding the digit, check for overflow. */
			if (checkAddOverflow(convertedInt, isPositive ? digit : -digit))
			{
				return isPositive ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
			}

			convertedInt = isPositive ? (convertedInt + digit) : (convertedInt - digit);
			++numberStartIndex;
		}

		return convertedInt;
	}

	static bool checkMultiplyOverflow(int multiplicand, int multiplier)
	{
		/* Overflow is impossible if either the multiplicand or multiplier are 0 or 1. */
		if (multiplicand == 0 || multiplicand == 1 ||
			multiplier == 0 || multiplier == 1)
		{
			return false;
		}

		int allowedMultiplicandBuffer = 0;

		/* Check for positive overflow if the product will be positive. */
		if ((multiplicand > 0 && multiplier > 0) || (multiplicand < 0 && multiplier < 0))
		{
			allowedMultiplicandBuffer = std::numeric_limits<int>::max() / multiplier;
		}

		/* Check for negative overflow if the product will be negative. */
		else
		{
			allowedMultiplicandBuffer = std::numeric_limits<int>::min() / multiplier;
		}

		return allowedMultiplicandBuffer < 0 ? (multiplicand < allowedMultiplicandBuffer)
			: (multiplicand > allowedMultiplicandBuffer);
	}

	static bool checkAddOverflow(int inputInt, int toAddValue)
	{
		/* Overflow is impossible if one input is non-negative and the other is negative. */
		if ((inputInt < 0 && toAddValue >= 0) || (toAddValue < 0 && inputInt >= 0))
		{
			return false;
		}

		int allowedAdditionBuffer = inputInt < 0 ? (std::numeric_limits<int>::min() - inputInt)
			: (std::numeric_limits<int>::max() - inputInt);

		return allowedAdditionBuffer < 0 ? (toAddValue < allowedAdditionBuffer)
			: (toAddValue > allowedAdditionBuffer);
	}

	static bool isDigit(char inputChar)
	{
		int charIntValue = (int)inputChar;
		return charIntValue >= 48 && charIntValue <= 57;
	}

	static int digitCharToInt(char inputChar)
	{
		if (!isDigit(inputChar))
		{
			std::cerr << "Error: Not a digit character." << std::endl;
		}

		return (int)inputChar - 48;
	}

	static int findNumberStartIndex(std::string inputStr)
	{
		/* Sweep until either +/- or [0-9] are found. */
		for (int i = 0; i < inputStr.length(); ++i)
		{
			if (inputStr[i] != ' ')
			{
				int charIntValue = (int)inputStr[i];

				/* Case: If first char after end of whitespace is +/- or [0-9],
				 * then return the index of that char. */
				if (charIntValue == 43 || charIntValue == 45 || isDigit(inputStr[i]))
				{
					return i;
				}
				/* Case: If first char after end of whitespace is not +/- nor [0-9],
				 * then return the error code. */
				else
				{
					return -1;
				}
			}
		}

		/* Case: The string was all whitespaces. */
		return -1;
	}

	static bool determineSign(std::string inputStr, int * numberStartIndex)
	{
		int charIntValue = (int)inputStr[*numberStartIndex];

		/* Negative sign has been found. */
		if (charIntValue == 45)
		{
			(*numberStartIndex)++;
			return false;
		}

		/* Positive sign has been found. */
		else if (charIntValue == 43)
		{
			(*numberStartIndex)++;
			return true;
		}

		/* Numbers have been found. */
		else if (isDigit(inputStr[*numberStartIndex]))
		{
			return true;
		}

		/* Error - invalid chararacter. */
		else
		{
			std::cerr << "Error: Invalid character found." << std::endl;
			return false;
		}
	}
};

#endif	// _STRING_TO_INTEGER_H_