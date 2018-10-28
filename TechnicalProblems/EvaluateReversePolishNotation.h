#pragma once
#ifndef _EVALUATE_REVERSE_POLISH_NOTATION_H_
#define _EVALUATE_REVERSE_POLISH_NOTATION_H_

#include "pch.h"

/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation. 
 * Valid operators are +, -, *, /. Each operand may be an integer or another 
 * expression. 
 *
 * Note:
 *	1. Division between two integer should truncate towards zero.
 *	2. The expression will always be valid.
 *
 * Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 */
class EvaluateReversePolishNotation
{
public:

	/* Evaluating a series of tokens in Reverse Polish Notation is like doing
	 * arithmetic with computer architecture that uses stacks. 
	 *
	 *	1. Numbers that are encountered are pushed to the stack. 
	 *
	 *	2. If an operator is encountered, then pop two numbers off the stack 
	 *		(where the first number that gets popped is the second parameter, 
	 *		and the second number that gets popped is the first parameter). 
	 *
	 *	3. Perform the operation on the two numbers, and push the result back to
	 *		the stack. 
	 *
	 *	4. When all of the tokens have been processed, the result of the entire 
	 *		expression should be at the top of the stack. 
	 */
	int evalRPN(std::vector<std::string>& tokens) {
		std::stack<int> calculatorStack;

		for (int i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i].compare("+") == 0)
			{
				int secondOperand = calculatorStack.top();
				calculatorStack.pop();
				int firstOperand = calculatorStack.top();
				calculatorStack.pop();

				calculatorStack.push(firstOperand + secondOperand);
			}
			else if (tokens[i].compare("-") == 0)
			{
				int secondOperand = calculatorStack.top();
				calculatorStack.pop();
				int firstOperand = calculatorStack.top();
				calculatorStack.pop();

				calculatorStack.push(firstOperand - secondOperand);
			}
			else if (tokens[i].compare("*") == 0)
			{
				int secondOperand = calculatorStack.top();
				calculatorStack.pop();
				int firstOperand = calculatorStack.top();
				calculatorStack.pop();

				calculatorStack.push(firstOperand * secondOperand);
			}
			else if (tokens[i].compare("/") == 0)
			{
				int secondOperand = calculatorStack.top();
				calculatorStack.pop();
				int firstOperand = calculatorStack.top();
				calculatorStack.pop();

				calculatorStack.push(firstOperand / secondOperand);
			}

			/* If the token is not any of the four operands, it must be
			 * a number. */
			else
			{
				calculatorStack.push(std::stoi(tokens[i]));
			}
		}

		return calculatorStack.top();
	}
};

#endif	// _EVALUATE_REVERSE_POLISH_NOTATION_H_