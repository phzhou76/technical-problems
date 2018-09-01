#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "LinkedListNode.h"

/**
 * Custom implementation of a doubly-linked list.
 */
template <class T>
class LinkedList
{
private:
	int mSize;
	LinkedListNode<T> * mHead;
	LinkedListNode<T> * mTail;

public:
	LinkedList() : mSize(0)
	{
		mHead = mTail = nullptr;
	}

	/**
	 * Safely deletes each heap-allocated node in the linked list.
	 */
	~LinkedList()
	{
		LinkedListNode<T> * currNode = mHead;

		while (currNode != nullptr)
		{
			LinkedListNode<T> * deleteNode = currNode;
			currNode = currNode->mNextNode;

			delete deleteNode;
		}
	}

	/**
	 * Inserts a new element into the linked list.
	 *
	 * @param data	The data to insert into the linked list.
	 * @param index	The index in the linked list at which to insert at.
	 */
	void insertElement(T data, int index)
	{
		/* Attempting to insert in an out of bounds area. */
		if (index < 0 || index > mSize)
		{
			throw std::out_of_range("Index out of bounds.");
		}

		LinkedListNode<T> * newNode = new LinkedListNode<T>(data);
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
			LinkedListNode<T> * currentNode = mHead;
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
	}

	/**
	 * Inserts element at the head of the linked list.
	 *
	 * @param data	The data to insert at the head of the linked list.
	 */
	void insertHead(T data)
	{
		insertElement(data, 0);
	}

	/**
	 * Inserts element at the tail of the linked list.
	 *
	 * @param data	The data to insert at the tail of the linked list.
	 */
	void insertTail(T data)
	{
		insertElement(data, mSize);
	}

	/**
	 * Deletes an element from the linked list.
	 *
	 * @param index	The index of the element in the linked list to delete.
	 */
	void deleteElement(int index)
	{
		/* Attempting to delete in an out of bounds area. */
		if (index < 0 || index > mSize - 1)
		{
			throw std::out_of_range("Index out of bounds.");
		}

		/* Obtain the node to delete. */
		LinkedListNode<T> * currentNode = mHead;
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
	}

	/**
	 * Deletes a given element from the linked list.
	 *
	 * @param element	The element to delete from the linked list.
	 */
	void deleteElement(LinkedListNode<T> element)
	{
		LinkedListNode<T> * currentNode = mHead;

		/* Determine if the node actually exists in the linked list. */
		while (currentNode != nullptr)
		{
			if (currentNode == element)
			{
				break;
			}

			currentNode = currentNode->mNextNode;
		}

		if (currentNode == nullptr)
		{
			throw std::invalid_argument("Node is not present in linked list.");
		}

		--mSize;

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
	}

	/**
	 * Deletes the head element.
	 */
	void deleteHead()
	{
		deleteElement(mHead);
	}

	/**
	 * Deletes the tail element.
	 */
	void deleteTail()
	{
		deleteElement(mTail);
	}

	/**
	 * Obtains an element in the linked list.
	 *
	 * @param index	The index of the element to obtain.
	 *
	 * @return The element in the linked list.
	 */
	LinkedListNode<T> * getElement(int index)
	{
		/* Attempting to access an out of bounds area. */
		if (index < 0 || index > mSize - 1)
		{
			throw std::out_of_range("Index out of bounds.");
		}

		LinkedListNode<T> * currentNode = mHead;
		for (int i = 0; i < index && currentNode != nullptr; ++i)
		{
			currentNode = currentNode->mNextNode;
		}

		return currentNode;
	}

	/**
	 * Obtains the head in the linked list.
	 * 
	 * @return The head in the linked list.
	 */
	LinkedListNode<T> * getHead()
	{
		return mHead;
	}

	/**
	 * Obtains the tail in the linked list.
	 * 
	 * @return The tail in the linked list.
	 */
	LinkedListNode<T> * getTail()
	{
		return mTail;
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

#endif	// _LINKED_LIST_H_