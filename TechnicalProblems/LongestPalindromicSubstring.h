#pragma once
#ifndef _LONGEST_PALINDROMIC_SUBSTRING_H_
#define _LONGEST_PALINDROMIC_SUBSTRING_H_

#include "pch.h"

/**
 * Problem: Given a string s, find the longest palindromic substring in s. You
 * may assume that the maximum length of s is 1000.
 *
 * Note: A palindrome string is a string that reads the same in both directions.
 */
class LongestPalindromicSubstring
{
public:

	/* Take note of the fact that a palindrome will have mirroring characters.
	 * Thus, this problem can be solved by starting at a character, and pushing
	 * outwards towards the left and right sides. Check that the characters on
	 * both the left and right sides are the same. Repeat this process for every
	 * character in the string until the last character in the string has been
	 * scanned. */
	std::string longestPalindrome(std::string inputStr)
	{
		/* Edge Case: If the string is length 0 or 1, then it itself is the
		 * longest palindromic substring. */
		if (inputStr.length() < 2)
		{
			return inputStr;
		}

		std::string longestPalindromicString;

		/* Scan through every character in the string for a possible starting
		 * point for a palindromic substring. */
		for (int palindromeStartIndex = 0; palindromeStartIndex < inputStr.length();
			++palindromeStartIndex)
		{
			/* Case 1: Assume that the palindromic substring is of odd length.
			 * Start scanning at the same character in the middle, and stop looking
			 * when the left and right side characters don't match, or when the
			 * character pointers go past the left or right side of the string. */

			/* Half of the string's length (including the center character). */
			int halfLength = 0;
			for (; palindromeStartIndex + halfLength < inputStr.length() 
				&& palindromeStartIndex - halfLength >= 0; ++halfLength)
			{
				if (inputStr[palindromeStartIndex + halfLength] 
					!= inputStr[palindromeStartIndex - halfLength])
				{
					break;
				}
			}

			/* If the half length of an odd string is equal to half of the string
			 * plus the center character itself, then the full length is equivalent
			 * to twice the half length minus 1. */
			int substringLength = 2 * halfLength - 1;
			if (substringLength > longestPalindromicString.length())
			{
				longestPalindromicString = 
					inputStr.substr(palindromeStartIndex - halfLength + 1, substringLength);
			}

			/* Case 2: Assume that the palindromic substring is of even length. 
			 * Start scanning at the same character, as well as the character
			 * on the right, and stop looking when the left and right side characters
			 * don't match, or when the character pointers go past the left or
			 * right side of the string. */

			/* Half of the string's length. */
			halfLength = 0;
			for (; palindromeStartIndex + halfLength + 1 < inputStr.length() 
				&& palindromeStartIndex - halfLength >= 0; ++halfLength)
			{
				if (inputStr[palindromeStartIndex + halfLength + 1] 
					!= inputStr[palindromeStartIndex - halfLength])
				{
					break;
				}
			}

			substringLength = 2 * halfLength;
			if (substringLength > longestPalindromicString.length())
			{
				longestPalindromicString 
					= inputStr.substr(palindromeStartIndex - halfLength + 1, substringLength);
			}
		}

		return longestPalindromicString;
	}
};

#endif	// _LONGEST_PALINDROMIC_SUBSTRING_H_