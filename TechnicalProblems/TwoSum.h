#pragma once
#ifndef _TWO_SUM_H_
#define _TWO_SUM_H_

#include "pch.h"

/**
 * Problem: Given an array of integers, return indices of the two numbers such
 * that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you cannot
 * use the same element in the array twice.
 */
class TwoSum
{
public:
	static std::vector<int> twoSum(std::vector<int>& nums, int target) {
		/* Map of a number to its index. */
		std::unordered_map<int, int> elementToIndex;
		std::vector<int> sumPair;

		for (int i = 0; i < nums.size(); ++i)
		{
			/* Check if the complementing value doesn't already exist in hash map. */
			int complementValue = target - nums.at(i);

			/* Sum values have been found. */
			if (elementToIndex.find(complementValue) != elementToIndex.end())
			{
				return std::vector<int> {elementToIndex.at(complementValue), i};
			}

			/* Else, possible that complementing value will come later, cache the value. */
			elementToIndex.insert(std::pair<int, int>(nums.at(i), i));
		}

		/* No pair was found that sums up to the target value. */
		return std::vector<int>();
	}
};

#endif	// _TWO_SUM_H_