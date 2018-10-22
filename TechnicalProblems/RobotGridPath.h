#pragma once
#ifndef _ROBOT_GRID_PATH_H_
#define _ROBOT_GRID_PATH_H_

#include "pch.h"

/**
 * Imagine a robot sitting on the upper left corner of a grid with r rows and c
 * columns. The robot can only move in two directions, right and down, but
 * certain cells are "off limits" such that the robot cannot step on them. Design
 * an algorithm to find a path for the robot from the top left to the bottom
 * right.
 *
 * Source: Cracking the Coding Interview, 6th Edition: Problem 8.2
 */
struct Coordinate
{
	int mXCoord;
	int mYCoord;

	Coordinate(int xCoord, int yCoord)
		: mXCoord(xCoord), mYCoord(yCoord) { }
};

class RobotGridPath
{
public:

	/* Top-down Approach: For this problem, we just need to obtain one path from
	 * the top left tile to the bottom right tile, not all of them. Thus, we can
	 * create a recursive method that starts from the bottom right tile, and
	 * attempts to find the top left tile.
	 *
	 * Given a tile in the grid, we will calculate whether or not the tile above
	 * it and to the left of it have a path to the top left tile. If one of the
	 * two tiles has a path to the top left tile, add the current tile to the
	 * path, and immediately mark this tile as true (we only need one path to the
	 * top left tile). If neither of the two tiles has a path to the top left
	 * tile, then mark this tile as false.
	 *
	 * If the top left tile is recursed on, then mark it as true if there is no
	 * obstacle there, and immediately return.
	 *
	 * If the current tile is not accessible, mark the tile as false, and
	 * immediately return.
	 *
	 * To optimize this recursion, we will use a 2D cache to store the results of
	 * pathfinding so that the same tiles aren't recalculated to find out whether
	 * or not they have paths to the top left tile.
	 *
	 * Time Complexity: O(m * n), where m is the length of the grid, and n is
	 *		the width of the grid.
	 * Space Complexity: O(m * n), where m is the length of the grid, and n is
	 *		the width of the grid.
	 */
	std::vector<Coordinate> getPath(std::vector<std::vector<bool>> gridOffLimits)
	{
		/* Edge Case: Return an empty path if the grid doesn't exist. */
		if (gridOffLimits.empty() || gridOffLimits[0].empty())
		{
			return std::vector<Coordinate>();
		}

		/* Path from the top left tile to the bottom right tile. */
		std::vector<Coordinate> path;

		/* Cache for the accessibility of each tile to the top left tile. 
		 *	0: Path from this tile to top left tile doesn't exist.
		 *	1: Path from this tile to top left tile does exist.
		 *	-1: Has not been calculated yet. */
		std::vector<std::vector<int>> accessibilityCache(gridOffLimits.size(),
			std::vector<int>(gridOffLimits[0].size(), -1));

		/* If we recurse from the bottom right corner first, and try to find a
		 * path to the top left corner, then we will add the top left tile first,
		 * and the bottom right tile last. */
		getPathHelper(gridOffLimits, accessibilityCache,
			Coordinate(gridOffLimits[0].size() - 1, gridOffLimits.size() - 1),
			path);

		return path;
	}

	void getPathHelper(std::vector<std::vector<bool>> &gridOffLimits,
		std::vector<std::vector<int>> &accessibilityCache,
		Coordinate currCoord, std::vector<Coordinate> &path)
	{
		/* Edge Case: If the current tile is marked as inaccessible, mark as
		 * false and return immediately. */
		if (gridOffLimits[currCoord.mYCoord][currCoord.mXCoord])
		{
			accessibilityCache[currCoord.mYCoord][currCoord.mXCoord] = 0;
			return;
		}

		/* Edge Case: If the current tile is the top left tile, mark the
		 * accessibility of the top left tile. */
		if (currCoord.mXCoord == 0 && currCoord.mYCoord == 0)
		{
			if (!gridOffLimits[currCoord.mYCoord][currCoord.mXCoord])
			{
				accessibilityCache[currCoord.mYCoord][currCoord.mXCoord] = 1;
				path.push_back(currCoord);
			}
			else
			{
				accessibilityCache[currCoord.mYCoord][currCoord.mXCoord] = 0;
			}

			return;
		}

		/* Only add this tile to the path if either the tile to the top or the
		 * tile to the left have a path to the top left tile (need to check for
		 * bounds). 
		 *
		 * Additionally, we only need to recurse if the tiles haven't been
		 * calculated before. */
		if (currCoord.mXCoord - 1 >= 0)
		{
			if (accessibilityCache[currCoord.mYCoord][currCoord.mXCoord - 1] == -1)
			{
				getPathHelper(gridOffLimits, accessibilityCache,
					Coordinate(currCoord.mXCoord - 1, currCoord.mYCoord), path);
			}

			if (accessibilityCache[currCoord.mYCoord][currCoord.mXCoord - 1] == 1)
			{
				path.push_back(currCoord);
				accessibilityCache[currCoord.mYCoord][currCoord.mXCoord] = 1;
				return;
			}
		}

		if (currCoord.mYCoord - 1 >= 0)
		{
			if (accessibilityCache[currCoord.mYCoord - 1][currCoord.mXCoord] == -1)
			{
				getPathHelper(gridOffLimits, accessibilityCache,
					Coordinate(currCoord.mXCoord, currCoord.mYCoord - 1), path);
			}

			if (accessibilityCache[currCoord.mYCoord - 1][currCoord.mXCoord] == 1)
			{
				path.push_back(currCoord);
				accessibilityCache[currCoord.mYCoord][currCoord.mXCoord] = 1;
				return;
			}
		}

		/* If neither of the top and left tiles has a path to the top left tile,
		 * then mark this tile as not having a path to the top left tile. */
		accessibilityCache[currCoord.mYCoord][currCoord.mXCoord] = 0;
	}
};

#endif	// _ROBOT_GRID_PATH_H_
