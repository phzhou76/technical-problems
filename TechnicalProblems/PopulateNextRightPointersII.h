#pragma once
#ifndef _POPULATE_NEXT_RIGHT_POINTERS_II_H_
#define _POPULATE_NEXT_RIGHT_POINTERS_II_H_

#include "TreeLinkNode.h"

/**
 * Given a binary tree in which each node has a left, right, and next pointer, 
 * populate each next pointer to point to its next right node. If there is no 
 * next right node, the next pointer should be set to null.
 *
 * Initially, all next pointers are set to null.
 *
 * Notes:
 *	1. You may only use constant extra space.
 *	2. Recursive approaches are fine - the implicit stack space does not count as
 *		extra space for this problem.
 *
 * Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 */
class PopulateNextRightPointersII
{
public:

	/* Algorithm:
	 *	1. Create two tree node pointers:
	 *		1a. One pointer holds the start of the next level (the leftmost node
	 *			in that level).
	 *		1b. Other pointer will hold the previously visited child. We need to
	 *			know which child was visited last on that level to create a link.
	 *			Note that this pointer must be set to null at the end of each
	 *			level.
	 *	2. Have the pointer that holds the start of the next level begin at the
	 *		root node.
	 *	3. While there is still a leftmost pointer (i.e. while there is still a
	 *		next level in the tree to visit):
	 *		3a. First, set the leftmost pointer to null so that the first child
	 *			node we find can set it. If there is no child node (i.e. we are
	 *			on the last level of this tree), then this pointer will stay null
	 *			and the loop will end.
	 *		3b. Then, start a current node pointer at the leftmost node in the
	 *			level, and continue until it points to null:
	 *			3ba. If the left child of the current node exists, connect the
	 *				previously seen node to it (if it exists), and set the left
	 *				child as the previously seen node. Also, check to see if the
	 *				child is the leftmost node of the next level.
	 *			3bb. If the right child of the current node exists, connect the
	 *				previously seen node to it (if it exists), and set the right
	 *				child as the previously seen node. Also, check to see if the
	 *				child is the leftmost node of the next level.
	 *			3bc. Increment the current node pointer by using the next field.
	 *		3c. Set the previously visited child node to null to reset it.
	 */
	void connect(TreeLinkNode * root)
	{
		/* Edge Case: Can't link the nodes in a tree that doesn't exist. */
		if (root == nullptr)
		{
			return;
		}

		TreeLinkNode * nextLeftmostNode = root;
		TreeLinkNode * prevVisitedChild = nullptr;

		for (TreeLinkNode * leftmostNode = nextLeftmostNode;
			leftmostNode != nullptr; leftmostNode = nextLeftmostNode)
		{
			/* Leftmost pointer should be only set on the first child node. */
			nextLeftmostNode = nullptr;

			for (TreeLinkNode * currNode = leftmostNode;
				currNode != nullptr; currNode = currNode->next)
			{
				/* Left child exists. */
				if (currNode->left != nullptr)
				{
					/* Connect the previously seen child, if it exists, to the
					 * left child. */
					if (prevVisitedChild != nullptr)
					{
						prevVisitedChild->next = currNode->left;
					}

					prevVisitedChild = currNode->left;

					if (nextLeftmostNode == nullptr)
					{
						nextLeftmostNode = currNode->left;
					}
				}

				/* Right child exists. */
				if (currNode->right != nullptr)
				{
					/* If the current node had both left and right children, then
					 * prevVisitedChild would be set to the left child before the
					 * right child was encountered. This lets us create a connection
					 * between the left and right children. */
					if (prevVisitedChild != nullptr)
					{
						prevVisitedChild->next = currNode->right;
					}

					prevVisitedChild = currNode->right;

					if (nextLeftmostNode == nullptr)
					{
						nextLeftmostNode = currNode->right;
					}
				}

				/* If there's no children, then we do nothing with this node.
				 * Proceed to the next node in the level, if it exists. */
			}

			prevVisitedChild = nullptr;
		}
	}
};

#endif	// _POPULATE_NEXT_RIGHT_POINTERS_II_H_