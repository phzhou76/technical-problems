#pragma once
#ifndef _CONSTRUCT_BINARY_TREE_H_
#define _CONSTRUCT_BINARY_TREE_H_

#include "pch.h"
#include "LeetCodeTreeNode.h"

/**
 * Problem: Given the inorder and postorder traversal of a tree, construct the
 * binary tree.
 *
 * Notes:
 *	1. You may assume that duplicates do not exist in the tree.
 */
class ConstructBinaryTree
{
public:

	/* By definition, in postorder traversal, the last element that is visited
	 * is the root of the tree. Draw the array of inorder elements, and we can
	 * see that we need to find the root of the subtree, and "divide" the array
	 * of inorder elements at that root for the left and right subtrees.
	 *
	 * So, we can use the postorder traversal array to determine where the root
	 * of the subtree is, and then recurse until one element in the subtree 
	 * remains (i.e. the lower bound and higher bound of the subtree's inorder
	 * traversal are the same). */
	TreeNode * buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
	{
		if (inorder.empty())
		{
			return nullptr;
		}

		/* Pair each element with its postorder position. */
		std::unordered_map<int, int> elmtOrder;
		for (int i = 0; i < postorder.size(); ++i)
		{
			elmtOrder[postorder[i]] = i;
		}

		return buildTreeHelper(inorder, elmtOrder, 0, inorder.size() - 1);
	}

	/* Parameters:
	 *	1. lowIndex: Lower bound of inorder elements that subtree consists of.
	 *	2. highIndex: Higher bound of inorder elements that subtree consists of. */
	TreeNode * buildTreeHelper(std::vector<int> &inorder,
		std::unordered_map<int, int> &elmtOrder, int lowIndex, int highIndex)
	{
		/* Determine which value in the allowed range has the greatest
			 * postorder position, since that will be the root of this subtree. */
		int rootInorderIndex = getRootInorderIndex(inorder, elmtOrder, lowIndex,
			highIndex);

		TreeNode * newNode = new TreeNode(inorder[rootInorderIndex]);

		/* Recurse onto the left subtree if it exists (i.e. if the root index is
		 * greater than the lower bound of the subtree. */
		if (rootInorderIndex > lowIndex)
		{
			newNode->left = buildTreeHelper(inorder, elmtOrder, lowIndex,
				rootInorderIndex - 1);
		}

		/* Recurse onto the right subtree if it exists (i.e. if the root index is
		 * less than the higher bound of the subtree. */
		if (rootInorderIndex < highIndex)
		{
			newNode->right = buildTreeHelper(inorder, elmtOrder,
				rootInorderIndex + 1, highIndex);
		}

		return newNode;
	}

	int getRootInorderIndex(std::vector<int> &inorder,
		std::unordered_map<int, int> &elmtOrder, int lowIndex, int highIndex)
	{
		/* Highest postorder index. */
		int highestPostorderIndex = -1;

		/* Index of element that holds the highest postorder index.*/
		int inorderIndex = -1;	

		for (int i = lowIndex; i <= highIndex; ++i)
		{
			if (elmtOrder[inorder[i]] > highestPostorderIndex)
			{
				highestPostorderIndex = elmtOrder[inorder[i]];
				inorderIndex = i;
			}
		}

		return inorderIndex;
	}
};

#endif	// _CONSTRUCT_BINARY_TREE_H_
