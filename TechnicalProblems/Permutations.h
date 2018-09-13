#pragma once
#ifndef _PERMUTATIONS_H_
#define _PERMUTATIONS_H_

#include "pch.h"

/**
 * Problem: Given a collection of distinct integers, return all possible
 * permutations.
 */
class Permutations
{
public:
	std::vector<std::vector<int>> permute(std::vector<int> &nums)
	{
		/* Holds the list of permutations. */
		std::vector<std::vector<int>> permutationList;

		/* Marks whether or not the number at the given index was used. */
		std::vector<bool> isNumberUsed(nums.size(), false);

		/* Holds the current permutation being generated. */
		std::vector<int> currentPermutation;

		permuteHelper(nums, permutationList, isNumberUsed, currentPermutation);
		return permutationList;
	}

	void permuteHelper(std::vector<int> &nums,
		std::vector<std::vector<int>> &permutationList,
		std::vector<bool> &isNumberUsed,
		std::vector<int> &currentPermutation)
	{
		/* Base case: The current permutation is the length of the entire list
		 * of numbers. A valid permutation must have been created. */
		if (currentPermutation.size() == nums.size())
		{
			permutationList.push_back(std::vector<int>(currentPermutation));
		}

		/* If the permutation isn't complete, sweep through the list of available
		 * numbers. For each number that hasn't been used yet, temporarily add
		 * them to the currently generated permutation, mark the number as used
		 * and recursively call the method. When the method returns, all permutations
		 * that have the current sequence of numbers have been generated, so we
		 * can safely pop the number from the permutation and set the number as
		 * available. */
		for (int i = 0; i < isNumberUsed.size(); ++i)
		{
			if (!isNumberUsed[i])
			{
				isNumberUsed[i] = true;
				currentPermutation.push_back(nums[i]);
				permuteHelper(nums, permutationList, isNumberUsed, currentPermutation);
				currentPermutation.pop_back();
				isNumberUsed[i] = false;
			}
		}
	}
};

#endif	// _PERMUTATIONS_H_