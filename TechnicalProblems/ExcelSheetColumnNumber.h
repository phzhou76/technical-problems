#pragma once
#ifndef _EXCEL_SHEET_COLUMN_NUMBER_H_
#define _EXCEL_SHEET_COLUMN_NUMBER_H_

#include "pch.h"

/**
 * Problem: Given a column title as in an Excel spreadsheet, return its corresponding
 * column number.
 */
class ExcelSheetColumnNumber
{
public:

	/* Add values of the alphabet characters backwards to calculate the "ones"
	 * place, the "tens" place, and so on. */
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