#pragma once
#ifndef _SUBSETS_H_
#define _SUBSETS_H_

#include "pch.h"

/**
 * Given a set of distinct integers nums, return all possible subsets (the power
 * set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Source: https://leetcode.com/problems/subsets/description/
 */
class Subsets
{
public:

	/* Backtracking (Recursive) Solution: First, create a list to contain subset
	 * lists, and an empty subset list to represent the current subset being
	 * worked on. Then, pass the list of subsets, and the current subset to the
	 * recursive method.
	 *
	 * Since we need to add all subsets to the list, the current subset will be
	 * immediately added to the list of subsets when the recursive method begins.
	 * We also need to hold the index after that of the last element added to the
	 * current subset (if the current subset was empty, then this index value
	 * will be 0). This will be the start index to add numbers from the array.
	 *
	 * Sweep through the array of numbers starting from that start index (since
	 * all numbers before the start index have been added to a subset already).
	 * For each number, add the number to the current subset, and recursively
	 * call the helper method with the start index adjusted to after the added
	 * number.
	 *
	 * When the method returns, the previous recursive call will backtrack by
	 * popping the value off the current subset and continue to look for other
	 * values to add to the subset.
	 *
	 * Time Complexity: O(2^n), since there are O(2^n) possible subsets that the
	 *		algorithm needs to visit.
	 * Space Complexity: O(n) for recursive call stack, where n is the number of
	 *		elements in the input array.
	 */
	std::vector<std::vector<int>> subsets(std::vector<int> &nums)
	{
		std::vector<std::vector<int>> subsetList;
		std::vector<int> currSubset;

		subsetsHelper(nums, subsetList, currSubset, 0);
		return subsetList;
	}

	/* Only add integers to the subset list that are at startIndex or after so
	 * that we don't create duplicate subsets. */
	void subsetsHelper(std::vector<int> &nums, std::vector<std::vector<int>> &subsetList,
		std::vector<int> &currSubset, int startIndex)
	{
		/* Add this subset to the list of subsets. */
		subsetList.push_back(std::vector<int>(currSubset));

		/* Recurse to a new subset, then backtrack to revert to the old subset. */
		for (int i = startIndex; i < nums.size(); ++i)
		{
			currSubset.push_back(nums[i]);
			subsetsHelper(nums, subsetList, currSubset, i + 1);
			currSubset.pop_back();
		}
	}
};

#endif	// _SUBSETS_H_