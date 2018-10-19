#pragma once
#ifndef _POSTORDER_TRAVERSAL_H_
#define _POSTORDER_TRAVERSAL_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Problem: Given a binary tree, return the postorder traversal of its nodes'
 * values.
 */
class PostorderTraversal
{
public:

	/* Postorder traversal can be implemented by just reversing the order that
	 * nodes are visited in preorder traversal. This can be done with a two-stack
	 * process.
	 *
	 * The idea is that if the root node of a subtree is the first node visited
	 * by a preorder traversal, then if it is placed in a stack, it will be the
	 * last node visited in a subtree, which is what postorder traversal is.
	 *
	 * Algorithm:
	 *	1. Start with two stacks: One stack for visiting nodes like a preorder
	 *		traversal algorithm would, and the other for reversing the nodes for
	 *		postorder traversal.
	 *	2. Push the root node to the preorder traversal stack, if it exists.
	 *	3. While there are still nodes to visit in the tree (i.e. while stack is
	 *		not empty):
	 *		3a. Pop the topmost element off the stack.
	 *		3b. "Cache" the node to visit later in a postorder traversal in the
	 *			postorder stack.
	 *		3c. Add the children of that node to the preorder traversal stack.
	 *			Note that we add the left child first before the right child,
	 *			unlike the typical implementation for preorder traversal. Since
	 *			postorder traversal will reverse whatever preorder traversal
	 *			visits, we want to visit the right child first, then the left
	 *			child in preorder traversal.
	 */
	std::vector<int> postorderTraversal(TreeNode * root)
	{
		/* Edge Case: Cannot perform postorder traversal on empty tree. */
		if (root == nullptr)
		{
			return std::vector<int>();
		}

		/* Contains nodes that have yet to be visited, i.e. preorder traversal. */
		std::stack<TreeNode *> toVisit;

		/* Contains nodes to visit in preorder traversal. */
		std::stack<TreeNode *> postorderVisit;

		toVisit.push(root);

		while (!toVisit.empty())
		{
			/* Pop the top of the toVisit stack, and "cache" the node to visit
			 * later in another stack. By using a stack, we ensure that the first
			 * node we encounter in a subtree will be the last node we actually
			 * visit. */
			TreeNode * visitLater = toVisit.top();
			toVisit.pop();
			postorderVisit.push(visitLater);

			/* Then, push the children of the node, just like in preorder fashion.
			 * However, instead of pushing the left child after the right child,
			 * we'll push the right child after the left child. This ensures that
			 * the right child will be the first to be visited in preorder
			 * traversal, which means that it will be the second to be visited in
			 * postorder traversal. */
			if (visitLater->left != nullptr)
			{
				toVisit.push(visitLater->left);
			}

			if (visitLater->right != nullptr)
			{
				toVisit.push(visitLater->right);
			}
		}

		/* After the preorder traversal has finished, the postorder traversal
		 * stack will contain the reversed sequence of the preorder traversal,
		 * where the root of a subtree will be below its left and right subtrees
		 * in the stack. Push these values into a list. */
		std::vector<int> postorderList;

		while (!postorderVisit.empty())
		{
			postorderList.push_back(postorderVisit.top()->val);
			postorderVisit.pop();
		}

		return postorderList;
	}
};

#endif	// _POSTORDER_TRAVERSAL_H_