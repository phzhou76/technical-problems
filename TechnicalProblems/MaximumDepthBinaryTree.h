#pragma once
#ifndef _MAXIMUM_DEPTH_BINARY_TREE_H_
#define _MAXIMUM_DEPTH_BINARY_TREE_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Given a binary tree, find its maximum depth. The maximum depth is defined as
 * the number of nodes along the longest path from the root node down
 * to the farthest leaf node.
 * 
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 */
class MaximumDepthBinaryTree
{
public:

	/* Recursive Algorithm:
	 *	1. Base Case: If the node is null, then it has a depth of 0.
	 *	2. Recursive Case: Take the maximum between the depths of the left and
	 *		right subtrees, and add 1.
	 */
	int maxDepth(TreeNode * root)
	{
		return maxDepthHelper(root);
	}
	
	int maxDepthHelper(TreeNode * node)
	{
		/* Base case: Return a depth of 0. */
		if (node == nullptr)
		{
			return 0;
		}

		/* Take the maximum length path between the two subtrees, and add one to
		 * it for this node. */
		return std::max(maxDepthHelper(node->left), maxDepthHelper(node->right)) + 1;
	}
};

#endif	// _MAXIMUM_DEPTH_BINARY_TREE_H_