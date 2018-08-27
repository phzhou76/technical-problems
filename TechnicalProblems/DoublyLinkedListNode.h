#pragma once
#ifndef _DOUBLY_LINKED_LIST_NODE_H_
#define _DOUBLY_LINKED_LIST_NODE_H_

/**
 * Custom implementation of a doubly-linked list node.
 */
template <class T>
class DoublyLinkedListNode
{
public:
	DoublyLinkedListNode<T> * mPreviousNode;
	DoublyLinkedListNode<T> * mNextNode;
	T mData;

	DoublyLinkedListNode(T data) : mData(data)
	{
		mPreviousNode = mNextNode = nullptr;
	}
};

#endif	// _DOUBLY_LINKED_LIST_NODE_H_
