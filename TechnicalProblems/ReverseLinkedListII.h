#pragma once
#ifndef _REVERSE_LINKED_LIST_II_H_
#define _REVERSE_LINKED_LIST_II_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Reverse a linked list from position m to n. Do it in one pass.
 *
 * Notes:
 *	1. 1 <= m <= n <= length of list.
 *	2. m, n are not zero-based, they are both 1-based indices.
 */
class ReverseLinkedListII
{
public:

	/* Algorithm (Using Pointers):
	 *	1. Create a fake head for the linked list.
	 *	2. Set the pre-reverse pointer to the fake head.
	 *	3. Advance the pre-reverse pointer until it reaches the m - 1 node.
	 *	4. Set the start pointer to point to the fake head's next node. This is
	 *		the beginning of the sublist to reverse.
	 *	5. Set the reverse pointer to point to the start pointer's next node.
	 *	6. Between m and n, there will be m - n reversals that need to be done.
	 *		For each iteration:
	 *		6a. Have the start pointer point to the reverse pointer's next node.
	 *			This allows the start pointer to hold the next node that needs
	 *			to be reversed.
	 *		6b. Have the reverse pointer's node point to the pre-reverse node's
	 *			next node.
	 *		6c. Have the pre-reverse node point to the reverse pointer's node.
	 *			Steps 6b and 6c will make the reverse pointer's node the start
	 *			of the sublist.
	 *		6d. Have the reverse pointer point to the start node's next node, so
	 *			that it can hold the next node to place at the start of the sublist.
	 *	7. Delete the fake head, and return the actual head of the linked list.
	 */
	ListNode * reverseBetween(ListNode * head, int m, int n)
	{
		/* Edge Case: Nothing to reverse if the list is empty. */
		if (head == nullptr)
		{
			return nullptr;
		}

		/* Create a fake head for the start of this list. */
		ListNode * fakeHead = new ListNode(0);
		fakeHead->next = head;

		/* Then, create a pointer that points to the node right before reversing. */
		ListNode * preReversePtr = fakeHead;

		/* Advance the pointer until it points to the node right before the start
		 * of the reversed list segment. The fake head is necessary for this problem,
		 * since the head might be a part of the reversed list segment, so
		 * reverseStartPtr will point to the fake head in that scenario. */
		for (int i = 0; i < m - 1; ++i)
		{
			preReversePtr = preReversePtr->next;
		}

		/* Pointer to the beginning of the list segment that will be reversed. */
		ListNode * startPtr = preReversePtr->next;
		/* Pointer to a node that will be reversed. */
		ListNode * reversePtr = startPtr->next;

		for (int i = m; i < n; ++i)
		{
			/* Step 1: Have the starting node of the unreversed list point to
			 * the node after the node to place at the front of the reversed list. */
			startPtr->next = reversePtr->next;

			/* Step 2: Have the node that will be placed at the start of the
			 * reversed list point to the first element in the reversed list. */
			reversePtr->next = preReversePtr->next;

			/* Step 3: Have the node right before the reversed list point to this
			 * newly moved node. */
			preReversePtr->next = reversePtr;

			/* Step 4: Obtain the next node to reverse, which is the node that
			 * the start node now points to. */
			reversePtr = startPtr->next;
		}

		ListNode * deleteNode = fakeHead;
		fakeHead = fakeHead->next;
		delete deleteNode;

		return fakeHead;
	}
};

#endif	// _REVERSE_LINKED_LIST_II_H_