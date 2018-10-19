#pragma once
#ifndef _MINIMUM_EDIT_DISTANCE_H_
#define _MINIMUM_EDIT_DISTANCE_H_

#include "pch.h"

/**
 * Problem: Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * Allowed Operations:
 *	1. Insert a character.
 *	2. Delete a character.
 *	3. Replace a character.
 */
class MinimumEditDistance
{
public:

	/* Dynamic Programming Solution:
	 *
	 * Create a 2D matrix, where word1 is on the x-axis, and word2 is on the y-axis.
	 * Then, set the first row and the first column of the matrix. Take for example:
	 *
	 *		  0 a b c d e f
	 *		0 0 1 2 3 4 5 6
	 *		a 1
	 *		g 2
	 *		c 3
	 *		d 4
	 *		f 5
	 *
	 * Where word1 is abcdef and word2 is agcdf. For example, to transform 'abcde'
	 * to an empty word2, 5 delete operations are required. To transform an empty
	 * word1 to 'agcdf' would require 5 insert operations.
	 *
	 * Then, for each char between word 1 and word2:
	 *	1. If the two chars match, then no operations between the two chars are
	 *		needed. In this case, just take the number of operations to transform
	 *		word1 to word2, excluding these chars. (dp[i - 1][j - 1])
	 *	2. If the two chars do not match, then take the minimum of the operations
	 *		from the top, diagonal, and left (they are all the minimum operations
	 *		needed to transform a part of word1 to a part of word2) and add 1 to it.
	 *
	 *		Minimum of:
	 *			1. dp[i - 1][j] (Top)
	 *			2. dp[i - 1][j - 1] (Diagonal)
	 *			3. dp[i][j - 1] (Left) 
	 */
	int minDistance(std::string word1, std::string word2)
	{
		std::vector<std::vector<int>> dp(word2.size() + 1,
			std::vector<int>(word1.size() + 1, 0));

		/* Initialize dp matrix for the first row and column. */
		for (int col = 1; col < dp[0].size(); ++col)
		{
			dp[0][col] = col;
		}

		for (int row = 1; row < dp.size(); ++row)
		{
			dp[row][0] = row;
		}

		/* Go through each char in word1 for every char in word2 and determine
		 * minimum edit distance. */
		for (int word2Char = 1; word2Char < dp.size(); ++word2Char)
		{
			for (int word1Char = 1; word1Char < dp[word2Char].size(); ++word1Char)
			{
				/* Case 1: If the chars of word1 and word2 match at their respective
				 * positions, then take the minimum number of edits required to
				 * edit the substring before word1Char to the substring before
				 * word2Char. */
				if (word1[word1Char - 1] == word2[word2Char - 1])
				{
					dp[word2Char][word1Char] = dp[word2Char - 1][word1Char - 1];
				}

				/* Case 2: If the chars of word1 and word2 don't match at their
				 * respective positions, then take the minimum of the edits from
				 * word substrings that are at most 1 edit away from them, and
				 * add 1 for this pair of chars. */
				else
				{
					int numberEditsTop = dp[word2Char - 1][word1Char];
					int numberEditsDiagonal = dp[word2Char - 1][word1Char - 1];
					int numberEditsLeft = dp[word2Char][word1Char - 1];

					dp[word2Char][word1Char] = std::min(numberEditsTop,
						std::min(numberEditsDiagonal, numberEditsLeft)) + 1;
				}
			}
		}

		/* Minimum number of edits to transform entirety of word1 into word2 can
		 * be found at the bottom right of the matrix. */
		return dp[word2.length()][word1.length()];
	}
};

#endif	// _MINIMUM_EDIT_DISTANCE_H_