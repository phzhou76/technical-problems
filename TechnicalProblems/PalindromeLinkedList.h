#pragma once
#ifndef _PALINDROME_LINKED_LIST_H_
#define _PALINDROME_LINKED_LIST_H_

#include "LeetCodeLinkedListNode.h"

/**
 * Problem: Given a singly-linked list, determine if it is a palindrome. Could this
 * problem be solved in O(n) time and O(1) space?
 */
class PalindromeLinkedList
{
public:

	/* Approach 1: This can be solved by reversing the first half of the list, and 
	 * and then comparing the first and second halves of the list. If the elements
	 * are the same in both lists, then the list is palindromic. 
	 *
	 * We can do this by first determining the length of the linked list, assume
	 * that this length is n. Then, we reverse the first n/2 nodes in the linked
	 * list (see ReverseLinkedListII to see how to reverse a subsection of a 
	 * linked list). 
	 *
	 * Then, we start scanning both lists to see if the contents match. If the
	 * solution from ReverseLinkedListII was used, the pointer that points to
	 * the start of the first half is now pointing to the last element. We can
	 * use this pointer as the scanner for the second half. If the length of the
	 * linked list is even, then the start of the second half is the next node.
	 * If the linked list is odd, then the start of the second half is the node
	 * after the next node. Create a new pointer to the start of the first half
	 * of the linked list, and start scanning until the second half's pointer is
	 * null. During the scan, if the two pointers ever point to different values,
	 * return false. 
	 *
	 * Return true at the end, since both halves contain the same values.
	 *
	 * Approach 2: If the interviewer doesn't want you to corrupt the contents
	 * of the list, then approach 1 can still be done, but the first half just
	 * needs to be reversed again, and the head pointer should point to the
	 * original head. However, if the interviewer doesn't want you to modify the
	 * contents of the list at all, then we can do this recursively.
	 *
	 * Calculate the length of the list, assume that this value is n. Create a 
	 * stack, and push all elements from index 0 to index n/2 to a stack, where
	 * the node at index n/2 is on top of the stack at the end. Then, create a
	 * pointer for the second half of the list. If the length of the list was even,
	 * then the pointer of the second half of the list can be stack.top()->next.
	 * If the length of the list was odd, then the pointer of the second half of
	 * the list can be stack.top()->next->next. Compare the pointer in the second
	 * half of the list with the top of the stack to see if they match. Pop the
	 * stack and increment the pointer after each iteration, and continue until
	 * the stack is empty. 
	 *
	 * This approach will have a space complexity of O(n). */
	bool isPalindrome(ListNode * head)
	{

	}
};

#endif	// _PALINDROME_LINKED_LIST_H_