#pragma once
#ifndef _REGULAR_EXPRESSION_MATCH_H_
#define _REGULAR_EXPRESSION_MATCH_H_

#include "pch.h"

/**
 * Problem: Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*'.
 *
 * Pattern Rules:
 *	1. '*' matches 0 or more occurrences of the characters before '*'.
 *	2. '.' matches any single character.
 *	3. '.*' matches 0 or more occurrences of any character. (E.g. 'ab' matches '.*').
 *
 * The entire string should match the pattern.
 *
 * Notes:
 *	1. s could be empty, and only contains lowercase letters a-z.
 *	2. p could be empty, and only contains lowercase letters a-z, '.', and '*'.
 *
 * Return true if the string s matches the pattern p, false if it doesn't.
 */
class RegularExpressionMatch
{
public:

	/* Dynamic Programming Solution:
	 *
	 * Create a 2D matrix T of boolean values of rows equal to the length of the
	 * string, and columns equal to the length of the pattern.
	 *
	 * Then, at element T[i][j] in the matrix, where i is the current char in the
	 * string being examined, and j is the current char in the pattern being matched
	 * against:
	 *	1. If T[i][j] is true, then the substring in s ending at the ith char
	 *		matches the pattern in p ending at the jth char.
	 *	2. If T[i][j] is false, then the substring in s ending at the ith char
	 *		does not match the pattern in p ending at the jth char.
	 *
	 * Cases:
	 *	1. If str[i] == pattern[j] OR if pattern[j] == '.', then have T[i][j]
	 *		take on the value at T[i - 1][j - 1]. This is because if the current
	 *		char in the string matches the current char in the pattern, we just
	 *		need to determine if the string up to before the current char matched
	 *		the pattern up to before the current pattern char.
	 *
	 *		If the previous substring was a match, then the previous substring
	 *		plus this char is a match. If the previous substring wasn't a match,
	 *		then the previous substring plus this char won't be a match.
	 *
	 *	2. If the current char in the pattern is a wildcard (pattern[j] == '*'),
	 *		then there are two subcases that we need to check.
	 *
	 *		2a. Check the previous char before the wildcard (i.e. pattern[j - 1]).
	 *			If this previous char matched the current char in the string,
	 *			OR if this previous char was '.', which means it can take on any
	 *			char, then the current char in the string matches the current
	 *			char in the pattern.
	 *
	 *			Look at whether or not the previous char in the string matches
	 *			the wildcard pattern, or T[i - 1][j].
	 *
	 *		2b. However, if the current char doesn't match the previous char before
	 *			the wildcard, then the wildcard pattern will have 0 occurrences.
	 *
	 *			Look at whether or not the current char in the string matches the
	 *			pattern char before the wildcard sequence, or T[i][j - 2].
	 *
	 *	3. If neither of the above two conditions match, then we will set this
	 *		to false, since the current char couldn't possibly match the current
	 *		char in the pattern. */
	bool isMatch(std::string s, std::string p)
	{
		/* Create a 2D matrix that holds the empty pattern + pattern on the column
		 * axis, and holds the empty string + string on the row axis. */
		std::vector<std::vector<bool>> dp(s.length() + 1,
			std::vector<bool>(p.length() + 1, false));

		/* Init first element in matrix as true, since empty string matches empty
		 * pattern. */
		dp[0][0] = true;

		/* Init the first row of the matrix. As a rule, the empty string will not
		 * match against non-wildcard characters, but will match against wildcard
		 * characters. So, if the pattern was a*b*c*d, then the first row would
		 * look like TFTFTFTF, where the true values are set where the wildcard
		 * chars are located. */
		for (int i = 1; i < dp[0].size(); ++i)
		{
			/* Check the corresponding char in the pattern. If it is a wildcard,
			 * then obtain the value from the previous wildcard that was encountered
			 * (or the empty pattern). Otherwise, leave it as false. */
			if (p[i - 1] == '*')
			{
				dp[0][i] = dp[0][i - 2];
			}
		}

		for (int strChar = 1; strChar < dp.size(); ++strChar)
		{
			for (int patternChar = 1; patternChar < dp[0].size(); ++patternChar)
			{
				/* Case 1: If the string char matches pattern char, or if the
				 * pattern char can take in any char, then we need to see whether
				 * or not the string up before the current char matched the pattern
				 * up until before the current pattern char. */
				if (s[strChar - 1] == p[patternChar - 1] ||
					p[patternChar - 1] == '.')
				{
					dp[strChar][patternChar] = dp[strChar - 1][patternChar - 1];
				}

				/* Case 2: Else, if the pattern char is a wildcard char, then we
				 * need to examine two possible subcases:
				 *	1. 0 occurrences of the wildcard char.
				 *	2. 1+ occurrences of the wildcard char. */
				else if (p[patternChar - 1] == '*')
				{
					/* Initially, assume that the number of occurrences of the
					 * wildcard char is 0. Look at whether the current char
					 * matches the pattern before the wildcard pattern. */
					dp[strChar][patternChar] = dp[strChar][patternChar - 2];

					/* Then, see if the current char matches the wildcard char.
					 * If it does, that means that it is the first instance of
					 * the wildcard sequence, or one of the sequential wildcard
					 * instances. Check if the previous character matched the
					 * wildcard pattern.
					 *
					 * As long as the 0-instance pattern or the 1+ instance pattern
					 * works, then this should be set to true. */
					if (p[patternChar - 2] == '.' ||
						s[strChar - 1] == p[patternChar - 2])
					{
						dp[strChar][patternChar] = dp[strChar][patternChar]
							|| dp[strChar - 1][patternChar];
					}
				}

				/* Case 3: The string char doesn't match the pattern char, and
				 * the pattern char is just an a-z char. Set it to false (already
				 * done by initialization. */
			}
		}

		/* Bottom right corner of matrix determines if the entire string matches
		 * the pattern. */
		return dp[dp.size() - 1][dp[0].size() - 1];
	}
};

#endif	// _REGULAR_EXPRESSION_MATCH_H_