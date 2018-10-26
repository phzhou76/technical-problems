#pragma once
#ifndef _ADD_TWO_NUMBERS_H_
#define _ADD_TWO_NUMBERS_H_

#include "pch.h"
#include "LeetCodeLinkedListNode.h"

/**
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contains a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume that the two numbers do not contain any leading zeroes, except
 * for the number 0.
 *
 * Note: The number 807 would be stored as 7->0->8.
 *
 * Source: https://leetcode.com/problems/add-two-numbers/description/
 */
class AddTwoNumbers
{
public:
	ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
	{
		/* Edge Case: If the linked lists could be empty, it would need to be
		 * checked here. */
		if (l1 == nullptr || l2 == nullptr)
		{
			throw std::invalid_argument("Empty lists detected.");
		}

		/* Create a fake head for the summed list. */
		ListNode * sumList = new ListNode(0);
		ListNode * sumListPtr = sumList;

		/* Sum digits from both lists until one of them has run out of digits. */
		int carry = 0;
		while (l1 != nullptr && l2 != nullptr)
		{
			int sum = l1->val + l2->val + carry;
			int digit = sum % 10;
			carry = sum / 10;

			sumListPtr->next = new ListNode(digit);
			sumListPtr = sumListPtr->next;

			l1 = l1->next;
			l2 = l2->next;
		}

		/* Since at least one list has been completely emptied, add the remainder
		 * of the other list to the sum. */
		ListNode * remainingList = (l1 == nullptr) ? l2 : l1;
		while (remainingList != nullptr)
		{
			int sum = remainingList->val + carry;
		}
	}
};

#endif	// _ADD_TWO_NUMBERS_H_