#pragma once
#ifndef _REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_
#define _REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_

#include "LinkedListNode.h"

/**
 * Problem: Given a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. In other words,
 * if a number has more than one copy of it in the linked list, delete all instances
 * of it.
 */
class RemoveDuplicatesFromSortedListII
{
public:
	LinkedListNode<int> * deleteDuplicates(LinkedListNode<int> * head)
	{
		/* Edge Case: If the linked list doesn't exist, return null. */
		if (head == nullptr)
		{
			return nullptr;
		}

		/* Create a "false" head for the linked list. */
		LinkedListNode<int> * newListCurrentPtr = new LinkedListNode<int>(0);
		LinkedListNode<int> * newListHeadPtr = newListCurrentPtr;

		LinkedListNode<int> * currPtr = head;
		while (currPtr != nullptr)
		{
			/* Obtain the value of the current node. This value is guaranteed to
			 * either be unique or the first value in a series of duplicates. */
			int currValue = currPtr->mData;
			int currValueCount = 1;

			/* Scan ahead to see if this current node's value is a duplicate value.
			 * If the next value is a duplicate, then we need to delete this node
			 * and move onto the next node. Repeat the process until the end of
			 * the list has been reached or until the next node's value is different. */
			while (currPtr->mNextNode != nullptr && currValue == currPtr->mNextNode->mData)
			{
				/* Each duplicate node we come across has to be deleted. */
				LinkedListNode<int> * deleteNode = currPtr;
				currPtr = currPtr->mNextNode;
				delete deleteNode;
				++currValueCount;
			}

			/* If currValueCount is greater than one, then that means that the loop
			 * above ran at least once, and ended up on the last duplicate node. 
			 * Delete this node. */
			if (currValueCount > 1)
			{
				LinkedListNode<int> * deleteNode = currPtr;
				currPtr = currPtr->mNextNode;
				delete deleteNode;
			}
			/* Else, connect the "new" list to this unique node, and advance both
			 * the new and old list pointers. */
			else
			{
				newListCurrentPtr->mNextNode = currPtr;
				currPtr = currPtr->mNextNode;
				newListCurrentPtr = newListCurrentPtr->mNextNode;
			}
		}

		/* The new list's current pointer is now at the end of the list. Make sure
		 * it doesn't it doesn't point to anything, and delete the false head that
		 * was originally created. */
		newListCurrentPtr->mNextNode = nullptr;
		LinkedListNode<int> * deleteNode = newListHeadPtr;
		newListHeadPtr = newListHeadPtr->mNextNode;
		delete deleteNode;
		return newListHeadPtr;
	}
};

#endif	// _REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H_