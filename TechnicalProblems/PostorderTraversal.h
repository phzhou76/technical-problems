#pragma once
#ifndef _POSTORDER_TRAVERSAL_H_
#define _POSTORDER_TRAVERSAL_H_

#include "pch.h"
#include "LeetCodeTreeNode.h"

/**
 * Problem: Given a binary tree, return the postorder traversal of its nodes'
 * values. 
 */
class PostorderTraversal
{
public:

	/* Postorder traversal can be implemented by just implementing preorder
	 * traversal, but reversing the order. I.e. when a node is popped from the
	 * stack to mark that it was visited in preorder traversal, instead push that
	 * node to another stack to visit later. At the very end of the algorithm,
	 * the last node of preorder traversal would be the first node of postorder
	 * traversal, and the first node of preorder traversal would be the last
	 * node of postorder traversal. */
	std::vector<int> postorderTraversal(TreeNode * root)
	{
		if (root == nullptr)
		{
			return std::vector<int>();
		}

		/* Contains nodes that have yet to be visited. */
		std::stack<TreeNode *> toVisit;
		std::stack<TreeNode *> postorderList;

		toVisit.push(root);

		while (!toVisit.empty())
		{
			/* Pop the top of the toVisit stack, and "cache" the node to visit
			 * later in another stack. */
			TreeNode * visitLater = toVisit.top();
			toVisit.pop();

			/* By using a stack, we ensure that the first node we encounter in
			 * a subtree will be the last node we actually visit. */
			postorderList.push(visitLater);

			/* Then, push the children of the node, just like in preorder fashion. 
			 * However, instead of pushing the left child after the right child,
			 * we'll push the right child after the left child. This ensures that
			 * the right child is on top of the stack, which means it will come
			 * after the left child in the postorder traversal. */
			if (visitLater->left != nullptr)
			{
				toVisit.push(visitLater->left);
			}

			if (visitLater->right != nullptr)
			{
				toVisit.push(visitLater->right);
			}
		}

		/* After the "preorder" traversal has finished, the postorderList stack
		 * will have contained the reversed preorder traversal, where the root
		 * of this tree will be at the bottom of the stack instead of the top.
		 * Push these values into a list. */
		std::vector<int> postorderArray;
		
		while (!postorderList.empty())
		{
			postorderArray.push_back(postorderList.top()->val);
			postorderList.pop();
		}

		return postorderArray;
	}
};

#endif	// _POSTORDER_TRAVERSAL_H_