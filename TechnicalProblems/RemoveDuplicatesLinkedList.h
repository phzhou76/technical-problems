#pragma once
#ifndef _REMOVE_DUPLICATES_LINKED_LIST_H_
#define _REMOVE_DUPLICATES_LINKED_LIST_H_

#include "LinkedList.h"

/**
 * Problem: Remove duplicates from an unsorted linked list. How would you solve
 * this problem if a temporary buffer is not allowed?
 *
 * Questions:
 *	1. Is this linked list a singly or doubly linked list? (For this problem, assume
 *		that it is a singly-linked list of ints.)
 *	2. What constitutes as a buffer? Like a data structure?
 *	3. What methods does the linked list implementation have? (For this problem,
 *		assume that insertion and deletion are available.)
 */
class RemoveDuplicatesLinkedList
{
private:
	static void removeDuplicates(LinkedList<int> &linkedList);
	static void removeDuplicatesNoBuffer(LinkedList<int> &linkedList);

public:
	static void testRemoveDuplicatesLinkedList();
};

#endif	// _REMOVE_DUPLICATES_LINKED_LIST_H_