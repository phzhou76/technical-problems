#pragma once
#ifndef _REVERSE_LINKED_LIST_H_
#define _REVERSE_LINKED_LIST_H_

#include "LinkedListNode.h"

/**
 * Problem: Reverse a singly linked list.
 */
class ReverseLinkedList
{
public:
	LinkedListNode<int>* reverseList(LinkedListNode<int>* head)
	{
		/* Iterative solution. */
#if 0
		/* If the head doesn't exist, or if there's only one element in the Linked
		 * List, then no reversing needs to be done. */
		if (head == nullptr || head->mNextNode == nullptr)
		{
			return head;
		}

		/* Push all of the nodes in the Linked List onto a stack so that previous
		 * nodes can be accessed. */
		std::stack<LinkedListNode<int> *> nodeStack;
		while (head != nullptr)
		{
			nodeStack.push(head);
			head = head->mNextNode;
		}

		/* Take the last node in the Linked List and assign it as the new head. */
		LinkedListNode<int> * currentNode = nodeStack.top();
		head = currentNode;
		nodeStack.pop();

		/* Continue to redirect the current node to the next node onto the stack
		 * until the stack is empty. */
		while (!nodeStack.empty())
		{
			currentNode->mNextNode = nodeStack.top();
			currentNode = nodeStack.top();
			nodeStack.pop();
		}

		/* Need to reassign the next pointer of the old head of the list, otherwise
		 * a circular Linked List will be created. */
		currentNode->mNextNode = nullptr;

		return head;
#endif

		/* Recursive solution. */
#if 1
		/* If the head doesn't exist, or if there's only one element in the Linked
		 * List, then no reversing needs to be done. */
		if (head == nullptr || head->mNextNode == nullptr)
		{
			return head;
		}

		/* The reverseListHelper method will always return the end of its current
		 * Linked List, so at the end of the recursion, the old head of the Linked
		 * List will be returned. Redirect it's next pointer to null. */
		LinkedListNode<int> * endNode = reverseListHelper(head, &head);
		endNode->mNextNode = nullptr;
		return head;
#endif
	}

	LinkedListNode<int> * reverseListHelper(LinkedListNode<int> * node,
		LinkedListNode<int> ** head)
	{
		/* If the node's next pointer is null, then the last node in the Linked
		 * List has been found. Redirect it as the new head, and return it. */
		if (node->mNextNode == nullptr)
		{
			*head = node;
			return node;
		}

		/* Point the end of the current Linked List to this node, and return this
		 * node as the new end of the current Linked List. */
		LinkedListNode<int> * currentEndOfList = reverseListHelper(node->mNextNode, head);
		currentEndOfList->mNextNode = node;

		return node;
	}
};

#endif	// _REVERSE_LINKED_LIST_H_
