#pragma once
#ifndef _PATH_SUM_II_H_
#define _PATH_SUM_II_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 */
class PathSumII
{
public:
	std::vector<std::vector<int>> pathSum(TreeNode * root, int sum)
	{
		/* Edge case: If the binary tree is empty, return an empty list. */
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

	void pathSumHelper(std::vector<std::vector<int>> &validPaths, std::vector<int> &currentPath,
		TreeNode * node, int currentDifference)
	{
		/* Update the difference and the current path to reflect this node. */
		currentDifference -= node->val;
		currentPath.push_back(node->val);

		/* Base case: The leaf node has been reached. */
		if (node->left == nullptr && node->right == nullptr)
		{
			/* Check if the current difference is 0, since that means the sum of the
			 * path will have met the given sum. */
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

		/* This node needs to be popped from the current path, since this path will not
		 * be examined anymore. */
		currentPath.pop_back();
	}
};

#endif	// _PATH_SUM_II_H_