#pragma once
#ifndef _SUM_ROOT_TO_LEAF_NUMBERS_H_
#define _SUM_ROOT_TO_LEAF_NUMBERS_H_

#include "LeetCodeTreeNode.h"

/**
 * Problem: Given a binary tree containing digits from 0-9 only, each root-to-leaf
 * path could represent a number. An example is the root-to-leaf path, which
 * represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 */
class SumRootToLeafNumbers
{
public:

	/* This problem can be solved with a modified version of DFS. When we reach
	 * a new digit, we shift the current sum over by 1 digit, and add the digit
	 * to the current value. If we encounter a leaf node (i.e. a node that
	 * represents the last digit of a valid number), then we can add that value
	 * to the sum. When we backtrack from a leaf node, we will reverse any digit
	 * shifting and adding (e.g. 123 becomes 12, since 3 was the leaf node). */
	int sumNumbers(TreeNode * root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int currentSum = 0;
		int totalSum = 0;
		sumNumbersHelper(root, &totalSum, &currentSum);

		return totalSum;
	}

	void sumNumbersHelper(TreeNode * node, int * totalSum, int * currentSum)
	{
		/* Add digit to current sum when travelling down the tree. */
		*currentSum *= 10;
		*currentSum += node->val;

		if (node->left)
		{
			sumNumbersHelper(node->left, totalSum, currentSum);
		}

		if (node->right)
		{
			sumNumbersHelper(node->right, totalSum, currentSum);
		}

		/* Only add the current sum to the total sum when a leaf node has been
		 * reached. */
		if (node->left == nullptr && node->right == nullptr)
		{
			*totalSum += *currentSum;
		}

		/* Remove digit from current sum when backtracking up the tree. */
		*currentSum -= node->val;
		*currentSum /= 10;
	}
};

#endif	// _SUM_ROOT_TO_LEAF_NUMBERS_H_