#pragma once
#ifndef _MERGE_TWO_SORTED_LISTS_H_
#define _MERGE_TWO_SORTED_LISTS_H_

#include "LinkedListNode.h"

/**
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Source: https://leetcode.com/problems/merge-two-sorted-lists/description/
 */
class MergeTwoSortedLists
{
public:
	LinkedListNode<int>* mergeTwoLists(LinkedListNode<int>* l1, LinkedListNode<int>* l2)
	{
		/* Initial checking to ensure lists actually exist. If one list doesn't
		 * exist, the merged list is just the other list. */
		if (l1 == nullptr)
		{
			return l2;
		}
		else if (l2 == nullptr)
		{
			return l1;
		}

		/* Create a new list using the minimum value between the two lists. */
		LinkedListNode<int> * newList = nullptr;
		LinkedListNode<int> * currNode = nullptr;

		if (l1->mData < l2->mData)
		{
			newList = currNode = l1;
			l1 = l1->mNextNode;
		}
		else
		{
			newList = currNode = l2;
			l2 = l2->mNextNode;
		}

		/* Continue to add the minimum of the two lists to the current list until 
		 * one list runs out of elements. */
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->mData < l2->mData)
			{
				currNode->mNextNode = l1;
				currNode = currNode->mNextNode;
				l1 = l1->mNextNode;
			}
			else
			{
				currNode->mNextNode = l2;
				currNode = currNode->mNextNode;
				l2 = l2->mNextNode;
			}
		}

		/* Add the remainder of the list that still has elements left over. */
		currNode->mNextNode = (l1 != nullptr) ? l1 : l2;

		return newList;
	}
};

#endif	// _MERGE_TWO_SORTED_LISTS_H_