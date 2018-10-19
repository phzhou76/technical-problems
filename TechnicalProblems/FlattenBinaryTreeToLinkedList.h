#pragma once
#ifndef _FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_
#define _FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_

#include "TreeNode.h"

/**
 * Problem: Given a binary tree, flatten it to a linked list in-place.
 */
class FlattenBinaryTreeToLinkedList
{
public:

	/* Recursive Algorithm:
	 *	1. Base Case: Return null.
	 *	2. Recursive Case: Obtain the left and right subtrees. 
	 *		2a. Then, traverse the left subtree to find its rightmost, bottommost
	 *			node.
	 *		2b. Have that node's right child pointer point to the right subtree.
	 *		2c. Clear the current node's left child pointer.
	 *		2d. Have the current node's right child pointer point to the right
	 *			subtree.
	 *		2e. Return the current node.
	 */
	void flatten(TreeNode * root)
	{
		root = flattenHelper(root);
	}

	TreeNode * flattenHelper(TreeNode * node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		else
		{
			TreeNode * rightTree = flattenHelper(node->right);
			TreeNode * leftTree = flattenHelper(node->left);

			/* Clear this node's left subtree pointer. */
			node->left = nullptr;

			/* If there is a left tree, find its rightmost node and attach the
			 * right subtree to this node. */
			if (leftTree != nullptr)
			{
				TreeNode * ptr = leftTree;
				while (ptr->right != nullptr)
				{
					ptr = ptr->right;
				}

				ptr->right = rightTree;

				node->right = leftTree;
			}

			return node;
		}
	}
};

#endif	// _FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_