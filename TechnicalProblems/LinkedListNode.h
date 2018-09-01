#pragma once
#ifndef _LINKED_LIST_NODE_H_
#define _LINKED_LIST_NODE_H_

/**
 * Custom implementation of a doubly-linked list node.
 */
template <class T>
class LinkedListNode
{
public:
	LinkedListNode<T> * mPreviousNode;
	LinkedListNode<T> * mNextNode;
	T mData;

	LinkedListNode(T data) : mData(data)
	{
		mPreviousNode = mNextNode = nullptr;
	}
};

#endif	// _LINKED_LIST_NODE_H_
