#pragma once
#ifndef _SINGLE_NUMBER_H_
#define _SINGLE_NUMBER_H_

#include "pch.h"

/**
 * Problem: Given a non-empty array of integers, every element appears twice
 * except for one. Find that single one.
 * 
 * Note: Your algorithm should have a linear runtime complexity. Could you
 * implement it without using extra memory?
 *
 * Questions:
 *	1. Can an element appear three times in the array?
 */
class SingleNumber
{
public:
	int singleNumber(std::vector<int> &nums)
	{
		/* Approach 1: Use a hash map to keep track of the counts. The numbers
		 * will be added to the hash map when they're encountered for the first
		 * time, and will be removed when they're encountered the second time. 
		 * This means that by the end of the loop, the only element that should
		 * exist in the hash map is the element that only has one copy of it. */
#if 0
		std::unordered_map<int, bool> numCounts;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (numCounts.find(nums[i]) == numCounts.end())
			{
				numCounts[nums[i]] = true;
			}
			else
			{
				numCounts.erase(nums[i]);
			}
		}

		return numCounts.begin()->first;
#endif

		/* Approach 2: Note the following bit manipulation tricks:
		 *		x ^ x = 0
		 *		0 ^ 0 = 0
		 *		x ^ 0 = x
		 * We can use this trick to XOR every number in the array. Each of the
		 * paired numbers will be XORed into 0. Eventually, when all of the pairs
		 * have been XORed, the result will be the single number XOR 0, which
		 * just equals the single number. */
#if 1
		int xorResult = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			xorResult ^= nums[i];
		}

		return xorResult;
#endif
	}
};

#endif	// _SINGLE_NUMBER_H_