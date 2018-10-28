#pragma once
#ifndef _MAJORITY_ELEMENT_II_H_
#define _MAJORITY_ELEMENT_II_H_

#include "pch.h"

/**
 * Given an integer array of size n, find all elements that appear strictly more
 * than n/3 times. (E.g. if there is an array of 3 elements, an element that
 * appears once doesn't count.)
 *
 * Questions:
 *	1. What should I return if there isn't a majority element? -1 in this case.
 *	2. Should I return all possible elements that appear more than n/3 times, or
 *		just one of them? For this problem, at most two elements can appear more
 *		than n/3 times (two elements would take up greater than 2/3 space).
 *
 * Source: https://leetcode.com/problems/majority-element-ii/description/
 */
class MajorityElementII
{
public:

	/* A simple solution would be to use a hash map that mapped each number to
	 * the number of times that the number appeared in the array. However, to achieve
	 * O(1) space complexity and O(N) runtime complexity, we'll need to use the
	 * Boyer-Moore algorithm, as explained here:
	 *
	 * https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
	 * https://leetcode.com/problems/majority-element-ii/discuss/63537/my-understanding-of-boyer-moore-majority-vote
	 *
	 * The algorithm requires two passes over the input list.
	 *	1. The first pass is used to generate two possible candidate values that
	 *		have a count of greater than N/3.
	 *	2. The second pass is used to count the frequency of those candidate values
	 *		to confirm that the count is greater than N/3.
	 */
	std::vector<int> majorityElement(std::vector<int> &nums)
	{
		if (nums.empty())
		{
			return std::vector<int>();
		}

		/* For this algorithm, we'll need the following values:
		 *	1. Two candidate values, initialized to any value. (Since at most two
		 *		values could have a count greater than N/3.)
		 *	2. Two counts, for each candidate value, initialized to 0. */
		int candidate1 = 0;
		int candidate2 = 0;
		int count1 = 0;
		int count2 = 0;

		/* Generate two possible candidate values that may have a count of greater
		 * than N/3.
		 *
		 * Explanation: Let's say that we want to find the element whose count is
		 * greater than N/2. If there is one, then there is a "pair" between that
		 * majority element and some different value, with some count of the
		 * majority element being "unpaired". So, given a count of this majority
		 * element, each time a different value appears, subtract one from this
		 * majority element to signify that a "pair" has been formed.
		 *
		 * We can expand this example to find at most two elements whose count is
		 * greater than N/3. Assuming that we currently hold two possible candidates
		 * for this majority element, finding a different value from either
		 * candidate will "pair" up the two candidate values and the different
		 * value together. Subtract a count from both candidate values to signify
		 * that a triplet has been formed. If a candidate truly has greater than
		 * N/3 count, then there should be instances of it left over at the end
		 * that aren't paired by different values. */
		for (auto it : nums)
		{
			/* Case 1: This number matches the first candidate. Increase count
			 * of the first candidate. There is now one more of this value that
			 * must be "paired" by a different value. */
			if (it == candidate1)
			{
				++count1;
			}
			/* Case 2: This number matches the second candidate. Increase count
			 * of the second candidate. There is now one more of this value that
			 * must be "paired" by a different value. */
			else if (it == candidate2)
			{
				++count2;
			}
			/* Case 3: The count of the first candidate was decreased to 0, or
			 * the first candidate was never set. This means that the number held
			 * by the first candidate was completely paired up with different
			 * values. Set the first candidate to this number and its count to 1. */
			else if (count1 == 0)
			{
				candidate1 = it;
				count1 = 1;
			}
			/* Case 4: The count of the second candidate was decreased to 0, or
			 * the second candidate was never set. This means that the number held
			 * by the second candidate was completely paired up with different
			 * values. Set the second candidate to this number and its count to 1. */
			else if (count2 == 0)
			{
				candidate2 = it;
				count2 = 1;
			}
			/* Case 5: Both candidates have been set and differ from this value.
			 * Create a triplet between the two candidates and this value, and
			 * subtract a "pairable" count from both candidates. */
			else
			{
				--count1;
				--count2;
			}
		}

		/* Now that we have two possible majority numbers, we need to verify that
		 * both numbers have a count of N/3. If they do, add them to the result. */
		std::vector<int> result;
		count1 = count2 = 0;
		for (auto it : nums)
		{
			if (it == candidate1)
			{
				++count1;
			}
			else if (it == candidate2)
			{
				++count2;
			}
		}

		if (count1 > nums.size() / 3)
		{
			result.push_back(candidate1);
		}

		if (count2 > nums.size() / 3)
		{
			result.push_back(candidate2);
		}

		return result;
	}
};

#endif	// _MAJORITY_ELEMENT_II_H_