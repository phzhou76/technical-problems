#pragma once
#ifndef _PREORDER_TRAVERSAL_H_
#define _PREORDER_TRAVERSAL_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Problem: Given a binary tree, return the preorder traversal of its nodes' values.
 */
class PreorderTraversal
{
public:

	/* Use a stack instead of recursive calls, similar to how DFS works. 
	 * 
	 * DFS (Preorder) Algorithm:
	 *	1. Push the root to a stack, if it exists.
	 *	2. While the stack isn't empty:
	 *		2a. Pop the top off the stack.
	 *		2b. Do any necessary operations with the node extracted from the stack.
	 *		2c. Add all of its neighbors to the stack. In this case, we want to
	 *			examine the left child before the right child, so we add the right
	 *			child to the stack first before the left child. 
	 */
	std::vector<int> preorderTraversal(TreeNode * root)
	{
		/* Edge Case: Nothing to visit if tree doesn't exist. */
		if (root == nullptr)
		{
			return std::vector<int>();
		}

		std::vector<int> preorderList;
		std::stack<TreeNode *> preorderStack;

		preorderStack.push(root);

		/* Continue until all nodes have been visited in the tree. */
		while (!preorderStack.empty())
		{
			TreeNode * node = preorderStack.top();
			preorderStack.pop();

			preorderList.push_back(node->val);

			/* Push the node's children to the stack if they exist. */
			if (node->right != nullptr)
			{
				preorderStack.push(node->right);
			}
			
			if (node->left != nullptr)
			{
				preorderStack.push(node->left);
			}
		}

		return preorderList;
	}
};

#endif	// _PREORDER_TRAVERSAL_H_