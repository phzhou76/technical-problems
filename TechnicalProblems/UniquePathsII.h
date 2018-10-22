#pragma once
#ifndef _UNIQUE_PATHS_II_H_
#define _UNIQUE_PATHS_II_H_

#include "pch.h"

/**
 * A robot is located at the top-left corner of a m x n grid.
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid.
 *
 * Now, consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 * Source: https://leetcode.com/problems/unique-paths-ii/description/
 */
struct Coordinate
{
	int mXCoord;
	int mYCoord;

	Coordinate(int xCoord, int yCoord)
		: mXCoord(xCoord), mYCoord(yCoord) { }
};

class UniquePathsII
{
public:
	int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
	{
		/* Top-down (Iterative) Approach: Create a cache where each tile in the
		 * cache represents the number of ways the top left tile can reach that
		 * current tile.
		 *
		 * The approach optimizes the space complexity of the DP approach that
		 * starts calculations of path lengths from the top left tile. Because
		 * each row in the grid will only take path counts from tiles in the
		 * same row, or tiles in the row above, we don't need to save the path
		 * counts of any of the other rows.
		 *
		 * Thus, use a cache that just caches the path counts of the tiles in the
		 * previous row. Overwrite the contents of the cache to get the path 
		 * counts of the current row, which will then become the previous row on
		 * the next iteration. 
		 *
		 * The number of paths that the top left tile can use to reach the bottom
		 * right tile is found at the rightmost element in the row cache once all
		 * rows have been scanned.
		 *
		 * Time Complexity: O(m * n), where m is the length of the grid, and n is
		 *		the width of the grid.
		 * Space Complexity: O(n), where n is the width of the grid.
		 */
#if 1
		 /* Edge Case: If the grid doesn't exist. */
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
		{
			return 0;
		}

		std::vector<int> rowPathCounts(obstacleGrid[0].size(), 0);
		rowPathCounts[0] = obstacleGrid[0][0] == 1 ? 0 : 1;

		/* Initialize the number of paths from start to each tile in the first
		 * row of the grid. If an obstacle is encountered in the first row, all
		 * other tiles after that obstacle tile are not accessible. */
		for (int col = 1; col < obstacleGrid[0].size(); ++col)
		{
			if (obstacleGrid[0][col] == 0)
			{
				rowPathCounts[col] = rowPathCounts[col - 1];
			}
		}

		/* Start calculating the path lengths for every tile in the second row,
		 * then the third row, and so on until the last row in the grid. */
		for (int row = 1; row < obstacleGrid.size(); ++row)
		{
			/* Edge Case: The first tile in each row only takes path count from
			 * tile from top. */
			rowPathCounts[0] = obstacleGrid[row][0] == 0 ? rowPathCounts[0] : 0;

			/* Take the path lengths from the top tile and the left tile to
			 * calculate the path lengths for the current tile. */
			for (int col = 1; col < obstacleGrid[row].size(); ++col)
			{
				rowPathCounts[col] = obstacleGrid[row][col] == 0 ?
					(rowPathCounts[col] + rowPathCounts[col - 1]) : 0;
			}
		}

		return rowPathCounts[rowPathCounts.size() - 1];

#endif

		/* Top-down Recursive Approach: Create a cache where each tile in the 
		 * cache represents the number of ways to get to the bottom right spot 
		 * from that tile. Each tile's path count will be required multiple times
		 * from many nodes, so they should be cached for faster runtimes.
		 *
		 * Pass the top-left coordinate, the obstacle grid, and the cache to the
		 * recursive method. If the path counts of the tiles to the right and the
		 * bottom haven't been calculated yet, then recursively call on those
		 * tiles first to obtain their values before returning to the current
		 * tile.
		 *
		 * When the recursion backtracks to the top, the top left tile should
		 * contain all of the paths to the bottom right tile.
		 *
		 * Time Complexity: O(m * n), where m is the length of the grid, and n
		 *		is the width of the grid.
		 * Space Complexity: O(m * n), where m is the length of the grid, and n
		 *		is the width of the grid.
		 */
#if 0
		 /* Edge Case: If the grid doesn't exist. */
		if (obstacleGrid.empty() || obstacleGrid[0].empty())
		{
			return 0;
		}

		/* Cache for recursion, since each spot in the grid can be called upon
		 * multiple times by surrounding spots. */
		std::vector<std::vector<int>> pathCounts(obstacleGrid.size(),
			std::vector<int>(obstacleGrid[0].size(), -1));

		uniquePathsWithObstaclesHelper(Coordinate(0, 0), obstacleGrid, pathCounts);

		return pathCounts[0][0];
#endif

		/* Top-down (Iterative) Approach: Create a 2D cache where each tile in
		 * the cache represents the number of ways the top left tile can reach 
		 * that current tile.
		 *
		 * Time Complexity: O(m * n), where m is the length of the grid, and n is
		 *		the width of the grid.
		 * Space Complexity: O(m * n), where m is the length of the grid, and n
		 *		is the width of the grid.
		 */
#if 0
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
#endif
	}

	void uniquePathsWithObstaclesHelper(Coordinate currCoord,
		std::vector<std::vector<int>> &obstacleGrid,
		std::vector<std::vector<int>> &pathCounts)
	{
		/* Edge Case: If this current coordinate is blocked by an obstacle, no
		 * paths can use this coordinate. */
		if (obstacleGrid[currCoord.mYCoord][currCoord.mXCoord] == 1)
		{
			pathCounts[currCoord.mYCoord][currCoord.mXCoord] = 0;
			return;
		}

		/* Base Case: The current coordinate is at the bottom right of the grid.
		 * Set the coordinate in the cache to 1, since there is only one path
		 * from the bottom right to itself. */
		if (currCoord.mXCoord == obstacleGrid[0].size() - 1
			&& currCoord.mYCoord == obstacleGrid.size() - 1)
		{
			pathCounts[currCoord.mYCoord][currCoord.mXCoord] = 1;
			return;
		}

		/* Obtain the number of paths from the tiles to the right and to the
		 * bottom, if possible (must check for bounds). */
		int rightPaths = 0;
		if (currCoord.mXCoord < obstacleGrid[0].size() - 1)
		{
			/* If the right tile's path count is -1, that means it hasn't been
			 * calculated yet. Recursively call on it to calculate its path count
			 * before returning to this tile. */
			if (pathCounts[currCoord.mYCoord][currCoord.mXCoord + 1] == -1)
			{
				uniquePathsWithObstaclesHelper(
					Coordinate(currCoord.mXCoord + 1, currCoord.mYCoord),
					obstacleGrid, pathCounts);
			}

			rightPaths = pathCounts[currCoord.mYCoord][currCoord.mXCoord + 1];
		}

		int bottomPaths = 0;
		if (currCoord.mYCoord < obstacleGrid.size() - 1)
		{
			/* If the bottom tile's path count is -1, that means it hasn't been
			 * calculated yet. Recursively call on it to calculate its path count
			 * before returning to this tile. */
			if (pathCounts[currCoord.mYCoord + 1][currCoord.mXCoord] == -1)
			{
				uniquePathsWithObstaclesHelper(
					Coordinate(currCoord.mXCoord, currCoord.mYCoord + 1),
					obstacleGrid, pathCounts);
			}

			bottomPaths = pathCounts[currCoord.mYCoord + 1][currCoord.mXCoord];
		}

		pathCounts[currCoord.mYCoord][currCoord.mXCoord] = rightPaths +
			bottomPaths;
	}
};

#endif	// _UNIQUE_PATHS_II_H_