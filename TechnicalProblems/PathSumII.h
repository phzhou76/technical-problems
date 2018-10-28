#pragma once
#ifndef _PATH_SUM_II_H_
#define _PATH_SUM_II_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 */
class PathSumII
{
public:

	/* DFS Algorithm:
	 *
	 *	1. Start with an empty array of ints which will be used to hold the
	 *		path from the root to the current node.
	 *
	 *	2. Then, start doing preorder traversal down the tree:
	 *
	 *		2a. On each node, subtract the node's value from the current difference
	 *			needed to hit the target sum, and push the node's value to the 
	 *			current path.
	 *
	 *		2b. If the node is a leaf node, check if the difference is 0. If so,
	 *			then the root to leaf sum is equal to the target sum, so add the
	 *			path to the list of paths.
	 *
	 *		2c. If the node has any left or right children, recurse onto them with
	 *			the updated path and difference to sum.
	 *
	 *		2d. When backtracking, pop this node's value from the current path.
	 *
	 *	3. Return the list of paths.
	 */
	std::vector<std::vector<int>> pathSum(TreeNode * root, int sum)
	{
		/* Edge Case: If the binary tree is empty, return an empty list. */
		if (root == nullptr)
		{
			return std::vector<std::vector<int>>();
		}

		/* Holds all of the paths from root to leaf nodes where the total sum
		 * is equal to the given sum. */
		std::vector<std::vector<int>> validPaths;

		/* Holds the path from the root to the current node being examined. */
		std::vector<int> currentPath;

		pathSumHelper(validPaths, currentPath, root, sum);
		
		return validPaths;
	}

	void pathSumHelper(std::vector<std::vector<int>> &validPaths, 
		std::vector<int> &currentPath, TreeNode * node, int currentDifference)
	{
		/* Update the difference and the current path to reflect this node. */
		currentDifference -= node->val;
		currentPath.push_back(node->val);

		/* Base case: The leaf node has been reached. */
		if (node->left == nullptr && node->right == nullptr)
		{
			/* Check if the current difference is 0, since that means the sum of
			 * the path will have met the given sum. */
			if (currentDifference == 0)
			{
				validPaths.push_back(std::vector<int>(currentPath));
			}
		}

		/* Recurse on left or right children if they exist.*/
		if (node->left != nullptr)
		{
			pathSumHelper(validPaths, currentPath, node->left, currentDifference);
		}
		
		if (node->right != nullptr)
		{
			pathSumHelper(validPaths, currentPath, node->right, currentDifference);
		}

		/* This node needs to be popped from the current path, since this path 
		 * will not be examined anymore. */
		currentPath.pop_back();
	}
};

#endif	// _PATH_SUM_II_H_