#pragma once
#ifndef _UNIQUE_PATHS_H_
#define _UNIQUE_PATHS_H_

#include "pch.h"

/**
 * Problem: A robot is located at the top-left corner of a m x n grid. The robot
 * can only move either down or right at any point in time. The robot is trying
 * to reach the bottom-right corner of the grid.
 *
 * How many possible unique paths are there?
 */
class UniquePaths
{
public:
	int uniquePaths(int m, int n)
	{
		/* Edge case: If m or n is 0, then there are 0 paths. */
		if (m == 0 || n == 0)
		{
			return 0;
		}

		/* Holds the number of paths that can be used to reach [i, j]. */
		std::vector<std::vector<int>> pathCounts(m, std::vector<int>(n, 0));

		/* Set all spots in the first row and column to 1, since all spots in the
		 * first row and column can only have at most one path to their spot. */
		for (int i = 0; i < pathCounts[0].size(); ++i)
		{
			pathCounts[0][i] = 1;
		}

		for (int i = 1; i < pathCounts.size(); ++i)
		{
			pathCounts[i][0] = 1;
		}

		/* Then, for each spot in the grid, going from top left to bottom right,
		 * take the sums of the paths that go to the grid to the left and the grid
		 * to the top, and add them together. */
		for (int i = 1; i < pathCounts.size(); ++i)
		{
			for (int j = 1; j < pathCounts[i].size(); ++j)
			{
				pathCounts[i][j] = pathCounts[i - 1][j] + pathCounts[i][j - 1];
			}
		}

		return pathCounts[pathCounts.size() - 1][pathCounts[0].size() - 1];
	}
};

#endif	// _UNIQUE_PATHS_H_