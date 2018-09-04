#pragma once
#ifndef _PALINDROME_NUMBER_H_
#define _PALINDROME_NUMBER_H_

#include "pch.h"

/**
 * Problem: Determine whether or not an integer is a palindrome. An integer is a
 * palindrome if it is read the same forwards or backwards. This means that negative
 * numbers cannot be palindromes, as the negative sign is included as a part of
 * the integer in determining if it is a palindrome or not. */
class PalindromeNumber
{
public:
	static bool isPalindrome(int inputInt) {
		/* Negative numbers cannot be palindromes. */
		if (inputInt < 0)
		{
			return false;
		}

		/* Single digit numbers are always palindromes. */
		if (inputInt >= 0 && inputInt <= 9)
		{
			return true;
		}

		std::vector<int> digits;

		/* Extract the digits of the number. */
		do
		{
			digits.push_back(inputInt % 10);
			inputInt /= 10;
		} while (inputInt != 0);

		for (int i = 0; i < digits.size() / 2; ++i)
		{
			int leftDigit = digits[i];
			int rightDigit = digits[digits.size() - 1 - i];
			
			/* Opposing digits do not match up. */
			if (leftDigit != rightDigit)
			{
				return false;
			}
		}

		return true;
	}
};

#endif	// _PALINDROME_NUMBER_H_