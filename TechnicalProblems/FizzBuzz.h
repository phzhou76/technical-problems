#pragma once
#ifndef _FIZZ_BUZZ_H_
#define _FIZZ_BUZZ_H_

#include "pch.h"

/**
 * Problem: Write a program that outputs the string representation of numbers 
 * from 1 to n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and 
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Questions:
 *	1. Is it 1 to n inclusive or 1 to n exclusive?
 */
class FizzBuzz
{
public:
	std::vector<std::string> fizzBuzz(int n)
	{
		std::vector<std::string> fizzBuzzResult;
	
		for (int i = 1; i <= n; ++i)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				fizzBuzzResult.push_back("FizzBuzz");
			}
			else if (i % 3 == 0)
			{
				fizzBuzzResult.push_back("Fizz");
			}
			else if (i % 5 == 0)
			{
				fizzBuzzResult.push_back("Buzz");
			}
			else
			{
				fizzBuzzResult.push_back(std::to_string(i));
			}
		}

		return fizzBuzzResult;
	}
};

#endif	// _FIZZ_BUZZ_H_