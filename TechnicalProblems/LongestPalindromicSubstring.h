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

	/* Note that a palindrome has mirroring characters. This problem can be
	 * solved by starting at a character, and pushing outwards towards the
	 * left and right sides. Repeat this process for every character in the
	 * string until the the last character in the string has been scanned. */
	std::string longestPalindrome(std::string inputStr)
	{
		/* Edge case: If the string is length 0 or 1, then it itself is the
		 * longest palindromic substring. */
		if (inputStr.length() < 2)
		{
			return inputStr;
		}

		std::string longestPalindromicString;

		/* Scan through every character in the string for a possible starting
		 * point for a palindromic substring. */
		for (int i = 0; i < inputStr.length(); ++i)
		{
			/* Case 1: Assume that the palindromic substring is of odd length. 
			 * Stop looking when the characters don't match, or when the character
			 * pointers go past the left or right side of the string. */
			int halfLength = 0;
			for (; i + halfLength < inputStr.length() && i - halfLength >= 0; ++halfLength)
			{
				if (inputStr[i + halfLength] != inputStr[i - halfLength])
				{
					break;
				}
			}

			/* Record length of longest odd length palindromic substring that has
			 * the current character as its center. */
			if ((2 * halfLength + 1) > longestPalindromicString.length())
			{
				longestPalindromicString = inputStr.substr(i - halfLength, 2 * halfLength + 1);
			}

			/* Case 2: Assume that the palindromic substring is of even length. */
			halfLength = 0;
			for (; i + halfLength + 1 < inputStr.length() && i - halfLength >= 0; ++halfLength)
			{
				if (inputStr[i + halfLength + 1] != inputStr[i - halfLength])
				{
					break;
				}
			}

			/* Record length of longest even length palindromic substring that has
			 * the current character as part of its center. */
			if ((2 * halfLength) > longestPalindromicString.length())
			{
				longestPalindromicString = inputStr.substr(i - halfLength - 1, 2 * halfLength);
			}
		}

		return longestPalindromicString;
	}
};

#endif	// _LONGEST_PALINDROMIC_SUBSTRING_H_