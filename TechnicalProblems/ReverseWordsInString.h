#pragma once
#ifndef _REVERSE_WORDS_IN_STRING_H_
#define _REVERSE_WORDS_IN_STRING_H_

#include "pch.h"

/**
 * Problem: Given an input string, reverse the string word by word.
 *
 * Notes:
 *	1. A word is defined as a sequence of non-space characters.
 *	2. Input string may contain leading or trailing spaces. However, your reversed
 *		string should not contain leading or trailing spaces.
 *	3. You need to reduce multiple spaces between words to a single space in the
 *		reversed string.
 *
 * Questions:
 *	1. Do characters other than a-z count as non-space characters? E.g. '@'.
 */
class ReverseWordsInString
{
public:

	/* This problem can be solved in a 3-step process to achieve a O(n) runtime
	 * and a O(1) space complexity.
	 *	1. Reverse the original string such that the words are in their correct
	 *		positions, but the characters in each string are reversed.
	 *	2. Reverse each word in the string so that the characters are now in their
	 *		correct positions.
	 *	3. Finally, scan to delete any extra whitespaces that might exist. */
	void reverseWords(std::string &s)
	{
		
	}
};

#endif	// _REVERSE_WORDS_IN_STRING_H_