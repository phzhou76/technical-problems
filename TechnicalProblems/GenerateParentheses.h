#pragma once
#ifndef _GENERATE_PARENTHESES_H_
#define _GENERATE_PARENTHESES_H_

#include "pch.h"

/**
 * Problem: Given n pairs of parentheses, write a function to generate all
 * combinations of well-formed parentheses.
 */
class GenerateParentheses
{
public:
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