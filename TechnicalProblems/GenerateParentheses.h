#pragma once
#ifndef _GENERATE_PARENTHESES_H_
#define _GENERATE_PARENTHESES_H_

#include "pch.h"

/**
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * Source: https://leetcode.com/problems/generate-parentheses/description/
 */
class GenerateParentheses
{
public:

	/* Backtracking (Recursive Solution): First, create an empty string and send
	 * in two integers, one for the number of free left parentheses, and the
	 * other for the number of free right parentheses.
	 *
	 * Base Case: If the number of left and right parentheses is 0, then that
	 * means the currently built string has been fully built up. Add the string
	 * to the array of valid parenthesis strings.
	 *
	 * Cases:
	 *	1. If there are still left parentheses remaining to be used, recursively
	 *		call the method with a left parentheses appended, and subtract one
	 *		from the left parentheses count.
	 *	2. If there are still right parentheses remaining to be used AND if there
	 *		are less left parentheses than right parentheses, then recursively
	 *		call the method with a right parentheses appended, and subtract one
	 *		from the right parentheses count.
	 *
	 * We need to check if there are less left parentheses than right parentheses
	 * before attaching a right parentheses to the string because valid
	 * parenthesis pairs require that a left parenthesis exist that hasn't been
	 * "paired up" yet.
	 */
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> parenthesisCombination;
		generateParenthesisHelper("", n, n, parenthesisCombination);

		return parenthesisCombination;
	}

	void generateParenthesisHelper(std::string combinationProgress, int leftParenthesesRemaining,
		int rightParenthesesRemaining, std::vector<std::string> &parenthesisCombinations)
	{
		/* If no parentheses remain for usage, then a full combination has been created. */
		if (leftParenthesesRemaining == 0 && rightParenthesesRemaining == 0)
		{
			parenthesisCombinations.push_back(combinationProgress);
		}

		/* If left parentheses are available for usage, attach them to the string. */
		if (leftParenthesesRemaining > 0)
		{
			generateParenthesisHelper(combinationProgress + "(", leftParenthesesRemaining - 1,
				rightParenthesesRemaining, parenthesisCombinations);
		}

		/* If right parentheses are available for usage, attach them to the string. A right
		 * parenthesis can only be used if a left parenthesis has already been used; i.e.
		 * there are less left parentheses remaining than right parentheses. */
		if (rightParenthesesRemaining > 0 && rightParenthesesRemaining > leftParenthesesRemaining)
		{
			generateParenthesisHelper(combinationProgress + ")", leftParenthesesRemaining,
				rightParenthesesRemaining - 1, parenthesisCombinations);
		}
	}
};

#endif	// _GENERATE_PARENTHESES_H_