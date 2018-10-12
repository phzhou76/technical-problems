#pragma once
#ifndef _PERMUTATIONS_II_H_
#define _PERMUTATIONS_II_H_

#include "pch.h"

/**
 * Problem: Given a collection of numbers that might contain duplicates, return
 * all possible unique permutations.
 */
class PermutationsII
{
public:

	/* This problem can be easily visualized with a trie-like tree. To solve this
	 * problem, we need to keep track of how many of each unique number that we
	 * have to use. Then, because we want to avoid duplicate permutations, we want
	 * to only use unique numbers in the current digit. For example, if the input
	 * was [1, 1, 2], then for each "digit" in the permutation, we would only look
	 * at 1 once and 2 once. Looking at 1 twice would lead to duplicate permutations.
	 * Add the permutation to the list if the permutation has used up all of the
	 * numbers in the input. */
	std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
	{
		/* Count the number of each unique number. */
		std::unordered_map<int, int> uniqueDigitCounts;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (uniqueDigitCounts.find(nums[i]) == uniqueDigitCounts.end())
			{
				uniqueDigitCounts[nums[i]] = 1;
			}
			else
			{
				++uniqueDigitCounts[nums[i]];
			}
		}

		std::vector<std::vector<int>> permutations;
		std::vector<int> currPermutation;
		permuteUniqueHelper(uniqueDigitCounts, permutations, currPermutation,
			nums.size());

		return permutations;
	}

	void permuteUniqueHelper(std::unordered_map<int, int> &uniqueDigitCounts,
		std::vector<std::vector<int>> &permutations, std::vector<int> &currPermutation,
		int numCount)
	{
		/* If the size of the current permutation matches the number of elements
		 * in the input array, then the permutation is finished. */
		if (currPermutation.size() == numCount)
		{
			permutations.push_back(std::vector<int>(currPermutation));
		}

		/* Sweep through each unique number that still has counts left to use. */
		for (auto it : uniqueDigitCounts)
		{
			/* There are still duplicate digits left for use. */
			if (it.second > 0)
			{
				uniqueDigitCounts[it.first] -= 1;
				currPermutation.push_back(it.first);
				permuteUniqueHelper(uniqueDigitCounts, permutations, currPermutation,
					numCount);
				currPermutation.pop_back();
				uniqueDigitCounts[it.first] += 1;
			}
		}
	}
};

#endif	// _PERMUTATIONS_II_H_