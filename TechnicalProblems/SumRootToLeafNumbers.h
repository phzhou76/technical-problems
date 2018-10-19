#pragma once
#ifndef _SUM_ROOT_TO_LEAF_NUMBERS_H_
#define _SUM_ROOT_TO_LEAF_NUMBERS_H_

#include "TreeNode.h"

/**
 * Problem: Given a binary tree containing digits from 0-9 only, each root-to-leaf
 * path could represent a number. An example is the root-to-leaf path, which
 * represents the number 123, where the root node contains 1 and the leaf node
 * contains 3.
 *
 * Find the total sum of all root-to-leaf numbers.
 */
class SumRootToLeafNumbers
{
public:

	/* DFS Algorithm:
	 *	1. When a new digit is approached, we will shift the current sum to the
	 *		left by one digit (i.e. multiply by 10).
	 *	2. Then, add the digit to the shifted sum.
	 *	3. If a leaf node is encountered, then we will follow steps 1-2, and then
	 *		add the updated sum to the global sum.
	 *	4. After we have visited all nodes in a subtree (e.g. finished visiting
	 *		a leaf node), then we will start to backtrack.
	 *		4a. First, we subtract the value of the node that we are backtracking
	 *			from. For example, if we were at the leaf node in the sequence 123,
	 *			then we would subtract 3 from the value.
	 *		4b. Then, we would reverse the shift of the other digits by dividing
	 *			the remaining sum by 10, which shifts them to the right.
	 */
	int sumNumbers(TreeNode * root)
	{
		/* Edge Case: Can't add sums if tree doesn't exist. */
		if (root == nullptr)
		{
			return 0;
		}

		/* Value with the current node being examined. */
		int currValue = 0;

		/* Total sum of all root to leaf paths. */
		int totalSum = 0;

		sumNumbersHelper(root, &totalSum, &currValue);

		return totalSum;
	}

	void sumNumbersHelper(TreeNode * node, int * totalSum, int * currValue)
	{
		/* Add digit to current value when travelling down the tree. */
		*currValue *= 10;
		*currValue += node->val;

		if (node->left)
		{
			sumNumbersHelper(node->left, totalSum, currValue);
		}

		if (node->right)
		{
			sumNumbersHelper(node->right, totalSum, currValue);
		}

		/* When a leaf node has been reached, add current value to total sum. */
		if (node->left == nullptr && node->right == nullptr)
		{
			*totalSum += *currValue;
		}

		/* Remove digit from current sum when backtracking up the tree. */
		*currValue -= node->val;
		*currValue /= 10;
	}
};

#endif	// _SUM_ROOT_TO_LEAF_NUMBERS_H_