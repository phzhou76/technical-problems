#pragma once
#ifndef _ROMAN_TO_INTEGER_H_
#define _ROMAN_TO_INTEGER_H_

#include "pch.h"

/**
 * Problem: Convert a roman string to an int value.
 */
class RomanToInteger
{
private:
	std::unordered_map<std::string, int> romanValues =
	{
		{"M", 1000},
		{"CM", 900},
		{"D", 500},
		{"CD", 400},
		{"C", 100},
		{"XC", 90},
		{"L", 50},
		{"XL", 40},
		{"X", 10},
		{"IX", 9},
		{"V", 5},
		{"IV", 4},
		{"I", 1}
	};

public:
	int romanToInt(std::string s) {
		int convertedRomanInt = 0;

		/* O(1) space complexity solution with no data structures. 50 ms slower
		 * than data structure version due to conditional statements. */
#if 0
		int i = 0;
		while (i < s.length())
		{
			convertedRomanInt += extractDigit(s, &i);
		}
#endif

		/* O(1) space complexity solution with data structures. Contains fewer
		 * conditional statements, since searching for strings in hash maps takes
		 * less time than going through multiple conditional statements. */
#if 1
		int i = 0;
		while (i < s.length())
		{
			/* Unless we're at the end of the string, always look forward.*/
			if (i != s.length() - 1)
			{
				/* Need to scan for possible multi-character roman numbers, like IV. */
				std::string substr = s.substr(i, 2);
				if (romanValues.find(substr) != romanValues.end())
				{
					convertedRomanInt += romanValues[substr];
					i += 2;
				}
				/* If the multi-character number doesn't exist, just read the single
				 * character's value. */
				else
				{
					convertedRomanInt += romanValues[std::string(1, s[i])];
					++i;
				}
			}
			/* At the end of the string, just scan the last character. */
			else
			{
				convertedRomanInt += romanValues[std::string(1, s[i])];
				++i;
			}
		}
#endif

		return convertedRomanInt;
	}

	int extractDigit(std::string inputStr, int * currentIndex)
	{
		if (*currentIndex >= inputStr.length())
		{
			return std::numeric_limits<int>::min();
		}

		switch (inputStr[*currentIndex])
		{
		case 'M':
			++(*currentIndex);
			return 1000;
		case 'D':
			++(*currentIndex);
			return 500;
		case 'C':
			/* Don't scan ahead if we're at the end of the string. */
			if (*currentIndex == inputStr.length() - 1)
			{
				++(*currentIndex);
				return 100;
			}

			/* Exception - CM is worth 900. Consume two of the characters. */
			if (inputStr[*currentIndex + 1] == 'M')
			{
				*currentIndex += 2;
				return 900;
			}

			/* Exception - CD is worth 400. Consume two of thw characters. */
			else if (inputStr[*currentIndex + 1] == 'D')
			{
				*currentIndex += 2;
				return 400;
			}

			else
			{
				++(*currentIndex);
				return 100;
			}
		case 'L':
			++(*currentIndex);
			return 50;
		case 'X':
			/* Don't scan ahead if we're at the end of the string. */
			if (*currentIndex == inputStr.length() - 1)
			{
				++(*currentIndex);
				return 10;
			}

			/* Exception - XC is worth 90. Consume two of the characters. */
			if (inputStr[*currentIndex + 1] == 'C')
			{
				*currentIndex += 2;
				return 90;
			}

			/* Exception - XL is worth 40. Consume two of the characters. */
			else if (inputStr[*currentIndex + 1] == 'L')
			{
				*currentIndex += 2;
				return 40;
			}

			else
			{
				++(*currentIndex);
				return 10;
			}
		case 'V':
			++(*currentIndex);
			return 5;
		case 'I':
			/* Don't scan ahead if we're at the end of the string. */
			if (*currentIndex == inputStr.length() - 1)
			{
				++(*currentIndex);
				return 1;
			}

			/* Exception - IX is worth 9. Consume two of the characters. */
			if (inputStr[*currentIndex + 1] == 'X')
			{
				*currentIndex += 2;
				return 9;
			}

			/* Exception - IV is worth 4. Consume two of the characters. */
			else if (inputStr[*currentIndex + 1] == 'V')
			{
				*currentIndex += 2;
				return 4;
			}

			else
			{
				++(*currentIndex);
				return 1;
			}
		default:
			return std::numeric_limits<int>::min();
		}
	}
};

#endif	// _ROMAN_TO_INTEGER_H_