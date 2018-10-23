#pragma once
#ifndef _SUBSETS_II_H_
#define _SUBSETS_II_H_

#include "pch.h"

/**
 * Given a collection of integers that might contain duplicates, nums, return all
 * possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Source: https://leetcode.com/problems/subsets-ii/description/
 */
class SubsetsII
{
	/* Backtracking (Recursive) Solution: This solution uses the same exact
	 * approach as if the input had all distinct numbers, with some slight
	 * modifications.
	 *
	 * Instead of just adding numbers from the array, we need to use a hash map
	 * to add unique numbers at each recursive call. Thus, we will use a hash
	 * map to contain each unique number with the available counts left for it.
	 *
	 * Another approach is to use a sorting algorithm to sort the original array
	 * of numbers so duplicate values are located next to each other. Only
	 * recursively call on a new subset if the current value is different from
	 * the previous value that was used for a recursive call.
	 *
	 * Time Complexity: O(2^n), since there are 2^n possible subsets that we
	 *		need to calculate.
	 * Space Complexity: O(n) for the recursion call stack, since the recursion
	 *		has a max depth of n, where the current subset consists of all
	 *		numbers.
	 */
	std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
	{
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> subsetList;
		std::vector<int> currSubset;

		subsetsWithDupHelper(nums, subsetList, currSubset, 0);

		return subsetList;
	}

	/* The helper method is the exact same as Subsets, but with a slight
	 * modification to the branching algorithm. */
	void subsetsWithDupHelper(std::vector<int> &nums,
		std::vector<std::vector<int>> &subsetList,
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