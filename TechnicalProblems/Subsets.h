#pragma once
#ifndef _SUBSETS_H_
#define _SUBSETS_H_

#include "pch.h"

/**
 * Problem: Given a set of distinct integers nums, return all possible subsets.
 *
 * Notes:
 *	1. The solution set must not contain duplicate subsets.
 */
class Subsets
{
public:

	/* This problem can be solved with backtracking. */
	std::vector<std::vector<int>> subsets(std::vector<int> &nums)
	{
		std::vector<std::vector<int>> subsetList;
		std::vector<int> currSubset;

		subsetsHelper(nums, subsetList, currSubset, 0);
		return subsetList;
	}

	/* We only add integers to the subset list that are at startIndex or after so
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