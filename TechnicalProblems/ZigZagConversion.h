#pragma once
#ifndef _ZIG_ZAG_CONVERSION_H_
#define _ZIG_ZAG_CONVERSION_H_

#include "pch.h"

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern as follows:
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * Which is then read as "PAHNAPLSIIGYIR". Write code that will take a string and
 * make this conversion given a number of rows.
 */
class ZigZagConversion
{
public:
	static std::string convert(std::string inputString, int numRows)
	{
		/* Nothing to convert if the string's length is less than 3, or if there
		 * are less than two rows, since the output would be the same. */
		if (inputString.length() < 3 || numRows < 2)
		{
			return inputString;
		}

		int rowModulus = (numRows - 1) * 2;
		std::string convertedString = "";

		/* Convert row by row; each row has its own unique index modulus value(s). */
		for (int i = 0; i < numRows; ++i)
		{
			/* Start and end rows only have one index modulus value. */
			if (i == 0 || i == numRows - 1)
			{
				for (int index = i; index < inputString.length(); index += rowModulus)
				{
					convertedString += inputString[index];
				}
			}
			else
			{
				/* For each left index, there could be a right index. But for
				 * every right index, there must be a left index. */
				for (int leftIndex = i; leftIndex < inputString.length(); leftIndex += rowModulus)
				{
					convertedString += inputString[leftIndex];
					int rightIndex = leftIndex + rowModulus - 2 * i;
					if (rightIndex < inputString.length())
					{
						convertedString += inputString[rightIndex];
					}
				}
			}
		}

		return convertedString;
	}
};
#endif	// _ZIG_ZAG_CONVERSION_H_