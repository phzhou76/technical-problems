#pragma once
#ifndef _INTEGER_TO_ROMAN_H_
#define _INTEGER_TO_ROMAN_H_

#include "pch.h"

/**
 * Given an integer, convert a given integer to its roman numeral representation.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * Source: https://leetcode.com/problems/integer-to-roman/description/
 */
class IntegerToRoman
{
public:

	/* This problem can be solved by extracting each digit from the ones place
	 * to the most significant digit. Each digit is then run through its own
	 * method to convert it to its roman numeral representation. However, this
	 * could be better implemented by only using one method definition instead
	 * of 3. The character patterns between the ones, tens, hundreds, and thousands
	 * digits are exact same; only the actual characters themselves differ.
	 *
	 * For each digit, pass the following characters into the method:
	 *	1. Ones Digit: 'I', 'V', and 'X'.
	 *	2. Tens Digit: 'X', 'L', and 'C'.
	 *	3. Hundreds Digit: 'C', 'D', and 'M'.
	 *	4. Thousands Digit: 'M'. (Other characters don't matter, since the max
	 *		thousands digit is 3.)
	 */
	std::string intToRoman(int num)
	{
		std::string romanNumber = "";

		if (num < 1 || num > 3999)
		{
			return "\nError: Number is out of allowed range.\n";
		}

		/* Sweep from the ones place to the thousands place. */
		for (int digitPlace = 0; num > 0; num /= 10, ++digitPlace)
		{
			int digit = num % 10;

			switch (digitPlace)
			{
			case 0:
				romanNumber = convertOnesPlace(digit) + romanNumber;
				break;
			case 1:
				romanNumber = convertTensPlace(digit) + romanNumber;
				break;
			case 2:
				romanNumber = convertHundredsPlace(digit) + romanNumber;
				break;
			case 3:
			default:
				romanNumber = convertThousandsPlace(digit) + romanNumber;
				break;
			}
		}

		return romanNumber;
	}

	std::string convertOnesPlace(int digit)
	{
		if (digit < 0 || digit > 9)
		{
			return "\nError: Input is not a valid ones digit for roman conversion.\n";
		}

		switch (digit)
		{
			/* Special case: 0s in roman numerals are ignored. */
		case 0:
			return "";
		case 1:
			return "I";
		case 2:
			return "II";
		case 3:
			return "III";
		case 4:
			return "IV";
		case 5:
			return "V";
		case 6:
			return "VI";
		case 7:
			return "VII";
		case 8:
			return "VIII";
		case 9:
		default:
			return "IX";
		}
	}

	std::string convertTensPlace(int digit)
	{
		if (digit < 0 || digit > 9)
		{
			return "\nError: Input is not a valid tens digit for roman conversion.\n";
		}

		switch (digit)
		{
			/* Special case: 0s in roman numerals are ignored. */
		case 0:
			return "";
		case 1:
			return "X";
		case 2:
			return "XX";
		case 3:
			return "XXX";
		case 4:
			return "XL";
		case 5:
			return "L";
		case 6:
			return "LX";
		case 7:
			return "LXX";
		case 8:
			return "LXXX";
		case 9:
		default:
			return "XC";
		}
	}

	std::string convertHundredsPlace(int digit)
	{
		if (digit < 0 || digit > 9)
		{
			return "\nError: Input is not a valid hundreds digit for roman conversion.\n";
		}

		switch (digit)
		{
			/* Special case: 0s in roman numerals are ignored. */
		case 0:
			return "";
		case 1:
			return "C";
		case 2:
			return "CC";
		case 3:
			return "CCC";
		case 4:
			return "CD";
		case 5:
			return "D";
		case 6:
			return "DC";
		case 7:
			return "DCC";
		case 8:
			return "DCCC";
		case 9:
		default:
			return "CM";
		}
	}

	std::string convertThousandsPlace(int digit)
	{
		if (digit < 0 || digit > 3)
		{
			return "\nError: Input is not a valid thousands digit for roman conversion.\n";
		}

		switch (digit)
		{
			/* Special case: 0s in roman numerals are ignored. */
		case 0:
			return "";
		case 1:
			return "M";
		case 2:
			return "MM";
		case 3:
		default:
			return "MMM";
		}
	}
};

#endif	// _INTEGER_TO_ROMAN_H_