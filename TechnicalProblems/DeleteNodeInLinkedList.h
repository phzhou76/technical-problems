#pragma once
#ifndef _DELETE_NODE_IN_LINKED_LIST_H_
#define _DELETE_NODE_IN_LINKED_LIST_H_

#include "LinkedListNode.h"

/**
 * Problem: Write a method to delete a node (except a tail) in a singly Linked
 * List, given only access to that node.
 *
 * Note: The Linked List will always have at least two elements, and the given 
 *		node to delete will never be the tail of the Linked List. 
 */
class DeleteNodeInLinkedList
{
public:

	/* Instead of deleting this particular node, which cannot be done without a
	 * reference to the previous node, we can move the value of the next node
	 * to this node, and delete the next node safely. 
	 */
	void deleteNode(LinkedListNode<int> * node)
	{
		node->mData = node->mNextNode->mData;
		LinkedListNode<int> * deleteNode = node->mNextNode;
		node->mNextNode = node->mNextNode->mNextNode;
		delete deleteNode;
	}
};

#endif	// _DELETE_NODE_IN_LINKED_LIST_H_