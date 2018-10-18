#pragma once
#ifndef _VALID_PARENTHESES_H_
#define _VALID_PARENTHESES_H_

#include "pch.h"

/**
 * Problem: Given a string containing just the characters '(', ')', '{', '}', 
 * '[' and ']', determine if the input string is a valid set of parentheses.
 */
class ValidParentheses
{
public:

	/* Use a stack to determine what the most recent set of parentheses is, since
	 * that's the parentheses that must be closed first with its matching pair. */
	bool isValid(std::string s) {
		std::stack<char> parenStack;

		for (int i = 0; i < s.length(); ++i)
		{
			/* Push left parentheses onto stack, since they must have a matching
			 * right parentheses. */
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				parenStack.push(s[i]);
			}

			/* Pop matching left parentheses off the stack, since a pair has been
			 * formed. However, the parentheses must pair with each other, otherwise
			 * the entire string is not a valid parentheses set. */
			else
			{
				/* Edge case: It's possible to have a string with just one right
				 * bracket. Check for that before examining the top of the stack. */
				if (parenStack.empty())
				{
					return false;
				}

				if (s[i] == ')' && parenStack.top() != '(')
				{
					return false;
				}
				else if (s[i] == ']' && parenStack.top() != '[')
				{
					return false;
				}
				else if (s[i] == '}' && parenStack.top() != '{')
				{
					return false;
				}

				parenStack.pop();
			}
		}

		/* All pairs were matched up. */
		return parenStack.empty();
	}
};

#endif	// _VALID_PARENTHESES_H_