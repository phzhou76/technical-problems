#pragma once
#ifndef _INVERT_BINARY_TREE_H_
#define _INVERT_BINARY_TREE_H_

#include "TreeNode.h"

/**
 * Problem: Invert a binary tree. This means that each left and right subtree are
 * switched around.
 */
class InvertBinaryTree
{
public:

	/* Recursive Approach: 
	 *	1. First, recursively call the method on the left and right subtrees.
	 *	2. Then, take the left and right subtrees, and assign the current node's
	 *		left child to point to the right subtree, and the right child to point
	 *		to the left subtree.
	 */
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