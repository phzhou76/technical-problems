#pragma once
#ifndef _LONGEST_SUBSTRING_H_
#define _LONGEST_SUBSTRING_H_

#include "pch.h"

/**
 * Problem: Given a string, find the length of the longest substring without
 * repeating characters.
 */
class LongestSubstring
{
public:
	static int lengthOfLongestSubstring(std::string inputString)
	{
		/* Map of chars to their last seen indices in the string. The indices in
		 * this hash map are only valid if they are within the currently examined
		 * substring; i.e. if the index value is less than the start of the
		 * substring, it should be treated as if it didn't exist.
		 */
		std::unordered_map<char, int> charLastSeen;
		int maxSubstringLength = 0;
		int substringStartIndex = 0;

		/* This can be solved with a sliding window algorithm. Keep a pointer at
		 * the starting char in the substring, which can be used to calculate
		 * the current length of the substring.
		 *
		 * If the char has never been encountered before, then it can be added
		 * to the substring. In addition, if the char has been encountered before,
		 * but its last known place was to the left of the start of the substring,
		 * then it can be added to the substring, since it's guaranteed that no
		 * copies of that char existed in the substring before this char. 
		 *
		 * In either case, the last known position of the char should be updated,
		 * and the length of the substring should be calculated.
		 */
		for (int i = 0; i < inputString.length(); ++i)
		{
			if (charLastSeen.find(inputString.at(i)) == charLastSeen.end()
				|| (charLastSeen[inputString.at(i)] < substringStartIndex))
			{
				charLastSeen[inputString.at(i)] = i;
				int currentSubstringLength = i - substringStartIndex + 1;
				if (currentSubstringLength > maxSubstringLength)
				{
					maxSubstringLength = currentSubstringLength;
				}
			}

			/* However, if the char has been encountered before, and it lies to
			 * the right of the start of the substring, then duplicates of this
			 * char will exist if the current char is added to the substring. 
			 *
			 * Move the start of the substring in front of the previous occurrence
			 * of this char, and update the last known position of this char. */
			else
			{
				substringStartIndex = charLastSeen[inputString.at(i)] + 1;
				charLastSeen[inputString.at(i)] = i;
			}
		}

		return maxSubstringLength;
	}
};

#endif	// _LONGEST_SUBSTRING_H_