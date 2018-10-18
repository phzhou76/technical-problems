#pragma once
#ifndef _WORD_BREAK_H_
#define _WORD_BREAK_H_

#include "pch.h"

/**
 * Problem: Given a non-empty string s and a dictionary wordDict containing a
 * list of non-emptu words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Note: The same word in the dictionary may be reused multiple times in the
 *		segmentation.
 */
class WordBreak
{
public:

	/* This problem can be solved with dynamic programming. Assume that the base
	 * case is true, where the substring of no characters is breakable. Then, if
	 * the element at the ith index is set to true, then the substring from 0 to
	 * i - 1 must have been breakable. */
	bool wordBreak(std::string inputStr, std::vector<std::string> &wordDict)
	{
		std::vector<bool> validSubstring(inputStr.length(), false);
		validSubstring[0] = true;

		for (int i = 0; i < inputStr.length(); ++i)
		{
			/* If the string from the 0th character to the (i-1)th character is
			 * valid, then examine for dictionary words in the rest of the string. */
			if (validSubstring[i])
			{
				for (auto word : wordDict)
				{
					/* Need to check that dictionary word does not go beyond the
					 * boundaries of the string, and that the substring of the
					 * dictionary word's length matches the dictionary word. */
					if (word.length() + i <= inputStr.length()
						&& inputStr.substr(i, word.length()).compare(word) == 0)
					{
						/* If it's a match, then mark the string from 0 to the
						 * (i-1)th character as valid. */
						validSubstring[i + word.length()] = true;
					}
				}
			}
		}

		/* If the string is valid from 0 to (length-1)th character, then it is a
		 * valid word break. */
		return validSubstring[inputStr.length()];
	}
};

#endif	// _WORD_BREAK_H_