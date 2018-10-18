#pragma once
#ifndef _REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
#define _REMOVE_DUPLICATES_FROM_SORTED_LIST_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Given a sorted linked list, delete all duplicates such that each
 * element only appears once.
 */
class RemoveDuplicatesFromSortedList
{
public:
	ListNode * deleteDuplicates(ListNode * head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		/* For this problem, we'll need two pointers. One pointer will point to
		 * the first instance of the current value. The other pointer will be
		 * used to delete each node that has the same value as the current value. */
		ListNode * currPtr = head;
		ListNode * scanPtr = nullptr;

		while (currPtr != nullptr)
		{
			int currValue = currPtr->val;
			scanPtr = currPtr->next;

			/* If there is a duplicate value, scan ahead and continue to delete
			 * nodes until the end of the list has been reached or until a node
			 * with a different value has been encountered. */
			while (scanPtr != nullptr && scanPtr->val == currValue)
			{
				ListNode * deleteNode = scanPtr;
				scanPtr = scanPtr->next;
				delete deleteNode;
			}

			/* scanPtr should now point to a node of different value, or it has
			 * reached the end of the list, and is now nullptr. */
			currPtr->next = scanPtr;
			currPtr = currPtr->next;
		}

		return head;
	}
};

#endif	// _REMOVE_DUPLICATES_FROM_SORTED_LIST_H_