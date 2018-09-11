#pragma once
#ifndef _LINKED_LIST_CYCLE_H_
#define _LINKED_LIST_CYCLE_H_

#include "pch.h"
#include "LinkedListNode.h"

/**
 * Problem: Given a linked list, determine if it has a cycle in it.
 *
 * Follow up: Can you solve it without using extra space?
 */
class LinkedListCycle
{
public:
	bool hasCycle(LinkedListNode<int> *head) {
		/* Have two pointers, one that moves one node per iteration, and another
		 * that moves two nodes per iteration. */
		LinkedListNode<int> * slowPointer = head;
		LinkedListNode<int> * fastPointer = head;

		/* If the fast pointer ever hits a nullptr, then it has reached the end
		 * of the linked list. This means that no cycle has been found. */
		while (fastPointer != nullptr)
		{
			fastPointer = fastPointer->mNextNode;

			/* Only iterate the fast pointer again if it is safe to do so. */
			if (fastPointer != nullptr)
			{
				fastPointer = fastPointer->mNextNode;
			}

			slowPointer = slowPointer->mNextNode;

			/* If the slow and fast pointer ever match (barring the case where
			 * they're both nullptr, since that means both reached the end of the
			 * list), then a loop exists. */
			if (slowPointer == fastPointer && slowPointer != nullptr)
			{
				return true;
			}
		}

		return false;
	}
};


#endif	// _LINKED_LIST_CYCLE_H_