#pragma once
#ifndef _SPIRAL_MATRIX_H_
#define _SPIRAL_MATRIX_H_

#include "pch.h"

/**
 * Problem: Given a matrix of m x n elements (m rows, n columns), return all
 * elements in spiral order. Start at the top left element, and then rotate
 * clockwise.
 *
 * Questions:
 *	1. What should be returned if the spiral matrix is empty?
 *	2. How should the algorithm work if the matrix doesn't have a natural spiral
 *		to it (e.g. a matrix of just one row)?
 *	3. How is the matrix represented? Is the matrix represented as matrix[m][n],
 *		or is it represented as matrix[n][m]?
 */
class SpiralMatrix
{
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
	{
		/* Edge Case: Can't extract spiral order if the matrix is empty. */
		if (matrix.empty() || matrix[0].empty())
		{
			return std::vector<int>();
		}

		std::vector<int> spiralArray;

		/* Row[] and column[][] indices for the top left element of the box layer. */
		int topLeftRow = 0;
		int topLeftColumn = 0;

		/* Row[] and column[][] indices for the bottom right element of the box
		 * layer.*/
		int bottomRightRow = matrix.size() - 1;
		int bottomRightColumn = matrix[0].size() - 1;

		/* Only continue to spiral through the matrix as long as the top left
		 * coordinate is less than or equal to the bottom right coordinate in both
		 * x and y coordinates. This ensures that there is still a "box layer" to sweep
		 * through. */
		while (topLeftRow <= bottomRightRow && topLeftColumn <= bottomRightColumn)
		{
			/* Edge case: The box layer only has a width of 1 (i.e. the top left
			 * x-coordinate and the bottom right x-coordinate are the same. Add
			 * all of the elements in this column layer. */
			if (topLeftColumn == bottomRightColumn)
			{
				for (int i = topLeftRow; i <= bottomRightRow; ++i)
				{
					spiralArray.push_back(matrix[i][topLeftColumn]);
				}
			}
			/* Edge case: The box layer only has a height of 1 (i.e. the top left
			 * y-coordinate and the bottom right y-coordinate are the same. Add
			 * all of the elements in this row layer. */
			else if (topLeftRow == bottomRightRow)
			{
				for (int i = topLeftColumn; i <= bottomRightColumn; ++i)
				{
					spiralArray.push_back(matrix[topLeftRow][i]);
				}
			}
			/* Add elements from the top, right, bottom, and left sides of the
			 * box layer. */
			else
			{
				/* Add elements from the top portion of the box layer (excluding
				 * the last element of the top row, since that will be used for
				 * the right side). */
				for (int i = topLeftColumn; i < bottomRightColumn; ++i)
				{
					spiralArray.push_back(matrix[topLeftRow][i]);
				}

				/* Add elements from the right portion of the box layer (excluding
				 * the last element of the right column, since that will be used for
				 * the bottom side). */
				for (int i = topLeftRow; i < bottomRightRow; ++i)
				{
					spiralArray.push_back(matrix[i][bottomRightColumn]);
				}

				/* Add elements from the bottom portion of the box layer (excluding
				 * the first element of the bottom row, since that will be used
				 * for the left side). */
				for (int i = bottomRightColumn; i > topLeftColumn; --i)
				{
					spiralArray.push_back(matrix[bottomRightRow][i]);
				}

				/* Add elements from the left portion of the box layer. The first
				 * element of the left column had already been added in the top
				 * row). */
				for (int i = bottomRightRow; i > topLeftRow; --i)
				{
					spiralArray.push_back(matrix[i][topLeftColumn]);
				}
			}

			/* Move onto the next inner box layer. */
			++topLeftRow;
			++topLeftColumn;
			--bottomRightRow;
			--bottomRightColumn;
		}

		return spiralArray;
	}
};

#endif	// _SPIRAL_MATRIX_H_