#pragma once
#ifndef _POPULATE_NEXT_RIGHT_POINTERS_II_H_
#define _POPULATE_NEXT_RIGHT_POINTERS_II_H_

/**
 * Problem: Given a binary tree in which each node has a left, right, and next
 * pointer, populate each next pointer to point to its next right node. If there
 * is no next right node, the next pointer should be set to null.
 *
 * Initially, all next pointers are set to null.
 *
 * Notes:
 *	1. You may only use constant extra space.
 *	2. Recursive approaches are fine - the implicit stack space does not count as
 *		extra space for this problem.
 */
struct TreeLinkNode
{
	int val;
	TreeLinkNode * left;
	TreeLinkNode * right;
	TreeLinkNode * next;

	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) { }
};

class PopulateNextRightPointersII
{
public:

	/* The approach that was used in PopulateNextRightPointers can be used here,
	 * but additional edge cases must be checked for. */
	void connect(TreeLinkNode * root)
	{
		/* Can't link the nodes in a tree that doesn't exist. */
		if (root == nullptr)
		{
			return;
		}

		/* Start scanning each layer, starting from the root and stopping at the
		 * layer above the last layer. However, unlike the previous problem, the
		 * trees in this problem may not be perfect trees.
		 *
		 * Thus, we may need the following:
		 *	1. A pointer that holds the start of the next level.
		 *	2. A pointer that holds the previously seen child node so that it can
		 *		be used to link the current node's leftmost child (right child if
		 *		there is no left child). */
		TreeLinkNode * nextLeftmostNode = root;
		TreeLinkNode * prevVisitedChild = nullptr;	/* Needs to be set to null at end of level. */
		for (TreeLinkNode * leftmostNode = nextLeftmostNode;
			leftmostNode != nullptr; leftmostNode = nextLeftmostNode)
		{
			/* Reset nextLeftmostNode to null to have it be set on the first child
			 * node encountered. */
			nextLeftmostNode = nullptr;

			for (TreeLinkNode * currNode = leftmostNode;
				currNode != nullptr; currNode = currNode->next)
			{
				/* For the current node's child nodes, there are four possible cases:
				 *	1. Left and right children exist.
				 *	2. Only left child exists.
				 *	3. Only right child exists.
				 *	4. Neither child exists. */

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

				/* Right child exists (if left child also exists, both of these
				 * cases will run. */
				if (currNode->right != nullptr)
				{
					/* If the current node had both left and right children, then
					 * prevVisitedChild would be set to the left child before the
					 * right child was encountered, which lets us create a connection
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