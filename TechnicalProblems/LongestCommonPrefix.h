#pragma once
#ifndef _LONGEST_COMMON_PREFIX_H_
#define _LONGEST_COMMON_PREFIX_H_

#include "pch.h"

/**
 * Problem: Write a method to find the longest common prefix string amongst an
 * array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Note: All given inputs are in lowercase letters a-z.
 */
class LongestCommonPrefix
{
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		/* Error: There is no common prefix if no strings are available. */
		if (strs.size() < 1)
		{
			return "";
		}
		/* If only one string is available, then it itself is the common prefix. */
		else if (strs.size() == 1)
		{
			return strs[0];
		}

		std::string commonPrefix = "";

		/* Look at the first character of every string, then the second character,
		 * and so on. For each match, add that character to the prefix string.
		 * Repeat until the shortest string has been completely looked through,
		 * since the shortest string is the longest possible prefix in the array
		 * of strings. */
		int shortestStringLength = findMinimumStringLength(strs);

		for (int i = 0; i < shortestStringLength; ++i)
		{
			/* Just grab the character from the first string for comparison. */
			char prefixChar = strs[0][i];

			/* Compare that character with the character in the same index for each
			 * of the other strings in the array. */
			for (int j = 1; j < strs.size(); ++j)
			{
				if (strs[j][i] != prefixChar)
				{
					return commonPrefix;
				}
			}

			commonPrefix += prefixChar;
		}

		return commonPrefix;
	}

	int findMinimumStringLength(std::vector<std::string> &strings)
	{
		int minStringLength = std::numeric_limits<int>::max();
		for (int i = 0; i < strings.size(); ++i)
		{
			if (strings[i].length() < minStringLength)
			{
				minStringLength = strings[i].length();
			}
		}

		return minStringLength;
	}
};

#endif	// _LONGEST_COMMON_PREFIX_H_