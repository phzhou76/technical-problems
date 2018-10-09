#pragma once
#ifndef _MERGE_SORTED_ARRAY_H_
#define _MERGE_SORTED_ARRAY_H_

#include "pch.h"

/**
 * Problem: Given two sorted integer arrays num1 and num2, merge nums2 into nums1
 * as one sorted array.
 *
 * Notes:
 *	1. The number of elements initialized in nums1 and nums2 are m and n,
 *		respectively.
 *	2. You may assume that nums1 has enough space to hold additional elements from
 *		nums2.
 */
class MergeSortedArray
{
public:
	
	/* Similar to the Replace Space problem, we just need to start copying elements
	 * to the back of the array first, since there's empty space there and we want
	 * to avoid overwriting any data. */
	void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
	{
		int nums1Ptr = m - 1;
		int nums2Ptr = n - 1;
		int mergedPtr = m + n - 1;

		while (nums1Ptr >= 0 && nums2Ptr >= 0)
		{
			/* Place the greater of the two values at the back. */
			if (nums1[nums1Ptr] > nums2[nums2Ptr])
			{
				nums1[mergedPtr--] = nums1[nums1Ptr--];
			}
			else
			{
				nums1[mergedPtr--] = nums2[nums2Ptr--];
			}
		}

		/* The elements in num1 have been completely placed into the merged
	     * array. Place the rest of num2 into the merged array. If all elements
		 * in num2 have been placed into the array, then we don't need to do 
		 * anything, since the rest of num1's elements are already there. */
		if (nums1Ptr < 0)
		{
			while (nums2Ptr >= 0)
			{
				nums1[mergedPtr--] = nums2[nums2Ptr--];
			}
		}
	}
};

#endif	// _MERGE_SORTED_ARRAY_H_