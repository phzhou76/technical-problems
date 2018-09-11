#pragma once
#ifndef _MAJORITY_ELEMENT_H_
#define _MAJORITY_ELEMENT_H_

#include "pch.h"

/**
 * Problem: Given an array of size n, find the majority element. The majority
 * element is the element that appears more than n/2 times. You may assume that
 * the array is non-empty and the majority element always exists in the array.
 * 
 * To have O(nlogn) runtime complexity, and O(1) space complexity, you could also
 * sort the array and just return the element at index n/2, since the majority is
 * guaranteed to extend at least n/2 elements. */
class MajorityElement
{
public:
	int majorityElement(std::vector<int> &nums)
	{
		/* Holds the numbers and their counts. */
		std::unordered_map<int, int> numberCounts;

		/* Holds the majority number. */
		int currentMajorityNumber = 0;

		/* Holds the current count of the majority number. */
		int currentMajorityNumberCount = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			/* Update the count of this number. */
			if (numberCounts.find(nums[i]) == numberCounts.end())
			{
				numberCounts[nums[i]] = 1;
			}
			else
			{
				++numberCounts[nums[i]];
			}

			/* Check if this number is the new majority number. */
			if (numberCounts[nums[i]] > currentMajorityNumberCount)
			{
				currentMajorityNumber = nums[i];
				currentMajorityNumberCount = numberCounts[nums[i]];
			}
		}

		return currentMajorityNumber;
	}
};

#endif	// _MAJORITY_ELEMENT_H_