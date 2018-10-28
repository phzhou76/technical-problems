#pragma once
#ifndef _COMBINATION_SUM_II_H_
#define _COMBINATION_SUM_II_H_

#include "pch.h"

/**
 * Given a collection of candidate numbers and a target number, find all unique
 * combinations in candidates where the candidate numbers sum to the target 
 * value.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *	1. All numbers including target will be positive integers.
 *	2. Solution set must not contain duplicate combinations.
 *
 * Source: https://leetcode.com/problems/combination-sum-ii/description/
 */
class CombinationSumII
{
public:

	/* Backtracking (Recursive) Solution: Sort the values out, since we cannot 
	 * have duplicate combinations (e.g. 1,7 and 7,1). Then, use DFS to sweep 
	 * through every combination, and backtrack when the current sum becomes 
	 * greater than or equal to the target value.
	 *  
	 * Add the combination to the list if the current sum is equal to the target
	 * value. 
	 */
	std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
		int target)
	{
		/* Because the solution set cannot contain duplicate combinations, we
		 * need to sort the array first. */
		std::sort(candidates.begin(), candidates.end());

		/* If a candidiate has been used, the element in this array 
		 * corresponding to that candidate's index will be set to true. 
		 *
		 * A hash map could also be used too - no sorting of the array would be
		 * necessary if a hash map that mapped candidates to their counts was
		 * used. */
		std::vector<bool> candidatesUsed(candidates.size(), false);
		std::vector<std::vector<int>> combinationSums;
		std::vector<int> currCombination;

		combinationSumHelper(candidates, candidatesUsed, combinationSums, 
			currCombination, target);
		return combinationSums;
	}

	void combinationSumHelper(std::vector<int> &candidates, 
		std::vector<bool> &candidatesUsed,
		std::vector<std::vector<int>> &combinationSums, 
		std::vector<int> &currCombination, int valueLeft)
	{
		/* Base case: The current sum is equal to the target. Note that the
		 * current sum should never be larger than the target, since the 
		 * backtracking algorithm prevents adding numbers to the sum that would 
		 * let the sum exceed the target. */
		if (valueLeft == 0)
		{
			combinationSums.push_back(std::vector<int>(currCombination));
		}

		for (int i = 0; i < candidates.size(); ++i)
		{
			/* Can only use numbers that haven't been used before. */
			if (!candidatesUsed[i])
			{
				/* Only branch to another number if it can be used to approach 
				 * the target value (i.e. the sum between the current sum and 
				 * the number must be less than or equal to the target value. */
				if (candidates[i] <= valueLeft)
				{
					candidatesUsed[i] = true;
					currCombination.push_back(candidates[i]);

					combinationSumHelper(candidates, candidatesUsed, 
						combinationSums, currCombination, 
						valueLeft - candidates[i]);

					/* Pop this value from the back of the array when
					 * backtracking. */
					currCombination.pop_back();
					candidatesUsed[i] = false;
				}
			}
		}
	}
};

#endif	// _COMBINATION_SUM_II_H_