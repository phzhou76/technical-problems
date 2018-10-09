#pragma once
#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_

#include "pch.h"

/**
 * Problem: Design and implement a data structure for a Least Recently Used (LRU)
 * cache. It should support the following operations:
 *	1. get(key): Get the value (will always be positive) of the key if the key
 *		exists in the cache, otherwise return -1.
 *	2. put(key, value): Set or insert the value if the key is not already present.
 *		When the cache has reached its capacity, it should invalidate the least
 *		recently used item before inserting a new item.
 *
 * Followup: Could both operations be implemented in O(1)?
 */

class LRULinkedListNode
{
public:
	LRULinkedListNode * mPreviousNode;
	LRULinkedListNode * mNextNode;
	int mKey;
	int mValue;

	LRULinkedListNode(int key, int value) : mKey(key), mValue(value)
	{
		mPreviousNode = mNextNode = nullptr;
	}
};

class LRULinkedList
{
public:
	LRULinkedListNode * mHead;
	LRULinkedListNode * mTail;

	LRULinkedList()
	{
		mHead = mTail = nullptr;
	}

	void addNewestItem(LRULinkedListNode * recentItem)
	{
		/* Edge case: No elements in the LRU cache. */
		if (mHead == mTail && mHead == nullptr)
		{
			mHead = mTail = recentItem;
		}
		else
		{
			mTail->mNextNode = recentItem;
			recentItem->mPreviousNode = mTail;
			mTail = recentItem;
		}
	}

	/* Note: Does not actually delete the node to deallocate memory, but just 
	 * removes the node from the linked list. */
	void extractItem(LRULinkedListNode * item)
	{
		/* Edge case: The item to remove is both the head and the tail. */
		if (item == mHead && item == mTail)
		{
			mHead = mTail = nullptr;
		}
		/* Edge case: The item to remove is the head. */
		else if (item == mHead)
		{
			mHead->mNextNode->mPreviousNode = nullptr;
			mHead = mHead->mNextNode;
		}
		/* Edge case: The item to remove is the tail. */
		else if (item == mTail)
		{
			mTail->mPreviousNode->mNextNode = nullptr;
			mTail = mTail->mPreviousNode;
		}
		else
		{
			item->mPreviousNode->mNextNode = item->mNextNode;
			item->mNextNode->mPreviousNode = item->mPreviousNode;
		}
	}

	LRULinkedListNode * removeOldestItem()
	{
		LRULinkedListNode * oldestItem = mHead;
		extractItem(oldestItem);
		return oldestItem;
	}
};

class LRUCache
{
public:

	/* A way to design a LRU cache is to use the following data structures:
	 *	1. Hash Map: Maps the key to the linked list node that holds the data.
	 *	2. Doubly-Linked List: Most recently read or written to key-value pairs
	 *		are placed at the back of the linked list, so the least recently used
	 *		values are pushed to the front of the linked list. */
	std::unordered_map<int, LRULinkedListNode *> mCache;
	LRULinkedList mLRUQueue;
	int mSize;
	int mCapacity;

	LRUCache(int capacity) : mSize(0), mCapacity(capacity) { }

	/* Try and obtain the desired value from the cache. If it doesn't exist, then
	 * just return -1. However, if it does exist, the key-value pair is now the
	 * most recently accessed item in the cache, so remove it from the queue, and
	 * push it to the back of the queue. */
	int get(int key)
	{
		std::unordered_map<int, LRULinkedListNode *>::iterator result = mCache.find(key);
		if (result == mCache.end())
		{
			return -1;
		}
		else
		{
			mLRUQueue.extractItem(result->second);
			mLRUQueue.addNewestItem(result->second);
			return result->second->mValue;
		}
	}
	
	/* Try and place the key-value pair into the cache. If the size capacity hasn't
	 * been hit yet, then just place the pair into the cache and update the queue.
	 * However, if the size capacity has been hit, then remove the oldest item
	 * from the queue and delete its respective mapping in the cache, and add the
	 * new pair into the cache and queue. */
	void put(int key, int value) 
	{ 	
		/* Edge case: No checking of size is necessary if the key-value pair already
		 * exists. */
		std::unordered_map<int, LRULinkedListNode *>::iterator result;
		if ((result = mCache.find(key)) == mCache.end())
		{
			mLRUQueue.extractItem(result->second);
			mLRUQueue.addNewestItem(result->second);
			result->second->mValue = value;
		}
		else
		{
			if (mSize == mCapacity)
			{
				LRULinkedListNode * oldestItem = mLRUQueue.removeOldestItem();
				mCache.erase(oldestItem->mKey);
				--mSize;
				delete oldestItem;
			}

			LRULinkedListNode * newestItem = new LRULinkedListNode(key, value);
			mCache[key] = newestItem;
			mLRUQueue.addNewestItem(newestItem);
			++mSize;
		}
	}
};

#endif	// _LRU_CACHE_H_