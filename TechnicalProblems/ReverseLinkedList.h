#pragma once
#ifndef _REVERSE_LINKED_LIST_H_
#define _REVERSE_LINKED_LIST_H_

#include "pch.h"
#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Reverse a singly linked list.
 */
class ReverseLinkedList
{
public:

	/* Approach (Using Pointers):
	 *	1. Create a fake head for the linked list.
	 *	2. Assign the pre-reverse pointer to the fake head.
	 *	3. Assign the start pointer to the head of the linked list.
	 *	4. Assign the reverse pointer to the start's next node.
	 *	5. While start's next node isn't null (which would mean that the start
	 *		node was at the end of the linked list):
	 *		5a. Assign the start pointer to the reverse pointer's next node to
	 *			obtain the next node that needs to be reversed.
	 *		5b. Assign the reverse pointer's next node to point to the
	 *			pre-reverse node's next node.
	 *		5c. Assign the pre-reverse node to point to the reverse pointer's
	 *			node.
	 *		5d. Assign the reverse pointer to point to the start pointer's next
	 *			node to capture the next node to reverse.
	 */
	ListNode * reverseList(ListNode * head)
	{
		/* Edge Case: Can't reverse a list if it's empty. */
		if (head == nullptr)
		{
			return nullptr;
		}

		ListNode * fakeHead = new ListNode(0);
		fakeHead->next = head;
		
		ListNode * startPtr = head;
		ListNode * reversePtr = startPtr->next;

		while (startPtr->next != nullptr)
		{
			startPtr->next = reversePtr->next;
			reversePtr->next = fakeHead->next;
			fakeHead->next = reversePtr;
			reversePtr = startPtr->next;
		}

		ListNode * deleteNode = fakeHead;
		fakeHead = fakeHead->next;
		delete deleteNode;

		return fakeHead;
	}
};

#endif	// _REVERSE_LINKED_LIST_H_
