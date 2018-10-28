#pragma once
#ifndef _MERGED_K_SORTED_LISTS_H_
#define _MERGED_K_SORTED_LISTS_H_

#include "pch.h"
#include "LinkedListNode.h"

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Source: https://leetcode.com/problems/merge-k-sorted-lists/
 */
class MergedKSortedLists
{
public:

	/* The runtime of this algorithm should be O(n * r), where n is the number of
	 * lists, and r is the length of the longest list. 
	 */
	LinkedListNode<int>* mergeKLists(std::vector<LinkedListNode<int>*>& lists)
	{
		/* Can't merge if no lists are available. */
		if (determineIfAllEmpty(lists))
		{
			return nullptr;
		}

		/* Instantiate the merged list by obtaining the minimum element of the 
		 * lists. */
		LinkedListNode<int> * mergedList = nullptr;
		LinkedListNode<int> * currentNode = nullptr;
		int minimumNodeIndex = findMinimumNodeIndex(lists);

		mergedList = currentNode = lists[minimumNodeIndex];
		lists[minimumNodeIndex] = lists[minimumNodeIndex]->mNextNode;

		/* The findMinimumNodeIndex method will continue to return the index of
		 * the list that has the lowest value. If there are no lists left, then 
		 * it will just return -1. */
		while ((minimumNodeIndex = findMinimumNodeIndex(lists)) != -1)
		{
			/* Update the current node's next node, and then update both the 
			 * current node pointer and the list's pointer that was just used. */
			currentNode->mNextNode = lists[minimumNodeIndex];
			currentNode = currentNode->mNextNode;
			lists[minimumNodeIndex] = lists[minimumNodeIndex]->mNextNode;
		}

		return mergedList;
	}

	bool determineIfAllEmpty(std::vector<LinkedListNode<int> *> &lists)
	{
		for (int i = 0; i < lists.size(); ++i)
		{
			if (lists[i] != nullptr)
			{
				return false;
			}
		}

		return true;
	}

	int findMinimumNodeIndex(std::vector<LinkedListNode<int> *> &lists)
	{
		int minValue = std::numeric_limits<int>::max();
		int minIndex = -1;

		/* To find just the minimum value, a min heap does not need to be used. 
		 * A simple O(n) sweep can be used instead. */
		for (int i = 0; i < lists.size(); ++i)
		{
			if (lists[i] != nullptr && lists[i]->mData < minValue)
			{
				minValue = lists[i]->mData;
				minIndex = i;
			}
		}

		return minIndex;
	}
};

#endif	// _MERGED_K_SORTED_LISTS_H_