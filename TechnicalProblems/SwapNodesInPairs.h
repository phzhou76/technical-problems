#pragma once
#ifndef _SWAP_NODES_IN_PAIRS_H_
#define _SWAP_NODES_IN_PAIRS_H_

#include "LinkedListNode.h"

/**
 * Problem: Given a linked list, swap every two adjacent nodes and return its head.
 *
 * Example: Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Note:
 *	1. Your algorithm should use only constant extra space.
 *	2. You may not modify the values in the list's nodes, only nodes itself may
 *		be changed.
 */
class SwapNodesInPairs
{
public:
	LinkedListNode<int> * swapPairs(LinkedListNode<int> * head) 
	{
		/* Edge Case: Can't swap if there's one or less nodes. */
		if (head == nullptr || head->mNextNode == nullptr)
		{
			return head;
		}

		/* Pointer to new head of list. */
		LinkedListNode<int> * newHead = nullptr;

		/* Pointer to second node of previous pair. */
		LinkedListNode<int> * previousNode = nullptr;

		/* Pointer to first node of current pair to swap. */
		LinkedListNode<int> * firstNode = head;

		/* Pointer to second node of current pair to swap. */
		LinkedListNode<int> * secondNode = head->mNextNode;

		/* Swap first pair and reassign head of the list. */
		firstNode->mNextNode = secondNode->mNextNode;
		secondNode->mNextNode = firstNode;
		newHead = secondNode;
		previousNode = firstNode;

		/* Move pointers to the next swappable pair. */
		firstNode = firstNode->mNextNode;
		secondNode = firstNode != nullptr ? firstNode->mNextNode : nullptr;

		/* Only continue to look at pairs to swap if both the first and
		 * second elements in the pair exist. Otherwise, the nodes cannot
		 * be swapped. In this case, only the second node needs to be checked,
		 * since it must not be null for the pair to be valid for swapping. */
		while (secondNode != nullptr)
		{
			/* Connect the previous pair with this swapped pair. */
			previousNode->mNextNode = secondNode;

			/* Swap pair. */
			firstNode->mNextNode = secondNode->mNextNode;
			secondNode->mNextNode = firstNode;
			previousNode = firstNode;

			/* Move pointers to the next swappable pair. */
			firstNode = firstNode->mNextNode;
			secondNode = firstNode != nullptr ? firstNode->mNextNode : nullptr;
		}

		return newHead;
	}
};

#endif	// _SWAP_NODES_IN_PAIRS_H_