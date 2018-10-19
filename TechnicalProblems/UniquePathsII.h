#pragma once
#ifndef _UNIQUE_PATHS_II_H_
#define _UNIQUE_PATHS_II_H_

#include "pch.h"

/**
 * Problem: A robot is located at the top-left corner of a m x n grid. The robot
 * can only move either down or right at any point in time. The robot is trying
 * to reach the bottom-right corner of the grid.
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 */
class UniquePathsII
{
public:
	int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
	{
		/* Edge Case: If the grid has a length of 0 or a width of 0, then no
		 * paths can exist. Additionally, if the start spot or end spot is
		 * blocked by an obstacle, then no paths to the end spot can exist. */
		if (obstacleGrid.empty() || obstacleGrid[0].empty() ||
			obstacleGrid[0][0] == 1 ||
			obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1)
		{
			return 0;
		}

		/* Holds the number of paths that can be used to reach [i, j]. */
		std::vector<std::vector<int>> pathCounts(obstacleGrid.size(),
			std::vector<int>(obstacleGrid[0].size(), 0));

		/* Initialize the first row and column of the path counts matrix. If an
		 * obstacle exists between the start point to a given point on the first
		 * row or column, then any point after that will be 0. */
		pathCounts[0][0] = 1;

		for (int col = 1; col < pathCounts[0].size(); ++col)
		{
			if (obstacleGrid[0][col] == 1)
			{
				pathCounts[0][col] = 0;
			}
			else
			{
				pathCounts[0][col] = pathCounts[0][col - 1];
			}
		}

		for (int row = 1; row < pathCounts.size(); ++row)
		{
			if (obstacleGrid[row][0] == 1)
			{
				pathCounts[row][0] = 0;
			}
			else
			{
				pathCounts[row][0] = pathCounts[row - 1][0];
			}
		}

		/* Scan from the top left spot to the bottom right spot. Use the number of
		 * paths to the spot to the left and to the spot to the top to calculate the
		 * number of paths to the current spot. */
		for (int i = 1; i < pathCounts.size(); ++i)
		{
			for (int j = 1; j < pathCounts[0].size(); ++j)
			{
				/* If the spot has an obstacle, then no paths can reach it. */
				if (obstacleGrid[i][j] == 1)
				{
					pathCounts[i][j] = 0;
				}
				else
				{
					pathCounts[i][j] = pathCounts[i - 1][j] + pathCounts[i][j - 1];
				}
			}
		}

		return pathCounts[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};

#endif	// _UNIQUE_PATHS_II_H_