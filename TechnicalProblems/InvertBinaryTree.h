#pragma once
#ifndef _INVERT_BINARY_TREE_H_
#define _INVERT_BINARY_TREE_H_

#include "LeetCodeTreeNode.h"

/**
 * Problem: Invert a binary tree.
 */
class InvertBinaryTree
{
public:
	TreeNode * invertTree(TreeNode * root)
	{
		invertTreeHelper(root);
		return root;
	}

	void invertTreeHelper(TreeNode * node)
	{
		/* Reverse both the left and right subtrees first, then switch the
		 * subtrees around. This is post-order traversal, since the left and
		 * right nodes are visited before modifying them from the parent node. */
		if (node != nullptr)
		{
			invertTreeHelper(node->left);
			invertTreeHelper(node->right);

			TreeNode * leftSubtree = node->left;
			node->left = node->right;
			node->right = leftSubtree;
		}
	}
};

#endif	// _INVERT_BINARY_TREE_H_