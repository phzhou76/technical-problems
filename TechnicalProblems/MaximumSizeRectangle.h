#pragma once
#ifndef _MAXIMUM_SIZE_RECTANGLE_H_
#define _MAXIMUM_SIZE_RECTANGLE_H_

#include "pch.h"

/**
 * Problem: Given a 2D binary matrix filled with 0s and 1s, find the largest
 * rectangle containing only 1s, and return its area.
 */
class MaximumSizeRectangle
{
public:

	/* Use a temporary array to hold the height of the column that ends in the
	 * current element. For example, if row = 2 and column = 3, then the array[3]
	 * will be the height of the column that ends in the third row of the matrix.
	 *
	 * If the current element is 1, then add 1 to the previous row's height, since
	 * the column size can be extended by 1. However, if the current element in
	 * the matrix is 0, then set the column size to 0, since no column can end
	 * with the current element.
	 *
	 * On each iteration, after the column heights for each element in the row have
	 * been calculated, find the maximum area of that "histogram" (see the solution
	 * in LargestRectangleHistogram). Record the maximum area of that row if it
	 * is greater than the overall maximum area found. */
	int maximalRectangle(std::vector<std::vector<char>> &matrix)
	{
		/* If the matrix has no rows or no columns, return 0. */
		if (matrix.empty() || matrix[0].empty())
		{
			return 0;
		}

		/* Holds the heights of the columns that end with the current row. */
		std::vector<int> columnHeights(matrix[0].size(), 0);

		/* Initialize the column heights of the first row (it will be either 0
		 * or 1). */
		for (int col = 0; col < matrix[0].size(); ++col)
		{
			columnHeights[col] = matrix[0][col] == '0' ? 0 : 1;
		}

		/* Calculate the maximum size of the rectangle for this row. */
		int maxSizeRectangle = calculateMaxRectangle(columnHeights);

		/* Sweep through the rest of the rows. */
		for (int row = 1; row < matrix.size(); ++row)
		{
			for (int col = 0; col < matrix[row].size(); ++col)
			{
				if (matrix[row][col] == '0')
				{
					columnHeights[col] = 0;
				}
				else
				{
					columnHeights[col] += 1;
				}
			}

			/* Holds the max size rectangle of the current row. */
			int currRowMSR = calculateMaxRectangle(columnHeights);
			if (currRowMSR > maxSizeRectangle)
			{
				maxSizeRectangle = currRowMSR;
			}
		}

		return maxSizeRectangle;
	}

	/* Calculate the max size rectangle in the "histogram", as the array represents
	 * columns placed next to each other. */
	int calculateMaxRectangle(std::vector<int> &columnHeights)
	{
		/* Holds the indices of each column. The topmost index in the stack will
		 * point to the highest bar. */
		std::stack<int> columnIndices;

		/* Max size rectangle found so far. */
		int maxSize = 0;

		/* Used to mark the right side of a rectangle where a specific column is
		 * the shortest column in the rectangle. */
		int rightSideIndex = 0;
		
		while (rightSideIndex < columnHeights.size())
		{
			/* If the current column is taller than the column on top of the stack,
			 * then we will need to find a max width rectangle for this column
			 * first before we find one for the column on top of the stack. The
			 * column on top of the stack will serve as the left side for this
			 * rectangle, as it is shorter than the current column. 
			 *
			 * Edge case: If the stack is empty, then this column is either the
			 * first column, or all other columns to the left of it are taller
			 * than it. */
			if (columnIndices.empty() ||
				columnHeights[rightSideIndex] > columnHeights[columnIndices.top()])
			{
				columnIndices.push(rightSideIndex);
				++rightSideIndex;
			}

			/* If the current column is not taller than the column on top of the
			 * stack, then it will serve as the right side of all rectangles whose:
			 *	1. Shortest bar is in the stack.
			 *	2. Shortest bar is taller than the current column. */
			else
			{
				/* Start to calculate the widest rectangle where the top of the
				 * stack is the shortest bar. */
				int topIndex = columnIndices.top();
				columnIndices.pop();

				/* Obtain the left side by looking at the column below the previously
				 * top column. If the stack is empty, then there are no other
				 * shorter columns to the left of the right side. */
				int leftSideIndex = columnIndices.empty() ? -1 : columnIndices.top();

				int height = columnHeights[topIndex];

				/* Width is 0 to right side if stack was empty after the top was
				 * popped off, since that means all columns to the left of the
				 * right side are taller than the current column. */
				int width = leftSideIndex == -1 ? rightSideIndex
					: (rightSideIndex - leftSideIndex - 1);

				int rectangleArea = height * width;
				if (rectangleArea > maxSize)
				{
					maxSize = rectangleArea;
				}
			}
		}

		/* Lastly, if there are still any elements left over (rightSideIndex
		 * would be equal to columnHeights.size() at this point), we need to
		 * calculate the size of the rectangle with each column as the shortest
		 * column. */
		while (!columnIndices.empty())
		{
			int topIndex = columnIndices.top();
			columnIndices.pop();

			int leftSideIndex = columnIndices.empty() ? -1 : columnIndices.top();

			int height = columnHeights[topIndex];
			int width = leftSideIndex == -1 ? rightSideIndex
				: (rightSideIndex - leftSideIndex - 1);

			int rectangleArea = height * width;
			if (rectangleArea > maxSize)
			{
				maxSize = rectangleArea;
			}
		}

		return maxSize;
	}
};

#endif	// _MAXIMUM_SIZE_RECTANGLE_H_