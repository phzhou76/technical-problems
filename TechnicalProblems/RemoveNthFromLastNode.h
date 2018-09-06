#pragma once
#ifndef _REMOVE_NTH_FROM_LAST_NODE_H_
#define _REMOVE_NTH_FROM_LAST_NODE_H_

#include "LinkedListNode.h"

/**
 * Problem: Given a linked list, remove the n-th from last node and return the
 * head of the linked list. For example, if n = 2, then the 2nd from last node
 * needs to be removed.
 *
 * Note: The input n will always be valid.
 */
class RemoveNthFromLastNode
{
public:
	LinkedListNode<int>* removeNthFromEnd(LinkedListNode<int>* head, int n)
	{
		/* Use a forward pointer to determine where the nth from last
		 * node will be. */
		LinkedListNode<int> * forwardPointer = head;
		for (int i = 0; i < n - 1; ++i)
		{
			forwardPointer = forwardPointer->mNextNode;
		}

		/* If the forward pointer's next node is null, that means that
		 * the forward pointer is at the tail node. This means that the
		 * head node is supposed to be deleted. */
		if (forwardPointer->mNextNode == nullptr)
		{
			LinkedListNode<int> * newHead = head->mNextNode;
			delete head;
			return newHead;
		}

		/* If the head is not being deleted, then advance a behind pointer
		 * along with the forward pointer. By the time the forward pointer
		 * reaches the tail, the behind pointer should reach the nth from
		 * last node. */
		LinkedListNode<int> * behindPointer = head;

		/* However, because we need the behind pointer to point to the node
		 * before the nth to last node to delete it properly, we can advance
		 * the forward pointer by one. */
		forwardPointer = forwardPointer->mNextNode;

		while (forwardPointer->mNextNode != nullptr)
		{
			behindPointer = behindPointer->mNextNode;
			forwardPointer = forwardPointer->mNextNode;
		}

		/* Delete nth to last node and reconnect the linked list. */
		LinkedListNode<int> * nthToLast = behindPointer->mNextNode;
		behindPointer->mNextNode = nthToLast->mNextNode;
		delete nthToLast;

		return head;
	}
};

#endif	// _REMOVE_NTH_FROM_LAST_NODE_H_