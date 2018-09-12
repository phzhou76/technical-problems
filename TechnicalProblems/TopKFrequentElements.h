#pragma once
#ifndef _TOP_K_FREQUENT_ELEMENTS_H_
#define _TOP_K_FREQUENT_ELEMENTS_H_

#include "pch.h"

/**
 * Problem: Given a non-empty array of integers, return the k most frequent elements.
 *
 * Note: You may assume k is always valid, 1 <= k <= number of unique elements.
 * Note: Your algorithm's time complexity must be better than O(nlogn), where
 *		n is the array's size.
 */
class TopKFrequentElementsComparator
{
public:

	/* A comparison should return true if the first element should be placed at
	 * a lower priority than the second (i.e. the second element will be popped
	 * sooner). In this case, the comparator is saying that if the first element
	 * is less than the second element, it will be placed at a lower priority
	 * than the second. This ensures a max heap. */
	int operator() (const std::pair<int, int> &numPair1,
		const std::pair<int, int> &numPair2)
	{
		return numPair1.second < numPair2.second;
	}
};

class TopKFrequentElements
{
public:

	/* This is a O(klogk) solution, where k is the number of unique numbers in
	 * the array. */
	std::vector<int> topKFrequent(std::vector<int> &nums, int k)
	{
		/* Maps each number to the count of it. */
		std::unordered_map<int, int> numberCounts;

		/* Gather the counts of each number. */
		for (int i = 0; i < nums.size(); ++i)
		{
			if (numberCounts.find(nums[i]) == numberCounts.end())
			{
				numberCounts[nums[i]] = 1;
			}
			else
			{
				++numberCounts[nums[i]];
			}
		}

		/* Create a max heap that sorts by the number count of each pair of
		 * {number, number count}. */
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
			TopKFrequentElementsComparator> maxHeap;

		for (auto it = numberCounts.begin(); it != numberCounts.end(); ++it)
		{
			maxHeap.push(std::pair<int, int>(it->first, it->second));
		}

		/* Extract the top k most frequent numbers from the max heap. */
		std::vector<int> kMostFrequentNumbers;
		for (int i = k; i > 0; --i)
		{
			kMostFrequentNumbers.push_back(maxHeap.top().first);
			maxHeap.pop();
		}

		return kMostFrequentNumbers;
	}
};

#endif	// _TOP_K_FREQUENT_ELEMENTS_H_