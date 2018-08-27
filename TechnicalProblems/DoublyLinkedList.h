#pragma once
#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include "DoublyLinkedListNode.h"

/**
 * Custom implementation of a doubly-linked list.
 */
template <class T>
class DoublyLinkedList
{
private:
	int mSize;
	DoublyLinkedListNode<T> * mHead;
	DoublyLinkedListNode<T> * mTail;

public:
	
	DoublyLinkedList() : mSize(0)
	{
		mHead = mTail = nullptr;
	}

	/**
	 * Safely deletes each heap-allocated node in the linked list.
	 */
	~DoublyLinkedList()
	{
		DoublyLinkedListNode<T> * currNode = mHead;

		while (currNode != nullptr)
		{
			DoublyLinkedListNode<T> * deleteNode = currNode;
			currNode = currNode->mNextNode;

			delete deleteNode;
		}
	}

	/**
	 * Inserts a new node into the linked list.
	 *
	 * @param data	The data to insert into the linked list.
	 * @param index	The index in the linked list at which to insert at.
	 *
	 * @return True if the operation was successful, false otherwise.
	 */
	bool insertNode(T data, int index)
	{
		/* Attempting to insert in an out of bounds area. */
		if (index < 0 || index > mSize)
		{
			return false;
		}

		DoublyLinkedListNode<T> * newNode = new DoublyLinkedListNode<T>(data);
		++mSize;

		/* Edge case: Insert node at the front of the linked list. */
		if (index == 0)
		{
			/* Only update connection between new node and head node if it exists. */
			if (mHead != nullptr)
			{
				newNode->mNextNode = mHead;
				mHead->mPreviousNode = newNode;
			}

			mHead = newNode;
		}
		else
		{
			/* Obtain the node before the index to insert at. */
			DoublyLinkedListNode<T> * currentNode = mHead;
			for (int i = 0; (i < index - 1) && currentNode != nullptr; ++i)
			{
				currentNode = currentNode->mNextNode;
			}

			/* Only update connection between new node and next node if it exists. */
			if (currentNode->mNextNode != nullptr)
			{
				newNode->mNextNode = currentNode->mNextNode;
				currentNode->mNextNode->mPreviousNode = newNode;
			}

			/* Update connection between previous node and new node. */
			newNode->mPreviousNode = currentNode;
			currentNode->mNextNode = newNode;
		}

		/* Edge case: The new node is the new tail of the linked list. */
		if (newNode->mNextNode == nullptr)
		{
			mTail = newNode;
		}

		return true;
	}

	/**
	 * Deletes a node from the linked list.
	 *
	 * @param index	The index of the node in the linked list to delete.
	 *
	 * @return True if the operation was successful, false otherwise.
	 */
	bool deleteNode(int index)
	{
		/* Attempting to delete in an out of bounds area. */
		if (index < 0 || index > mSize - 1)
		{
			return false;
		}

		/* Obtain the node to delete. */
		DoublyLinkedListNode<T> * currentNode = mHead;
		--mSize;

		for (int i = 0; i < index && currentNode != nullptr; ++i)
		{
			currentNode = currentNode->mNextNode;
		}

		/* Update previous node's connections, if null the delete node is head. */
		if (currentNode->mPreviousNode != nullptr)
		{
			currentNode->mPreviousNode->mNextNode = currentNode->mNextNode;
		}
		else
		{
			mHead = currentNode->mNextNode;
		}

		/* Update next node's connections, if null the delete node is tail. */
		if (currentNode->mNextNode != nullptr)
		{
			currentNode->mNextNode->mPreviousNode = currentNode->mPreviousNode;
		}
		else
		{
			mTail = currentNode->mPreviousNode;
		}

		/* Free up allocated space for the deleted node. */
		currentNode->mPreviousNode = nullptr;
		currentNode->mNextNode = nullptr;
		delete currentNode;

		return true;
	}
	
	/**
	 * Obtains a node in the linked list.
	 *
	 * @param index	The index of the node to obtain.
	 *
	 * @return The node in the linked list, or null if the operation failed.
	 */
	DoublyLinkedListNode<T> * getNode(int index)
	{
		/* Attempting to access an out of bounds area. */
		if (index < 0 || index > mSize - 1)
		{
			return nullptr;
		}

		DoublyLinkedListNode<T> * currentNode = mHead;
		for (int i = 0; i < index && currentNode != nullptr; ++i)
		{
			currentNode = currentNode->mNextNode;
		}

		return currentNode;
	}

	/**
	 * Returns the number of elements in the linked list.
	 *
	 * @return The number of elements in the linked list.
	 */
	int getSize()
	{
		return mSize;
	}
};

#endif	// _DOUBLY_LINKED_LIST_H_