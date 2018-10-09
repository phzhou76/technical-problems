#pragma once
#ifndef _REVERSE_NODES_IN_K_GROUP_H_
#define _REVERSE_NODES_IN_K_GROUP_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Given a linked list, reverse the nodes of a linked list k at a time,
 * and return its modified list.
 *
 * Notes:
 *	1. k is a positive integer and is less than or equal to the length of the
 *		linked list. If the number of nodes is not a multiple of k, then left-over
 *		nodes at the very end should remain in their original order.
 *	2. Only constant extra memory is allowed.
 *	3. You may not alter the values in the list's nodes, only the nodes themselves
 *		can be changed.
 */
class ReverseNodesInKGroup
{
public:

	/* This problem can be solved with the algorithm that is used to reverse one
	 * single segment of a linked list (see ReverseLinkedListII). The only
	 * difference is that the preReverseNode would update on every "iteration".
	 * At the end of every iteration, the old start node of that reversed segment
	 * becomes the new preReverseNode. We can calculate how many times we are 
	 * able to create reversed lists by first calculating the length of the 
	 * list, and using length / k to determine the number of reversals that we 
	 * can do. */
	ListNode * reverseKGroup(ListNode * head, int k)
	{
		/* Can't reverse anything if there is no list, or if the reverse list
		 * length is just 1. */
		if (head == nullptr || k == 1)
		{
			return head;
		}

		/* Create a fake head for the list. */
		ListNode * fakeHead = new ListNode(0);
		fakeHead->next = head;

		/* Points to the node before the segment of the list to be reversed. Will
		 * start at the fake head, since the actual head needs to be reversed. */
		ListNode * preReversePtr = fakeHead;

		/* Points to the start of the unreversed list segment. */
		ListNode * startPtr = head;

		/* Points to the current node that needs to be reversed (i.e. placed at
		 * the front of the list segment). */
		ListNode * reversePtr = startPtr->next;

		/* Calculate length of list and the number of reversals we need to do. */
		int listLength = calculateListLength(head);
		int numReversals = listLength / k;

		for (int i = 0; i < numReversals; ++i)
		{
			/* Reverse the segment from the start node to k - 1 nodes away. */
			for (int j = 0; j < k - 1; ++j)
			{
				/* Obtain the next node in the segment that needs to be reversed. */
				startPtr->next = reversePtr->next;

				/* Have the reversed node point to the beginning of the reversed
				 * segment. */
				reversePtr->next = preReversePtr->next;

				/* Have the node before reversed node point to the reversed node,
				 * which places the reversed node at the beginning of the reversed
				 * segment. */
				preReversePtr->next = reversePtr;

				/* Obtain the next node to be reversed.  */
				reversePtr = startPtr->next;
			}

			/* Now that the current segment has been fully reversed, startPtr will
			 * point to the last node in the reversed segment. This will be the
			 * new pre-reverse node for the next segment to reverse. */
			preReversePtr = startPtr;

			/* In the scenario where there are no more segments to reverse, (i.e.
			 * this is the last iteration, NPEs can occur if there are no nodes
			 * after the last node of the most recently reversed segment. */
			startPtr = startPtr->next;
			if (startPtr != nullptr)
			{
				reversePtr = startPtr->next;
			}
		}

		/* Clean up the fake head. */
		ListNode * deleteNode = fakeHead;
		fakeHead = fakeHead->next;
		delete deleteNode;
		
		return fakeHead;
	}

	int calculateListLength(ListNode * head)
	{
		int listLength = 0;
		while (head != nullptr)
		{
			++listLength;
			head = head->next;
		}

		return listLength;
	}
};

#endif	// _REVERSE_NODES_IN_K_GROUP_H_