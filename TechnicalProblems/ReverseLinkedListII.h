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
	ListNode * reverseBetween(ListNode * head, int m, int n)
	{
		/* Nothing to reverse if there is no list. */
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
			 * the start node now points to. Need to check for edge case where 
			 * the node to reverse was the last node in the list, which can trigger
			 * a NPE when startPtr is accessed like this. */
			if (startPtr != nullptr)
			{
				reversePtr = startPtr->next;
			}
		}

		ListNode * deleteNode = fakeHead;
		fakeHead = fakeHead->next;
		delete deleteNode;
			
		return fakeHead;
	}
};

#endif	// _REVERSE_LINKED_LIST_II_H_