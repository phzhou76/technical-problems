#pragma once
#ifndef _EVALUATE_REVERSE_POLISH_NOTATION_H_
#define _EVALUATE_REVERSE_POLISH_NOTATION_H_

#include "pch.h"

/**
 * Problem: Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation. Valid operators are +, -, *, /. Each operand may  be an integer
 * or another expression. 
 *
 * Note:
 *	1. Division between two integer should truncate towards zero.
 *	2. The expression will always be valid.
 */
class EvaluateReversePolishNotation
{
public:
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