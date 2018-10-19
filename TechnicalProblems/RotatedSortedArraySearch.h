#pragma once
#ifndef _ROTATED_SORTED_ARRAY_SEARCH_H_
#define _ROTATED_SORTED_ARRAY_SEARCH_H_

#include "pch.h"

/**
 * Problem: Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand. For example, [0, 1, 2, 3] became [2, 3, 0, 1].
 * You are given a target value to search for. If the target value is found in
 * the array, return its index. Otherwise, return -1.
 *
 * You may assume that no duplicate values exist in the array.
 * Your algorithm's runtime complexity must be in the order of O(log N).
 */
class RotatedSortedArraySearch
{
public:
	int search(std::vector<int> &nums, int target)
	{
		if (nums.empty())
		{
			return -1;
		}

		int lowIndex = 0;
		int highIndex = nums.size() - 1;

		/* We first want to find the index of the lowest element in the sorted
		 * array (i.e. the original first element in the sorted array before the
		 * rotation). Use binary search to look for this element. */
		while (lowIndex < highIndex)
		{
			/* Calculate the midpoint of the subarray. */
			int midIndex = (lowIndex + highIndex) >> 1;

			/* If the midpoint of this subarray is greater than the rightmost
			 * element of this subarray, then we know that the lowest value lies
			 * somewhere to the right side of the subarray. Recurse to the right
			 * side. */
			if (nums[midIndex] > nums[highIndex])
			{
				lowIndex = midIndex + 1;
			}

			/* If the above condition isn't true, then we know that the rotation
			 * point couldn't have been on the right side, since all elements to
			 * the right are in sequential order (including the middle element).
			 * Recurse onto the left side of the subarray (including the middle
			 * element, since it could be the lowest value element. */
			else
			{
				highIndex = midIndex;
			}
		}

		/* Now that the index of the lowest value element in the array has been
		 * found, we can do normal binary search, but with taking the rotation
		 * into account. */
		int rotationShift = lowIndex;
		lowIndex = 0;
		highIndex = nums.size() - 1;

		while (lowIndex <= highIndex)
		{
			/* Calculate the mid index like you normally would in binary search. */
			int midIndex = (lowIndex + highIndex) >> 1;

			/* Then, use the number of rotations to shift the midIndex to the
			 * correct spot. If the index of the lowest value element was 2, then
			 * the entire array rotated by 2 elements. */
			int realMidIndex = (midIndex + rotationShift) % nums.size();

			/* Use the adjusted mid index to look for the target value. */
			if (nums[realMidIndex] == target)
			{
				return realMidIndex;
			}
			/* We can just adjust the low and high indices of the original array,
			 * since we will always adjust with rotation later. */
			else if (nums[realMidIndex] < target)
			{
				lowIndex = midIndex + 1;
			}
			else
			{
				highIndex = midIndex - 1;
			}
		}

		return -1;
	}
};

#endif	// _ROTATED_SORTED_ARRAY_SEARCH_H_