#pragma once
#ifndef _INTERSECTION_LINKED_LISTS_H_
#define _INTERSECTION_LINKED_LISTS_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Write a program to find the node at which the intersection of two 
 * singly-linked lists begins.
 *
 * Notes:
 *	1. If the two linked lists have no intersection at all, return null.
 *	2. The linked lists must retain their original structure after the method
 *		returns.
 *	3. You may assume that there are no cycles anywhere in the entire linked
 *		list structure.
 *	4. Your code should preferably run in O(n) time and use only O(1) memory.
 *
 * Source: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 */
class IntersectionLinkedLists
{
public:

	/* We can detect the first intersecting node if headA and headB were the same
	 * number of nodes away from the first intersecting node. We can force this
	 * to happen by counting the lengths of both lists, and then figuring out the
	 * difference in lengths between the two. 
	 *
	 * Advance the longer list by the difference in the lengths so that headA and
	 * headB are the same distance from the intersecting node. Advance until the
	 * intersecting node has been found. If the pointers reach the end of their
	 * respective lists, that means the intersecting node was never found, so an
	 * intersection never existed. 
	 */
	ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
	{
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}

		/* Calculate the lengths of both singly-linked lists. */
		int lenA = 0;
		int lenB = 0;

		ListNode * aPtr = headA;
		ListNode * bPtr = headB;

		while (aPtr != nullptr)
		{
			++lenA;
			aPtr = aPtr->next;
		}

		while (bPtr != nullptr)
		{
			++lenB;
			bPtr = bPtr->next;
		}

		int lenDiff = lenA - lenB;

		/* Adjust the longer list's head to match the shorter list. */
		if (lenDiff > 0)
		{
			for (int i = 0; i < lenDiff; ++i)
			{
				headA = headA->next;
			}
		}
		else
		{
			for (int i = 0; i < -lenDiff; ++i)
			{
				headB = headB->next;
			}
		}

		/* Now that both linked lists are the same distance from the end, attempt
		 * to find the first node where the pointers match. */
		while (headA != nullptr)
		{
			if (headA == headB)
			{
				return headA;
			}

			headA = headA->next;
			headB = headB->next;
		}

		return nullptr;
	}
};

#endif	// _INTERSECTION_LINKED_LISTS_H_