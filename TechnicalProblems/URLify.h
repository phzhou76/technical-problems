#pragma once
#ifndef _URLIFY_H_
#define _URLIFY_H_

#include "pch.h"

/**
 * Problem: Write a method to replace all spaces in a string with '%20'. You may
 * assume that the string has sufficient space at the end to hold the additional
 * characters, and that you are given the "true" length of the string.
 *
 * Questions:
 *	1. Does the "true" length of the string refer to the length of the string
 *		with the spaces in it, or the length of the entire character array?
 *	2. Is the string to be changed in-place, i.e. no extra copy of the string
 *		can be created?
 */
class URLify
{
private:

	/**
	 * Implementation with no extra data structures, assuming that the entire char
	 * array can hold the updated string plus the null char to signify the end of the
	 * C string. Note: The input C string must be instantiated in non-read-only memory,
	 * i.e. instantiated with char a[] or char *a = malloc().
	 */
	static void replaceSpaces(char * inputString, int stringLength)
	{
		if (inputString == nullptr)
		{
			throw std::invalid_argument("Input string is null.");
		}

		int spaceCount = 0;
		for (int i = 0; i < stringLength; ++i)
		{
			if (inputString[i] == ' ')
			{
				++spaceCount;
			}
		}

		int arrayLength = stringLength + (2 * spaceCount);
		inputString[arrayLength] = '/0';

		char * oldStringPtr = inputString + (stringLength - 1);
		char * newStringPtr = inputString + (arrayLength - 1);

		/* In general, when modifying a data structure, it's better to modify any empty
		 * buffer space first to avoid overwriting data. In this case, the string should
		 * be copied from the back to the start of the string, since an empty buffer
		 * is available at the end of the string.
		 */
		while (oldStringPtr >= inputString && newStringPtr >= inputString)
		{
			if (*oldStringPtr == ' ')
			{
				*newStringPtr-- = '0';
				*newStringPtr-- = '2';
				*newStringPtr-- = '%';
				--oldStringPtr;
			}
			else
			{
				*newStringPtr-- = *oldStringPtr--;
			}
		}
	}
};

#endif	// _URLIFY_H_