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
		
		/* This loop takes care of two possible conditions:
		 *	1. The stack could be empty, but currentNode might be pointing to
		 *		something. This is possible if the currentNode is pointing to
		 *		the root, or if all elements in the stack have been popped, and
		 *		currentNode is pointing to the right child.
		 *	2. currentNode may be null, but the stack still has elements inside
		 *		it. This is possible if all left children to the leftmost node
		 *		in the subtree have been added, and the leftmost node has no
		 *		right child. */
		while (currentNode != nullptr || !toVisitStack.empty())
		{
			/* This loop will continue to add all left children in the subtree
			 * until the leftmost node has been added. However, in the case where
			 * all left nodes have been added and the leftmost node has no right
			 * child, currentNode will be null and this loop will not run. */
			while (currentNode != nullptr)
			{
				toVisitStack.push(currentNode);
				currentNode = currentNode->left;
			}

			/* Pop the most recently visited value on the stack and add it to the
			 * iteration list. Then, see if the most recently added node has a 
			 * right subtree, and explore it if it does. 
			 *
			 * If it does, then currentNode will point to it, and we'll repeat
			 * the process of adding all of the left children in that subtree
			 * that has the right child as the root.
			 *
			 * If it doesn't, then we'll start to backtrack up the tree, popping
			 * nodes from the top of the stack until one of the nodes has a right
			 * child. */
			currentNode = toVisitStack.top();
			toVisitStack.pop();

			inorderList.push_back(currentNode->val);
			currentNode = currentNode->right;
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