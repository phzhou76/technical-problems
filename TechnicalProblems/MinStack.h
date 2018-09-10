#pragma once
#ifndef _MIN_STACK_H_
#define _MIN_STACK_H_

#include "pch.h"

/**
 * Problem: Design a stack that supports push, pop, top, and retrieving the 
 * minimum element in constant time.
 *
 *	push(x) -- Push element x onto stack.
 *	pop() -- Removes the element on top of the stack.
 *	top() -- Get the top element.
 *	getMin() -- Retrieve the minimum element in the stack.
 */
class MinStack
{
private:
	std::stack<int> mStack;
	std::stack<int> mMinimumValues;

public:
	/** initialize your data structure here. */
	MinStack() { }

	void push(int x) {
		mStack.push(x);

		/* Only push a value onto the minimum stack if it is less than the current
		 * minimum of the stack, or if it is the only element in the stack. */
		if (mMinimumValues.empty() || x <= mMinimumValues.top())
		{
			mMinimumValues.push(x);
		}
	}

	void pop() {
		int poppedValue = mStack.top();
		mStack.pop();

		/* If the value to be popped is located at the top of the minimum values
		 * stack, then it must have been a minimum value at some point in the
		 * stack. Pop it so that the next minimum value can be easily retreived. */
		if (poppedValue == mMinimumValues.top())
		{
			mMinimumValues.pop();
		}
	}

	int top() {
		return mStack.top();
	}

	int getMin() {
		return mMinimumValues.top();
	}
};

#endif	// _MIN_STACK_H_