#pragma once
#ifndef _CHECK_PERMUTATION_H_
#define _CHECK_PERMUTATION_H_

/**
 * Problem: Given two strings, write a method to decide if one is a permutation
 * of the other.
 *
 * Questions:
 *	1. Is the algorithm case-sensitive? For example, is lowercase 'a' and uppercase
 *		'a' considered two different characters?
 *	2. What about whitespaces and non-letter characters, like exclamation marks?
 *	3. Is an empty string considered a permutation of another empty string?
 * 
 * The solution assumes that a string is considered to be a permutation of another
 * string if one string has the same number of each unique character as the other
 * string.
 */
class CheckPermutation
{
private:
	static bool checkPermutation(std::string stringA, std::string stringB);
	static bool checkPermutationNoDataStructures(std::string stringA, std::string stringB);

public:
	static void testCheckPermutation();
};

#endif	// _CHECK_PERMUTATION_H_