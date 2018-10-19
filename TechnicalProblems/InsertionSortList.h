#pragma once
#ifndef _INSERTION_SORT_LIST_H_
#define _INSERTION_SORT_LIST_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Sort a linked list using insertion sort. The algorithm of insertion
 * sort is as follows:
 *	1. Insertion sort maintains two portions of the array: one portion that has
 *		been already sorted, and the other portion that's not sorted yet.
 *	2. The sort will consume one element from the unsorted portion and place it
 *		into the sorted portion per iteration.
 *	3. The sort will need to scan the entire sorted portion to determine where the
 *		element should be placed at.
 *	4. Repeat the process until the unsorted portion is empty.
 */
class InsertionSortList
{
public:
	ListNode * insertionSortList(ListNode * head)
	{
		/* Edge Case: Nothing to sort if less than 2 elements. */
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		/* Create a fake head that will contain the sorted portion of the list. */
		ListNode * sortedList = new ListNode(0);

		/* Points to an unsorted value in the linked list. */
		ListNode * currPtr = head;

		while (currPtr != nullptr)
		{
			/* Obtain the value to sort. Advance the pointer in the unsorted list,
			 * since this element will be sorted. */
			ListNode * unsortedValue = currPtr;
			ListNode * sortedPtr = sortedList;
			currPtr = currPtr->next;

			/* Continue to scan along the sorted list until the end of the list,
			 * or until the next node is greater than the current node. */
			while (sortedPtr->next != nullptr && sortedPtr->next->val < unsortedValue->val)
			{
				sortedPtr = sortedPtr->next;
			}

			/* Insert the unsorted list at the end of the list, or after the node
			 * whose next node is greater than the unsorted value. */
			unsortedValue->next = sortedPtr->next;
			sortedPtr->next = unsortedValue;
		}

		/* Clean up the fake head and return the sorted list. */
		ListNode * deleteHead = sortedList;
		sortedList = sortedList->next;
		delete deleteHead;
		return sortedList;
	}
};

#endif	// _INSERTION_SORT_LIST_H_