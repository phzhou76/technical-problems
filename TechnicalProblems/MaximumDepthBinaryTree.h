#pragma once
#ifndef _MAXIMUM_DEPTH_BINARY_TREE_H_
#define _MAXIMUM_DEPTH_BINARY_TREE_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Problem: Given a binary tree, find its maximum depth. The maximum depth is
 * defined as the number of nodes along the longest path from the root node down
 * to the farthest leaf node. 
 */
class MaximumDepthBinaryTree
{
public:
	int maxDepth(TreeNode * root)
	{
		return maxDepthHelper(root);
	}

	/* This problem can be solved recursively. The base case is in which the node
	 * being examined is null, at which 0 can be returned. Then, for each node
	 * that actually exists, take the maximum length of the left subtree and 
	 * the right subtree. */
	int maxDepthHelper(TreeNode * node)
	{
		/* Base case: Return a path length of 0. */
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