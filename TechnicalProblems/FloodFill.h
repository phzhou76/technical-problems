#pragma once
#ifndef _FLOOD_FILL_H_
#define _FLOOD_FILL_H_

#include "pch.h"

/**
 * An image is represented by a 2D array of integers, with each integer
 * representing the pixel value of the image (from 0 to 65535).
 *
 * Given a coordinate (startRow, startCol), representing the starting pixel row
 * and column of the flood fill, and a pixel value newColor, "flood fill" the
 * image.
 *
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connecting 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connecting 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.
 *
 * Replace the color of all of the aforementioned pixels with newColor.
 *
 * At the end, return the modified image.
 *
 * Source: https://leetcode.com/problems/flood-fill/description/
 */
class FloodFill
{
public:

	/* DFS (Recursive) Solution: First, extract the color of the starting pixel,
	 * since that color will be used to determine if a pixel needs to be
	 * recolored or not.
	 *
	 * Start at the start pixel, and continually recurse. If the current pixel's
	 * color matches the start color, then:
	 *	1. Color the pixel to the new color.
	 *	2. Recurse onto the top, left, right, and bottom pixels, as long as they
	 *		are within the image's bounds.
	 *
	 * Warning: Because this uses a DFS approach, there needs to be a way to
	 * determine if a pixel was already visited or not. Usually, the color not
	 * being the same as the start color is enough. However, if the start color
	 * is the same as the new color, then an endless loop could occur in which
	 * a pixel gets colored to the new color, and gets continually recolored by
	 * future calls that can't determine if the pixel was already colored.
	 *
	 * This solution can also be implemented with a BFS approach. Both approaches
	 * need a way for the algorithm to determine if a pixel has already been
	 * visited and colored or not.
	 */
	std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image,
		int startRow, int startCol, int newColor)
	{
		/* Edge Case: If the image isn't valid. */
		if (image.empty() || image[0].empty())
		{
			return image;
		}

		/* Extract the starting color. */
		int startColor = image[startRow][startCol];

		/* Edge Case: The new color is the same as the start color. Return the
		 * original image.
		 *
		 * The DFS implementation has an issue where if the start color is the
		 * same as the new color to change to, an endless cycle could occur,
		 * since the new color cannot be used to determine if a pixel that was
		 * originally the start color was already visited or not. */
		if (startColor == newColor)
		{
			return image;
		}

		floodFillHelper(image, startColor, newColor, startRow, startCol);

		return image;
	}

	void floodFillHelper(std::vector<std::vector<int>> &image, int startColor,
		int newColor, int currRow, int currCol)
	{
		/* Only color the pixel if it matches the starting color. */
		if (image[currRow][currCol] == startColor)
		{

			/* Color this pixel. */
			image[currRow][currCol] = newColor;

			/* Examine the four adjacent pixels, if they're valid pixel coordinates. */

			/* Pixel to the left. */
			if (currCol - 1 >= 0)
			{
				floodFillHelper(image, startColor, newColor, currRow, currCol - 1);
			}

			/* Pixel to the right. */
			if (currCol + 1 < image[0].size())
			{
				floodFillHelper(image, startColor, newColor, currRow, currCol + 1);
			}

			/* Pixel to the top. */
			if (currRow - 1 >= 0)
			{
				floodFillHelper(image, startColor, newColor, currRow - 1, currCol);
			}

			/* Pixel to the bottom. */
			if (currRow + 1 < image.size())
			{
				floodFillHelper(image, startColor, newColor, currRow + 1, currCol);
			}
		}
	}
};

#endif	// _FLOOD_FILL_H_