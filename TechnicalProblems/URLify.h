#pragma once
#ifndef _URLIFY_H_
#define _URLIFY_H_

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
	static void replaceSpaces(char * inputString, int stringLength);
};

#endif	// _URLIFY_H_