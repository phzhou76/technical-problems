#pragma once
#ifndef _BINARY_TREE_INORDER_TRAVERSAL_H_
#define _BINARY_TREE_INORDER_TRAVERSAL_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Problem: Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Note: The recursive solution is trivial, can this be done iteratively?
 */
class BinaryTreeInorderTraversal
{
public:
	std::vector<int> inorderTraversal(TreeNode * root)
	{
		/* Recursive approach. */
#if 0
		std::vector<int> inorderList;
		inorderTraversalHelper(root, inorderList);
		return inorderList;
#endif

		/* Iterative approach. */
#if 1
		std::vector<int> inorderList;
		std::stack<TreeNode *> toVisitStack;

		TreeNode * currentNode = root;
		while (currentNode != nullptr)
		{
			/* Case 1: If there is a left subtree, then the nodes in that left
			 * subtree need to be added to the inorder list before this node's
			 * value can be added to the inorder list. Add this node to the "to
			 * visit" stack to examine after the left subtree has been examined
			 * and move to the left child node. */
			if (currentNode->left != nullptr)
			{
				toVisitStack.push(currentNode);
				currentNode = currentNode->left;
			}

			/* Case 2: If there is no left subtree, then this node's value can
			 * be added to the inorder list. After that, if this node has a right
			 * child, then the right subtree can be examined. */
			else
			{
				inorderList.push_back(currentNode->val);

				/* If this node has a right child, then go to that right child
				 * for processing. Otherwise, go back up the tree, and for each
				 * node examined, add its value to the inorder list, and if it
				 * has a right child, process the right child. */
				while (!toVisitStack.empty() && currentNode->right == nullptr)
				{
					currentNode = toVisitStack.top();
					toVisitStack.pop();
					inorderList.push_back(currentNode->val);
				}

				currentNode = currentNode->right;
			}
		}

		return inorderList;
#endif
	}

	void inorderTraversalHelper(TreeNode * node, std::vector<int> &inorderList)
	{
		/* Base case: If node is null, then recurse back up. */
		if (node != nullptr)
		{
			inorderTraversalHelper(node->left, inorderList);
			inorderList.push_back(node->val);
			inorderTraversalHelper(node->right, inorderList);
		}
	}
};

#endif	// _BINARY_TREE_INORDER_TRAVERSAL_H_