#pragma once
#ifndef _IS_UNIQUE_H_
#define _IS_UNIQUE_H_

#include <string>

/**
 * Problem: Implement an algorithm to determine if a string has all unique
 * characters. What if you cannot use additional data structures?
 *
 * Questions:
 *	1. What char set is being used?
 *	2. Can I assume that standard sorting algorithms will not use additional
 *		data structures?
 *	3. Is the algorithm case sensitive?
 */
class IsUnique
{
private:
	static bool determineIsUnique(std::string inputString);
	static bool determineIsUnique(std::string inputString, const int alphabetSize);
	static bool determineIsUniqueBitVector(std::string inputString, const int alphabetSize);
	static int determineBitVectorSize(const int alphabetSize);
	static bool getBit(std::vector<int> &bitVectors, int charValue);
	static void setBit(std::vector<int> &bitVectors, int charValue, bool setValue);
	static bool determineIsUniqueNoDataStructures(std::string inputString);

public:
	static void testIsUnique();
};

#endif	// _IS_UNIQUE_H_