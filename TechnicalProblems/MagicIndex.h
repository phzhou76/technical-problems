#pragma once
#ifndef _MAGIC_INDEX_H_
#define _MAGIC_INDEX_H_

#include "pch.h"

/**
 * A magic index in an array A[1...n-1] is defined to be an index such that
 * A[i] = i. Given an array of distinct integers, write a method to find a magic
 * index, if one exists, in array A.
 *
 * Follow-up: What if the values are not distinct?
 *
 * Source: Cracking the Coding Interview, 6th Edition: Problem 8.3
 */
class MagicIndex
{
public:

	/* Binary Search Solution: A brute force way of solving this problem is to
	 * sweep through the entire array and examine each index and its element,
	 * which would result in a O(n) runtime. However, this solution also works
	 * for unsorted arrays, so there should a faster runtime given that the input
	 * is sorted.
	 *
	 * Let's start with an example:
	 *
	 *		Values:		-7 -5 -2 -1 0 4 5 7 9 12 15
	 *		Indices:	 0  1  2  3 4 5 6 7 8  9 10
	 *
	 * We can see that the magic index of this array is 7. Additionally, we can
	 * also see the following patterns:
	 *
	 *	1. All indices greater than the magic index must contain values greater
	 *		than their respective index. If they were less than their respective
	 *		index, it would violate the sorting of the array (e.g. index 8 having
	 *		a value of 6 or lower). If they were equal to their respective index,
	 *		then more than one magic index exists.
	 *
	 *	2. All indices less than the magic index must contain values less than
	 *		their respective index. If they were greater than their respective
	 *		index, it would violate the sorting of the array (e.g. index 6 having
	 *		a value of 8 or greater). If they were equal to their respective
	 *		index, then more than one magic index exists.
	 *
	 * This means that a binary search algorithm can be implemented to find the
	 * magic index of the array, if it exists. Start at the middle of the array,
	 * and compare the middle value with its index.
	 *
	 *	1. If the middle value is less than its index, then the magic index must
	 *		lie to the right. Recurse onto the right subarray.
	 *
	 *	2. If the middle value is greater than its index, then the magic index
	 *		must lie to the left. Recurse onto the left subarray.
	 *
	 *	3. If the middle value is equal to its index, then the magic index has
	 *		been found.
	 *
	 * Time Complexity: O(log n), where n is the number of elements in the array.
	 * Space Complexity: O(1).
	 */
	int findMagicIndex(std::vector<int> nums)
	{
		int lowIndex = 0;
		int highIndex = nums.size() - 1;

		while (lowIndex <= highIndex)
		{
			int midIndex = (lowIndex + highIndex) / 2;

			/* Case 1: If the middle value is lower than the index, then the
			 * magic index will be somewhere on the right subarray. */
			if (nums[midIndex] < midIndex)
			{
				lowIndex = midIndex + 1;
			}

			/* Case 2: If the middle value is higher than the index, then the
			 * magic index will be somewhere on the left subarray. */
			else if (nums[midIndex] > midIndex)
			{
				highIndex = midIndex - 1;
			}

			/* Case 3: If the middle vlaue is equal to the index, then the magic
			 * index has been found. */
			else
			{
				return midIndex;
			}
		}

		return -1;
	}

	/* Binary Search Solution: This solution requires a little more adjusting if
	 * the values are not distinct. Take the following example:
	 *
	 *		Values:		2 2 2 2 2 2 2
	 *		Indices:	0 1 2 3 4 5 6
	 *
	 * If the original algorithm was used, then it would look at the middle index,
	 * and try to look at the values on the right subarray. However, the actual
	 * magic index is located on the left subarray at index 2. Thus, if there are
	 * duplicate values in the sorted array, then both subarrays will have to be
	 * examined.
	 *
	 * However, there is an optimization that can be made when looking at both
	 * subarrays. Given the value of the middle index:
	 *
	 *	1. For the right subarray, start at the maximum between the middle value
	 *		and the index [middle + 1]. If the middle value was greater than the
	 *		index [middle + 1], then because of the sorted nature of the array,
	 *		the magic index could not possibly be found before the index that
	 *		equals the middle value.
	 *
	 *	2. For the left subarray, end at the minimum between the middle value and
	 *		the index [middle - 1]. If the middle value was less than the index
	 *		[middle - 1], then because of the sorted nature of the array, the
	 *		magic index could not possibly be found after the index that equals
	 *		the middle value.
	 *
	 * Note that this solution still works even with a sorted array of distinct
	 * elements.
	 *
	 * Time Complexity: O(log n), where n is the number of elements in the array.
	 * Space Complexity: O(log n) for recursive call stack, where n is the number
	 *		of elements in the array.
	 */
	int findMagicIndexDuplicates(std::vector<int> nums)
	{
		return findMIDHelper(nums, 0, nums.size() - 1);
	}

	int findMIDHelper(std::vector<int> &nums, int low, int high)
	{
		/* Edge Case: No more elements in this subarray. */
		if (high < low)
		{
			return -1;
		}

		int mid = (low + high) / 2;

		/* Case 1: Magic index was found. */
		if (nums[mid] == mid)
		{
			return mid;
		}

		int leftHighIndex = std::min(mid - 1, nums[mid]);
		int rightLowIndex = std::max(mid + 1, nums[mid]);

		/* Case 2: Explore the left subarray. Return immediately if the left
		 * subarray returns the location of the magic index. */
		int leftResult = findMIDHelper(nums, low, leftHighIndex);
		if (leftResult != -1)
		{
			return leftResult;
		}

		int rightResult = findMIDHelper(nums, rightLowIndex, high);
		return rightResult;
	}
};

#endif	// _MAGIC_INDEX_H_