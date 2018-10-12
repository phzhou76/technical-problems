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
	int maximalRectangle(std::vector<std::vector<char>> &matrix)
	{
		/* If the matrix has no rows or no columns, return 0. */
		if (matrix.empty() || matrix[0].empty())
		{
			return 0;
		}

		/* Holds the maximum width and height of all rectangles that have the
		 * bottom right corner at the given coordinate. */
		std::vector<std::vector<std::pair<int, int>>> maxDimensions(matrix.size(),
			std::vector<std::pair<int, int>>(matrix[0].size(), std::pair<int, int>(0, 0)));

		/* Holds the maximum area rectangle found so far. */
		int maxArea = 0;

		/* Initialize the top left element first. */
		if (matrix[0][0] == '1')
		{
			maxDimensions[0][0].first = maxDimensions[0][0].second = 1;
			maxArea = 1;
		}

		/* Note that if the current element is 0, then no rectangle can end with
		 * the current element. In this case, set the maximum width and height
		 * of the element to 0. */

		/* Initialize the first row. */
		for (int i = 1; i < matrix[0].size(); ++i)
		{
			if (matrix[0][i] == '1')
			{
				maxDimensions[0][i].first = maxDimensions[0][i - 1].first + 1;
				maxDimensions[0][i].second = 1;

				int currentArea = maxDimensions[0][i].first * maxDimensions[0][i].second;
				if (currentArea > maxArea)
				{
					maxArea = currentArea;
				}
			}
		}

		/* Initialize the first column. */
		for (int i = 1; i < matrix.size(); ++i)
		{
			if (matrix[i][0] == '1')
			{
				maxDimensions[i][0].first = 1;
				maxDimensions[i][0].second = maxDimensions[i - 1][0].second + 1;

				int currentArea = maxDimensions[i][0].first * maxDimensions[i][0].second;
				if (currentArea > maxArea)
				{
					maxArea = currentArea;
				}
			}
		}

		/* Scan the rest of the matrix. If the current element contains a 1, then
		 * it's possible to have a rectangle have the current element as its
		 * bottom right coordinate. 
		 *
		 * To calculate the maximum height and width of all rectangles that have
		 * this element as the bottom right:
		 *	1. Take the max height saved in the top element, and add 1.
		 *	2. Take the max width saved in the left element, and add 1. */
		for (int row = 1; row < matrix.size(); ++row)
		{
			for (int col = 1; col < matrix[row].size(); ++col)
			{
				if (matrix[row][col] == '1')
				{
					/* Calculate max width. */
					maxDimensions[row][col].first = maxDimensions[row][col - 1].first + 1;

					/* Calculate max height. */
					maxDimensions[row][col].second = maxDimensions[row - 1][col].second + 1;

					int currentArea = maxDimensions[row][col].first *
						maxDimensions[row][col].second;
					if (currentArea > maxArea)
					{
						maxArea = currentArea;
					}
				}
			}
		}

		return maxArea;
	}
};

#endif	// _MAXIMUM_SIZE_RECTANGLE_H_