#pragma once
#ifndef _COPY_LIST_RANDOM_POINTER_H_
#define _COPY_LIST_RANDOM_POINTER_H_

#include "pch.h"

/**
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of this list.
 *
 * Source: https://leetcode.com/problems/copy-list-with-random-pointer/description/
 */

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) { }
};

class CopyListRandomPointer
{
public:
	RandomListNode * copyRandomList(RandomListNode * head)
	{
		/* Maps each node to their respective deep copied node. This is needed
		 * so that when the original list is looked at for each node's random
		 * pointers, we know the respective node in the deep copied list. */
		std::unordered_map<RandomListNode *, RandomListNode *> origToCopy;

		/* Create a deep copy of each node before making random node links. */
		RandomListNode * fakeHead = new RandomListNode(0);

		RandomListNode * currDupePtr = fakeHead;
		RandomListNode * currOrigPtr = head;

		while (currOrigPtr != nullptr)
		{
			RandomListNode * dupe = new RandomListNode(currOrigPtr->label);
			currDupePtr->next = dupe;
			currDupePtr = currDupePtr->next;

			/* Map each original node to its deep copy node. */
			origToCopy[currOrigPtr] = dupe;
			currOrigPtr = currOrigPtr->next;
		}

		currOrigPtr = head;
		currDupePtr = fakeHead->next;

		while (currOrigPtr != nullptr)
		{
			/* Obtain the random node pointer from the current original node. */
			RandomListNode * randomNode = currOrigPtr->random;

			/* Possible for the random node pointer to be null. */
			if (randomNode != nullptr)
			{
				/* Obtain the respective deep copy node of the random node, and
				 * then have the current deep copy node point to that node. */
				RandomListNode * randomCopyNode = origToCopy[randomNode];
				currDupePtr->random = randomCopyNode;
			}

			currOrigPtr = currOrigPtr->next;
			currDupePtr = currDupePtr->next;
		}

		RandomListNode * deleteNode = fakeHead;
		fakeHead = fakeHead->next;
		delete deleteNode;

		return fakeHead;
	}
};

#endif	// _COPY_LIST_RANDOM_POINTER_H_