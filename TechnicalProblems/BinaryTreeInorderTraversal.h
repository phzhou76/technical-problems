#pragma once
#ifndef _BINARY_TREE_INORDER_TRAVERSAL_H_
#define _BINARY_TREE_INORDER_TRAVERSAL_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Follow-up: The recursive solution is trivial, can this be done iteratively?
 *
 * Source: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 */
class BinaryTreeInorderTraversal
{
public:

	/* Iterative Solution: To implement an inorder traversal solution iteratively,
	 * we need the following:
	 *	1. Array of integers to push inorder traversal integers to.
	 *	2. Stack of tree nodes that hold the nodes that still need to be visited,
	 *		with the node that has been most recently added at the top.
	 *	3. Pointer to the current node being visited.
	 *
	 * Then, set the pointer to the root node. There are two cases why the while
	 * loop should be running:
	 *	1. The stack is not empty: This means that there are still nodes to visit,
	 *		along with their right subtrees.
	 *	2. The current node pointer is not null, but the stack is empty: This
	 *		means that the entire left subtree of the root, as well as the root
	 *		itself, has been visited. Start visiting the right subtree of the
	 *		root.
	 *
	 * Within the loop:
	 *	1. Keep adding left children to the stack until there are no more left
	 *		children to add. At this point, the current node pointer will be null.
	 *	2. Once all of the left children have been added to the stack, pop the
	 *		node off the top of the stack - this is the leftmost node in the
	 *		subtree. Add it to the inorder traversal list, and have the current
	 *		pointer point to that node's right child.
	 *	3. Now, on the next iteration of the loop, if that node had a right child,
	 *		the inner loop will traverse through the right subtree. If it didn't,
	 *		then it will pop off the top of the stack and see if that node has a
	 *		right subtree.
	 */
	std::vector<int> inorderTraversal(TreeNode * root)
	{
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
	}

	/* Recursive Solution: The definition of inorder traversal is to visit the
	 * left node before the current node, and the current node before the right
	 * node.
	 *
	 * Then, we can just implement this recursively by recursing on the left
	 * child before adding the current number to the traversal list, and
	 * recursing onto the right child afterwards.
	 *
	 * Stop if the current node is null, since that means that the current node
	 * does not exist.
	 *
	 * Time Complexity: O(n), where n is the number of nodes in the tree.
	 * Space Complexity: O(h), where h is the maximum depth of the tree.
	 */
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