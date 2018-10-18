#pragma once
#ifndef _PASCALS_TRIANGLE_II_H_
#define _PASCALS_TRIANGLE_II_H_

#include "pch.h"

/**
 * Problem: Given a non-negative index k where k <= 33, return the kth index row
 * of Pascal's Triangle. Note that the index k is zero-based.
 *
 * Note: Each entry in Pascal's table is actually equal to n choose k, where both 
 * n and k are zero-based. For example, the first row would be C(0,0). The second
 * row would be C(1,0); C(1,1). The third row would be C(2,0); C(2,1); C(2,2).
 *
 * Instead of calculating every single row and adding their sums up, we can use 
 * the combination formula to create each element in the desired row without 
 * requiring data from the previous row.
 *
 * Formula for calculating combinations is n!/(k! * (n - k)!)
 *
 * Issue with this approach is that factorials blow up in value very quickly, which
 * leads to overflows, so we should just build a row at a time.
 */
class PascalsTriangleII
{
public:
	std::vector<int> getRow(int rowIndex)
	{
		/* No calculations are needed if the row index is 1 or less. */
		if (rowIndex < 2)
		{
			return std::vector<int>(rowIndex + 1, 1);
		}

		/* Start at the index 1 row of two 1s. */
		std::vector<int> triangleRow(2, 1);
		for (int row = 2; row <= rowIndex; ++row)
		{
			/* Create the next row using the previous row of elements. */
			std::vector<int> currentRow;
			for (int i = 0; i <= row; ++i)
			{
				/* 1s need to be placed at the start and the end of the row. */
				if (i == 0 || i == row)
				{
					currentRow.push_back(1);
				}
				/* Any element inside of the row will sum up two elements from
				 * the previous row. */
				else
				{
					currentRow.push_back(triangleRow[i - 1] + triangleRow[i]);
				}
			}

			triangleRow = currentRow;
		}

		return triangleRow;
	}
};

#endif	// _PASCALS_TRIANGLE_II_H_