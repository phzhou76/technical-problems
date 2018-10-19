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
		/* Edge Case: Can't delete duplicates if there is no linked list. */
		if (head == nullptr)
		{
			return nullptr;
		}

		/* Points to the last unique value encountered. */
		ListNode * uniqueEndPtr = head;
		
		/* Used to scan ahead and look for unique values. */
		ListNode * currPtr = uniqueEndPtr->next;

		/* Scan towards the end. */
		while (currPtr != nullptr)
		{
			/* If the current node is equal to the last unique value encountered,
			 * then delete this node and move onto the next node. */
			if (currPtr->val == uniqueEndPtr->val)
			{
				ListNode * deleteNode = currPtr;
				currPtr = currPtr->next;
				delete deleteNode;
			}

			/* If the current node is not equal to the last unique value encountered,
			 * then this is a unique value. Advance the unique pointer to this value
			 * and advance both pointers. */
			else
			{
				uniqueEndPtr->next = currPtr;
				uniqueEndPtr = uniqueEndPtr->next;
				currPtr = currPtr->next;
			}
		}
		
		/* Because we only keep the first value, and delete all other duplicate
		 * nodes afterward, there is a possible memory access issue at the end.
		 * If multiple duplicate values exist at the end, the first instance of
		 * those nodes will be kept, while the rest will be deleted. At the end,
		 * the first instance will be pointing to a deleted memory address, so
		 * we need to set it to null. */
		uniqueEndPtr->next = nullptr;

		return head;
	}
};

#endif	// _REMOVE_DUPLICATES_FROM_SORTED_LIST_H_