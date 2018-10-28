#pragma once
#ifndef _PASCALS_TRIANGLE_H_
#define _PASCALS_TRIANGLE_H_

#include "pch.h"

/**
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle. For example, if the number of rows given is 5, then generate the
 * first 5 rows of Pascal's Triangle, which is represented as an array of int
 * arrays.
 *
 * Questions:
 *	1. What should be returned if the input is 0?
 *
 * Source: https://leetcode.com/problems/pascals-triangle/description/
 */
class PascalsTriangle
{
public:
	std::vector<std::vector<int>> generate(int numRows)
	{
		/* Holds Pascal's Triangle. */
		std::vector<std::vector<int>> pascalsTriangle;

		/* Generate each row in Pascal's Triangle. */
		for (int row = 1; row <= numRows; ++row)
		{
			pascalsTriangle.push_back(std::vector<int>());

			/* First and last element in the row should be 1, all other elements
			 * in the row should take the sum of the two elements in the row above.
			 *
			 * If the element's zero-based index is i, then the two elements that
			 * should be used for its sum are located at i - 1 and i. */
			for (int rowElement = 0; rowElement < row; ++rowElement)
			{
				if (rowElement == 0 || rowElement == row - 1)
				{
					pascalsTriangle.back().push_back(1);
				}
				else
				{
					int elementSum = pascalsTriangle[pascalsTriangle.size() - 2][rowElement - 1]
						+ pascalsTriangle[pascalsTriangle.size() - 2][rowElement];
					pascalsTriangle.back().push_back(elementSum);
				}
			}
		}

		return pascalsTriangle;
	}
};

#endif	// _PASCALS_TRIANGLE_H_