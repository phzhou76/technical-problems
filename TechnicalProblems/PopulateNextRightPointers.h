#pragma once
#ifndef _POPULATE_NEXT_RIGHT_POINTERS_H_
#define _POPULATE_NEXT_RIGHT_POINTERS_H_

/**
 * Given a binary tree where each node in the tree has a left, right, and next
 * pointer, populate each next pointer to point to its next right node. If there
 * is no next right node, the next pointer should be set to null. Initially, all
 * next pointers are set to null.
 *
 * Notes:
 *	1. You may only use constant extra space.
 *	2. Recursive approach is fine - implicit stack space does not count as extra
 *		space for this problem.
 *	3. You may assume that it is a perfect binary tree (i.e. all leaves are at
 *		the same level, and every parent has two children.
 *
 * Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 */
struct TreeLinkNode
{
	int val;
	TreeLinkNode * left;
	TreeLinkNode * right;
	TreeLinkNode * next;

	TreeLinkNode(int x): val(x), left(nullptr), right(nullptr), next(nullptr) { }
};

class PopulateNextRightPointers
{
public:

	/* This problem can be solved with O(1) space complexity. The assumption that
	 * the input is a perfect binary tree means that we know the following:
	 *	1. Each node apart from the leaf nodes will have two children that we
	 *		need to connect with next.
	 *	2. The first, or leftmost, node in each level can be obtained by taking
	 *		the leftmost node in the previous level and obtaining its left child. 
	 *
	 * With that in mind, we'll take the leftmost node in each level, starting
	 * from the root, and ending at the level before the leaf nodes. Use the
	 * leftmost node in each level as the starting point, and for each node in
	 * the level (accessed with the next field), do the following:
	 *	1. Connect the current node's left child to its right child.
	 *	2. If the current node isn't the last node on its level (this can be 
	 *		checked with node->right != null), then connect this node's right
	 *		child to the next node's left child.
	 *	3. Iterate on to the node to the right. 
	 *
	 * The next field will be guaranteed to be set for currNode, since the previous
	 * level's iteration must have set it, starting from the root setting the next
	 * level's next fields.
	 */
	void connect(TreeLinkNode * root)
	{
		if (root == nullptr)
		{
			return;
		}

		/* Iterate per level of the perfect tree, stopping at the level before
		 * the leaf nodes. */
		for (TreeLinkNode * leftmostNode = root; leftmostNode->left != nullptr;
			leftmostNode = leftmostNode->left)
		{
			/* Iterate through all nodes in each level of the perfect tree. */
			for (TreeLinkNode * currNode = leftmostNode; currNode != nullptr;
				currNode = currNode->next)
			{
				/* Connect the left and right children of this node. */
				currNode->left->next = currNode->right;

				/* Connect the right child of this node to the left child of the
				 * next node, if it is available. */
				if (currNode->next != nullptr)
				{
					currNode->right->next = currNode->next->left;
				}
			}
		}
	}
};

#endif	// _POPULATE_NEXT_RIGHT_POINTERS_H_