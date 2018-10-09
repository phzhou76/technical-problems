#pragma once
#ifndef _PARTITION_LIST_H_
#define _PARTITION_LIST_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Given a linked list and a value x, partition it such that all nodes
 * less than x come before nodes greater than or equal to x. You should preserve
 * the original relative order of the nodes in each of the two partition.
 */
class PartitionList
{
public:
	ListNode * partition(ListNode * head, int x)
	{
		/* Nothing to partition if there are less than 2 elements. */
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		/* Create two "fake" heads for the lesser and greater partitions. */
		ListNode * lesserPartition = new ListNode(0);
		ListNode * greaterPartition = new ListNode(0);
		ListNode * lesserPtr = lesserPartition;
		ListNode * greaterPtr = greaterPartition;

		ListNode * currPtr = head;
		while (currPtr != nullptr)
		{
			/* Partition each node to either the lesser or the greater partition
			 * linked lists. */
			if (currPtr->val < x)
			{
				lesserPtr->next = currPtr;
				lesserPtr = lesserPtr->next;
			}
			else
			{
				greaterPtr->next = currPtr;
				greaterPtr = greaterPtr->next;
			}

			currPtr = currPtr->next;
		}

		/* Now that we have the left and the right partitions, we need to take
		 * care of two possible edge cases:
		 *	1. All elements are on the left partition. If that's the case,
		 *		return the left partition without the fake head.
		 *	2. All elements are on the right partition. If that's the case, just
		 *		return the right partition without the fake head. 
		 *
		 * Else, we will just remove the fake heads from both partitions, and then
		 * attach the left partition to the right partition, and return the left
		 * partition. */
		if (lesserPartition->next == nullptr)
		{
			delete lesserPartition;
			ListNode * greaterDeleteNode = greaterPartition;
			greaterPartition = greaterPartition->next;
			greaterPtr->next = nullptr;
			delete greaterDeleteNode;

			return greaterPartition;
		}
		else if (greaterPartition->next == nullptr)
		{
			delete greaterPartition;
			ListNode * lesserDeleteNode = lesserPartition;
			lesserPartition = lesserPartition->next;
			lesserPtr->next = nullptr;
			delete lesserDeleteNode;

			return lesserPartition;
		}
		else
		{
			/* Delete the fake heads from both partition linked lists. */
			ListNode * lesserDeleteNode = lesserPartition;
			ListNode * greaterDeleteNode = greaterPartition;

			lesserPartition = lesserPartition->next;
			greaterPartition = greaterPartition->next;

			delete lesserDeleteNode;
			delete greaterDeleteNode;

			lesserPtr->next = greaterPartition;
			greaterPtr->next = nullptr;

			return lesserPartition;
		}
	}
};

#endif	// _PARTITION_LIST_H_