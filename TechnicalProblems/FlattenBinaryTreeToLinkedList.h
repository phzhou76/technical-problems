#pragma once
#ifndef _FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_
#define _FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_

#include "LeetCodeTreeNode.h"

/**
 * Problem: Given a binary tree, flatten it to a linked list in-place.
 */
class FlattenBinaryTreeToLinkedList
{
public:

	/* This problem can be solved with a postorder traversal. Obtain the left
	 * and right subtrees, and then attach the right subtree to the END of the
	 * left subtree, and make the left subtree as the right subtree of the
	 * current node. */
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