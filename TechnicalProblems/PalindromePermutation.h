#pragma once
#ifndef _PALINDROME_PERMUTATION_H_
#define _PALINDROME_PERMUTATION_H_

/**
 * Problem: Given a string, write a function to check if it is a permutation of
 * a palindrome. A palindrome is a word or phrase that is the same forwards or
 * backwards. A permutation is a rearrangement of letters. The palindrome does not
 * need to be limited to just dictionary words.
 *
 * Questions:
 *	1. Are certain chars ignored in considering if a string is a permutation of
 *		a palindrome? (For this problem, it seems like whitespace is ignored.)
 *	2. Is capitalization ignored in considering if a string is a permutation of
 *		a palindrome?
 */
class PalindromePermutation
{
private:
	static bool checkIsPermutationOfPalindrome(std::string inputString);
	static bool checkIsPermutationOfPalindromeBitVector(std::string inputString,
		int alphabetSize);
	static int calculateBitVectorSize(int numElements);
	static void toggleBit(std::vector<int> &bitVectors, int bitIndex);
	static bool isValidPalindromePermutation(std::vector<int> &bitVectors);

public:
	static void testPalindromePermutation();
};

#endif	// _PALINDROME_PERMUTATION_H_