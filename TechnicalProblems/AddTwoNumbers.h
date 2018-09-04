#pragma once
#ifndef _ADD_TWO_NUMBERS_H_
#define _ADD_TWO_NUMBERS_H_

#include "LinkedListNode.h"

/**
 * Problem: Given two non-empty linked lists representing two non-negative integers,
 * add the two numbers and return it as a linked list. The numbers are stored in
 * reverse order; i.e. 807 would be stored as 7->0->8.
 */
class AddTwoNumbers
{
public:
	static LinkedListNode<int> * addTwoNumbers(LinkedListNode<int> * num1,
		LinkedListNode<int> * num2)
	{
		LinkedListNode<int> * sumList = nullptr;
		LinkedListNode<int> * currentDigit = nullptr;

		/* Continue to sum up digits until one or both lists run out of digits. */
		int carry = 0;
		while (num1 != nullptr && num2 != nullptr)
		{
			int sum = num1->mData + num2->mData + carry;
			int digit = sum % 10;
			carry = sum / 10;

			/* Initialize sum list. */
			if (sumList == nullptr)
			{
				sumList = currentDigit = new LinkedListNode<int>(digit);
			}
			else
			{
				currentDigit->mNextNode = new LinkedListNode<int>(digit);
				currentDigit = currentDigit->mNextNode;
			}

			/* Increment digit pointers of both numbers. */
			num1 = num1->mNextNode;
			num2 = num2->mNextNode;
		}

		/* Extract the digits from the remaining list, if there is one. */
		LinkedListNode<int> * remainingList = (num1 == nullptr) ? num2 : num1;

		while (remainingList != nullptr)
		{
			int sum = remainingList->mData + carry;
			int digit = sum % 10;
			carry = sum / 10;

			/* Don't need to check if sumList is null, since non-empty lists are guaranteed. */
			currentDigit->mNextNode = new LinkedListNode<int>(digit);
			currentDigit = currentDigit->mNextNode;

			remainingList = remainingList->mNextNode;
		}

		/* Possible that carry is still 1 after adding the two numbers, need to create new digit. */
		if (carry == 1)
		{
			currentDigit->mNextNode = new LinkedListNode<int>(carry);
		}

		return sumList;
	}
};

#endif	// _ADD_TWO_NUMBERS_H_