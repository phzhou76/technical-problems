#pragma once
#ifndef _REVERSE_STRING_H_
#define _REVERSE_STRING_H_

#include "pch.h"

/** 
 * Problem: Write a method that takes a string as an input and returns the string
 * reversed.
 */
class ReverseString
{
public:
	std::string reverseString(std::string inputString)
	{
		/* When reversing something, the element swapping should only go to the
		 * half of the array, or else the reversed elements will be reversed 
		 * again. */
		for (int i = 0; i < inputString.length() / 2; ++i)
		{
			char tmpChar = inputString[i];
			inputString[i] = inputString[inputString.length() - 1 - i];
			inputString[inputString.length() - 1 - i] = tmpChar;
		}

		return inputString;
	}
};

#endif	// _REVERSE_STRING_H_