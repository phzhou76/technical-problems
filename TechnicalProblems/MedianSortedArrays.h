#pragma once
#ifndef _MEDIAN_SORTED_ARRAYS_H_
#define _MEDIAN_SORTED_ARRAYS_H_

#include "pch.h"

/**
 * Problem: There are two sorted arrays nums1 and nums2 of size m and n, respectively.
 * Find the median of the two sorted arrays. The runtime complexity should be
 * O(log(m+n)). It is safe to assume that the arrays cannot be both empty.
 */
class MedianSortedArrays
{
public:

	/**
	 * A median is defined as a value that divides a set into two equal length
	 * subsets, where all values in one subset are greater than all values in
	 * another subset.
	 *
	 * With that definition in mind, we will first divide num1 (length m) into
	 * two parts at a random position i, like such:
	 *
	 *				  num1_left 		|		num1_right
	 *			num1[0] .. num1[i-1]	|	num1[i] .. num1[m-1]
	 * Length:			i							m - i
	 *
	 * If array num1 has m elements, then there are m + 1 ways to divide the array
	 * into left and right subsets (think of placing a border between each element).
	 * Note, if i is 0, then the left subset is empty, and if i is m, then the
	 * right subset is empty.
	 *
	 * We will then divide num2 (length n) into two parts at a random position j,
	 * like such:
	 *
	 *				  num2_left 		|		num2_right
	 *			num2[0] .. num2[j-1]	|	num2[j] .. num2[n-1]
	 * Length:			j							n - j
	 *
	 * Then, place num1's left subset and num2's left subset into the same set,
	 * and num1's right subset and num2's right subset into the same set.
	 *
	 *				 left_subset 		|		right_subset
	 *			num1[0] .. num1[i-1]	|	num1[i] .. num1[m-1]
	 *			num2[0] .. num2[j-1]	|	num2[j] .. num2[n-1]
	 * Length:			i + j				 (m - i) + (n - j)
	 *
	 * To fit the definition of a median, we need to ensure the following:
	 *	1. Length(left_subset) == Length(right_subset)
	 *	2. Max(left_subset) <= Min(right_subset)
	 *
	 * This ensures that the arrays are divided up in such a way that the combination
	 * of their left subsets is equal in numbers as the combination of their right
	 * subsets, and that all elements in the left subset are less than all elements
	 * in the right subset.
	 *
	 * If these two conditions are met, then the median can be calculated as follows:
	 *			median = (max(left_subset) + min(right_subset)) / 2
	 *
	 * To ensure that the length of the left_subset and right_subset are equal,
	 * the following equalities need to be kept:
	 *
	 *				i + j = (m - i) + (n - j)
	 *	Rearranged: j = (m + n)/2 - i
	 *
	 * To ensure that all elements in the left_subset are less than the right_subset,
	 * the following equalities need to be kept:
	 *
	 *				num1[i-1] <= num1[i]	This is a given, num1 is sorted.
	 *				num1[i-1] <= num2[j]	NEEDS TO BE CHECKED.
	 *				num2[j-1] <= num2[j]	This is a given, num2 is sorted.
	 *				num2[j-1] <= num1[i]	NEEDS TO BE CHECKED.
	 *
	 * Next, we need to find a value i in [0, m] such that the above conditions
	 * are true. The value j can be calculated from i like such:
	 *				j = (m + n + 1)/2 - i
	 * (Add the extra 1 to account for indices.)
	 *
	 * Use binary search to find the right value for i:
	 *	1. Set i_min = 0 and i_max = m, then start searching in [i_min, i_max].
	 *	2. Set i = (i_min + i_max)/2, and j = (m + n + 1)/2 - 1.
	 *		2a. This will create values for i and j that ensure that the length
	 *			of left_subset and right_subset are equal.
	 *	3. The following situations are possible:
	 *		3a. num1[i-1] <= num2[j] AND num2[j-1] <= num1[i]
	 *			This situation means that all values in left_subset are less than
	 *			those in right_subset. The correct value for i has been found.
	 *		3b. num2[j-1] > num1[i]
	 *			This situation means that some values in left_subset are greater
	 *			than those in right_subset. The value of i needs to be increased
	 *			and the value of j decreased, which shifts lower values from num1
	 *			over to left_subset, and shifts higher values from num2 over to
	 *			right_subset.
	 *			Adjust the binary search range to [i + 1, i_max], and go back to
	 *			step 2.
	 *		3c. num1[i-1] > num2[j]
	 *			This situation means that some values in left_subset are greater
	 *			than those in right_subset. The value of i needs to be decreased
	 *			and the value of j increased, which shifts higher values from num1
	 *			over to right_subset, and shifts lower values from num2 over to
	 *			left_subset.
	 *			Adjust the binary search range to [i_min, i - 1], and go back to
	 *			step 2.
	 *
	 * After i has been found, the median can be calculated as such:
	 *					  		 Max(num1[i - 1], B[j - 1]), when m + n is odd.
	 *	(Max(num1[i - 1], B[j - 1]) + Max(num1[i], B[j]))/2, when m + n is even.
	 */
	static double findMedianSortedArrays(std::vector<int> &nums1,
		std::vector<int> &nums2)
	{
		std::vector<int> shorterList = nums1;
		std::vector<int> longerList = nums2;

		/* Length of list 1 (of length m) must be less than or equal to the length
		 * of list 2 (of length n), to enforce the condition that m <= n. */
		if (nums1.size() > nums2.size())
		{
			shorterList = nums2;
			longerList = nums1;
		}

		/* Start hunting for a value i (which is used to calculate j) in the range
		 * of [0, m] in list 1. */
		int iMin = 0;
		int iMax = shorterList.size();

		/* Half of the size of the combined lists. Preliminary calculation used
		 * for calculated j. */
		int halfLength = (shorterList.size() + longerList.size()) / 2;

		while (iMin <= iMax)
		{
			/* Binary search - i should examine the halfway point between the set
			 * min and max range of the shorter list. */
			int i = (iMin + iMax) / 2;
			int j = halfLength - i;

			/* Case 1: i is too small, since there is an element in list B's left
			 * subset that is greater than an element in list A's right subset.
			 * Move i up to move elements from the left subset of list B to the
			 * right subset, and elements from the right subset of list A to the
			 * left subset. */
			if (i < iMax && longerList[j - 1] > shorterList[i])
			{
				iMin = i + 1;	/* Readjust iMin to recurse to the upper half. */
			}

			/* Case 2: i is too large, since there is an element in list A's left
			 * subset that is greater than an element in list B's right subset.
			 * Move i down to move elements from the left subset of list A to the
			 * right subset, and elements from the right subset of list B to the
			 * left subset. */
			else if (i > iMin && shorterList[i - 1] > longerList[j])
			{
				iMax = i - 1;	/* Readjsut iMax to recurse to the lower half. */
			}

			/* Case 3: i is the right value. */
			else
			{
				/* Determine the maximum value of the left subset of list A and
				 * list B's left subsets. */
				int maxLeft = 0;

				/* Edge case: i == 0 means that no elements are on list A's left
				 * subset, so maximum value of left combined subset must be the
				 * maximum of list B's left subset. */
				if (i == 0)
				{
					maxLeft = longerList[j - 1];
				}

				/* Edge case: j == 0 means that no elements are on list B's left
				 * subset, so maximum value of left combined subset must be the
				 * maximum of list A's left subset. */
				else if (j == 0)
				{
					maxLeft = shorterList[i - 1];
				}

				/* Else, take the maximum between the two of the left subsets. */
				else
				{
					maxLeft = std::max(shorterList[i - 1], longerList[j - 1]);
				}

				/* If there is an odd number of elements when the two lists are
				 * combined, then the median is just the maximum of the left
				 * subset. */
				if ((shorterList.size() + longerList.size()) % 2 == 1)
				{
					return maxLeft;
				}

				/* If this part of the code is hit, then an even number of elements
				 * is present. Calculate the minimum of the right subsets with
				 * similar edge cases as the maximum of the left subsets, and return
				 * the average of the maximum of the left and the minimum of the
				 * right as the median. */
				int minRight = 0;

				/* No elements in right subset of list A. */
				if (i == shorterList.size())
				{
					minRight = longerList[j];
				}

				/* No elements in the right subset of list B. */
				else if (j == longerList.size())
				{
					minRight = shorterList[i];
				}

				/* Else, take the minimum between the two of the right subsets. */
				else
				{
					minRight = std::min(shorterList[i], longerList[j]);
				}

				return (maxLeft + minRight) / 2.0;
			}
		}

		/* This line should not be hit. */
		return 0.0;
	}
};

#endif	// _MEDIAN_SORTED_ARRAYS_H_