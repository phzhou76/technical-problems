#pragma once
#ifndef _IMPLEMENT_STR_STR_H_
#define _IMPLEMENT_STR_STR_H_

#include "pch.h"

/**
 * Problem: Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if 
 * needle is not part of haystack.
 *
 * Questions:
 *	1. What value should be returned if the needle is empty?
 *	2. What value should be returned if the haystack is empty?
 */
class ImplementStrStr
{
public:
	int strStr(std::string haystack, std::string needle) {
		/* Edge case - if the needle doesn't exist. */
		if (needle.length() == 0)
		{
			return 0;
		}

		/* Scan through the haystack until the first character of the
		 * needle has been encountered in the haystack. Then, scan the
		 * string for needle.length() - 1 characters ahead to see if
		 * a match has been found. If not, then continue to scan the
		 * haystack until the first character of the needle has been
		 * encountered again. */
		for (int i = 0; i < haystack.length(); ++i)
		{
			/* If the first character of the needle has been encountered
			 * in the haystack, then scan ahead in the string to see if
			 * the rest of the needle has a match.
			 *
			 * Check that the length of the current place in the haystack
			 * plus length of needle doesn't go past last character of
			 * haystack. */
			if (haystack[i] == needle[0] && i + needle.length() <= haystack.length())
			{
				for (int j = 0; j < needle.length(); ++j)
				{
					if (haystack[i + j] != needle[j])
					{
						break;
					}

					/* On last iteration, if still looping, then a match
					 * has been found. Return index of start character in
					 * haystack. */
					if (j == needle.length() - 1)
					{
						return i;
					}
				}
			}
		}

		/* Needle was not found in haystack. */
		return -1;
	}
};

#endif	// _IMPLEMENT_STR_STR_H_