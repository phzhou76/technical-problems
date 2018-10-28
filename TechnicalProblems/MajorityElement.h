#pragma once
#ifndef _MAJORITY_ELEMENT_H_
#define _MAJORITY_ELEMENT_H_

#include "pch.h"

/**
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than n/2 times. You may assume that the array
 * is non-empty and the majority element always exists in the array.
 *
 * Source: https://leetcode.com/problems/majority-element/description/
 */
class MajorityElement
{
public:

	/* To have O(nlogn) runtime complexity, and O(1) space complexity, you could also
	 * sort the array and just return the element at index n/2, since the majority is
	 * guaranteed to extend at least n/2 elements. 
	 */
	int majorityElement(std::vector<int> &nums)
	{
#if 0
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
#endif

		/* Boyer-Moore Algorithm Approach: Since the majority number occupies
		 * more than half of the array, we can pair up numbers that have DIFFERENT
		 * values.
		 *
		 * By pairing up different numbers, we assure that the majority number
		 * will be have "unpaired" copies at the end of the loop.
		 */
#if 1
		int majorityCandidate = 0;
		int majorityCandidateCount = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (majorityCandidateCount == 0)
			{
				majorityCandidate = nums[i];
				majorityCandidateCount = 1;
			}
			else if (nums[i] == majorityCandidate)
			{
				++majorityCandidateCount;
			}
			else
			{
				--majorityCandidateCount;
			}
		}

		return majorityCandidate;
#endif
	}
};

#endif	// _MAJORITY_ELEMENT_H_