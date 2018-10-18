#pragma once
#ifndef _SUBSETS_II_H_
#define _SUBSETS_II_H_

#include "pch.h"

/**
 * Problem: Given a collection of numbers that could contain duplicates, return
 * all possible subsets.
 *
 * Notes:
 *	1. The solution set must not contain duplicate subsets.
 */
class SubsetsII
{
	std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
	{
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> subsetList;
		std::vector<int> currSubset;

		subsetsWithDupHelper(nums, subsetList, currSubset, 0);

		return subsetList;
	}

	/* The helper method is the exact same as Subsets, but with a slight modification
	 * to the branching algorithm. */
	void subsetsWithDupHelper(std::vector<int> &nums, std::vector<std::vector<int>> &subsetList,
		std::vector<int> currSubset, int startIndex)
	{
		/* Add the current subset to the list, since we need to add all possible
		 * subsets, not just completely finished ones. */
		subsetList.push_back(std::vector<int>(currSubset));

		/* We needed to sort the nums array originally, since we want to limit
		 * the recursive branching to one per unique value. So, if the input was
		 * 1, 2, 2, we should only be branching out to 1, 2 on the first call. */
		int prevValue = std::numeric_limits<int>::min();

		for (int i = startIndex; i < nums.size(); ++i)
		{
			if (nums[i] != prevValue)
			{
				currSubset.push_back(nums[i]);
				subsetsWithDupHelper(nums, subsetList, currSubset, i + 1);
				currSubset.pop_back();
				prevValue = nums[i];
			}
		}
	}
};

#endif	// _SUBSETS_II_H_