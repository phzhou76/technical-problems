#pragma once
#ifndef _PATH_SUM_H_
#define _PATH_SUM_H_

#include "TreeNode.h"

/** 
 * Problem: Given a binary tree and a sum, determine if the tree has a
 * root-to-leaf path such that adding up all the values along the path equals
 * the given sum.
 */
class PathSum
{
public:
	bool hasPathSum(TreeNode* root, int sum) {
		return root == nullptr ? false : hasPathSumHelper(root, sum);
	}

	bool hasPathSumHelper(TreeNode * node, int difference)
	{
		/* If this is a leaf node, determine if target sum has been reached. */
		if (node->left == nullptr && node->right == nullptr)
		{
			return (difference - node->val) == 0;
		}

		/* Check the results of the left subtree, if it exists. */
		bool leftResult = node->left != nullptr ? 
			hasPathSumHelper(node->left, difference - node->val) : false;

		/* Check the results of the right subtree, if it exists. */
		bool rightResult = node->right != nullptr ? 
			hasPathSumHelper(node->right, difference - node->val) : false;
		
		return leftResult || rightResult;
	}
};

#endif	// _PATH_SUM_H_