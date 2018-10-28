#pragma once
#ifndef _EXCEL_SHEET_COLUMN_NUMBER_H_
#define _EXCEL_SHEET_COLUMN_NUMBER_H_

#include "pch.h"

/**
 * Given a column title as in an Excel spreadsheet, return its corresponding
 * column number.
 *
 * Source: https://leetcode.com/problems/excel-sheet-column-title/description/
 */
class ExcelSheetColumnNumber
{
public:

	/* Add values of the alphabet characters backwards to calculate the "ones"
	 * place, the "tens" place, and so on. Think of the column titles as a base
	 * 26 numerical system, where each digits place is 26-fold of the previous
	 * one. 
	 *
	 * For example, the 'A' in "AAZ" would be calculated by extracting its
	 * numerical value (1), and multiplying it by 26 * 26. This is similar to 
	 * how the 5 in 526 would be calculated - extract the 5 from 526, and
	 * multiply it by 10 * 10 to account for its digit place. 
	 */
	int titleToNumber(std::string s)
	{
		int columnNumber = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			int alphabetValue = convertAlphabetToInt(s[s.length() - 1 - i]);
			columnNumber += std::pow(26, i) * alphabetValue;
		}

		return columnNumber;
	}

	int convertAlphabetToInt(char alphabetChar)
	{
		return alphabetChar - 'A' + 1;
	}
};

#endif	// _EXCEL_SHEET_COLUMN_NUMBER_H_