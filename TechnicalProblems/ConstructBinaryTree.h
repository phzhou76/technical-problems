#pragma once
#ifndef _CONSTRUCT_BINARY_TREE_H_
#define _CONSTRUCT_BINARY_TREE_H_

#include "pch.h"
#include "TreeNode.h"

/**
 * Given the inorder and postorder traversal of a tree, construct the binary
 * tree.
 *
 * Note:
 *	1. You may assume that duplicates do not exist in the tree.
 *
 * Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 */
class ConstructBinaryTree
{
public:

	/* Recursive Solution: In postorder traversal, the last element that is
	 * visited is the root of the tree. Draw the array of both the inorder and
	 * postorder traversal. Using the postorder array, we can find the root of
	 * that subtree, and divide the array of inorder elements at that root for
	 * the left and right subtrees.
	 *
	 * Recursive Algorithm:
	 *	1. First, create a hash map that maps each number to its postorder
	 *		position for faster lookups.
	 *
	 *	2. Then, pass the inorder traversal array, the hash map, the lower bound
	 *		of the entire inorder array, and the higher bound of the entire
	 *		inorder array to the recursive method.
	 *
	 *	3. Within the recursive method:
	 *
	 *		3a. Within the subtree's range of the inorder array, find the number
	 *			with the highest postorder index position, since that will be
	 *			the root of the subtree.
	 *
	 *		3b. Create a node for the root of this subtree using the number with
	 *			the highest postorder index position.
	 *
	 *		3c. If the inorder index of the root node is greater than the lower
	 *			bound of the inorder subarray, then recurse onto the left
	 *			subtree. Have the subtree root's left child point to the result.
	 * 
	 *		3d. If the inorder index of the root node is less than the higher
	 *			bound of the inorder subarray, then recurse onto the right 
	 *			subtree. Have the subtree root's right child point to the 
	 *			result.
	 */
	TreeNode * buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
	{
		/* Edge Case: Can't build a tree if no elements exist. */
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
	 *	2. highIndex: Higher bound of inorder elements that subtree consists of.
	 */
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

		/* Recurse onto the right subtree if it exists (i.e. if the root index
		 * is less than the higher bound of the subtree. */
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
