#pragma once
#ifndef _PREORDER_TRAVERSAL_H_
#define _PREORDER_TRAVERSAL_H_

#include "pch.h"
#include "LeetCodeTreeNode.h"

/**
 * Problem: Given a binary tree, return the preorder traversal of its nodes' values.
 */
class PreorderTraversal
{
public:

	/* Use a stack instead of recursive calls, similar to how DFS works. */
	std::vector<int> preorderTraversal(TreeNode * root)
	{
		if (root == nullptr)
		{
			return std::vector<int>();
		}

		std::vector<int> preorderList;
		std::stack<TreeNode *> preorderStack;

		preorderStack.push(root);

		while (!preorderStack.empty())
		{
			TreeNode * node = preorderStack.top();
			preorderStack.pop();

			preorderList.push_back(node->val);

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