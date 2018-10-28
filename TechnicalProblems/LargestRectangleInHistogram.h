#pragma once
#ifndef _LARGEST_RECTANGLE_IN_HISTOGRAM_H_
#define _LARGEST_RECTANGLE_IN_HISTOGRAM_H_

#include "pch.h"

/**
 * Given n non-negative integers representing the histogram's bar height where 
 * the width of each bar is 1, find the area of the larges rectangle in the
 * histogram.
 *
 * Source: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 */
class LargestRectangleInHistogram
{
public:

	/* Solution: For each bar i in the histogram, we want to calculate the area
	 * of the widest rectangle where i is the shortest bar in the rectangle.
	 * 
	 *	1. i, since it is the shortest bar in the rectangle, will be the limiting
	 *		height of that rectangle.
	 *
	 *	2. There can only be one possible rectangle of maximum width where i is
	 *		the shortest bar in the rectangle, as the rectangle will spread out
	 *		until it hits bars shorter than i, or until it hits the edges of the
	 *		histogram.
	 *
	 * Once we have the widest rectangles of each bar i, where i is the shortest
	 * bar in the rectangle, we can just find the rectangle of the greatest area
	 * and return that value.
	 *
	 *
	 * Brute Force Solution:
	 *
	 * for(i in 0 to histogram.size() - 1):
	 *		left = x where x == 0 or histogram[x - 1] < histogram[i]
	 *		right = y where y == histogram.size() - 1 or histogram[y + 1] < histogram[i]
	 *		area = (right - left + 1) * histogram[i]
	 *
	 * The left and right indices in this solution would each take O(n) runtime,
	 * so the overall solution would have a O(n^2) runtime.
	 */
	int largestRectangleArea(std::vector<int> &histogram)
	{
		/* Create an empty stack, which holds the indices of the histogram array.
		 * The bars stored in the stack will always be in increasing order of
		 * their heights in the histogram. I.e. histogram[stack.top()] will have
		 * the greatest value of all elements in the stack. */
		std::stack<int> barIndices;

		int maxArea = 0;	/* Max rectangle area found so far. */

		/* Run through each bar in the histogram. */
		int currIndex = 0;
		while (currIndex < histogram.size())
		{
			/* If this bar's height is taller than the height of the bar on top
			 * of the stack, push it to the stack. We now need to find a bar that
			 * is shorter than this stack before finding a bar that is shorter
			 * than the bar that was previously on top of the stack.
			 *
			 * Edge case: If the stack is empty, that means one of two things:
			 *	1. This is the first bar in the histogram.
			 *	2. This bar is shorter than all previously visited bars. */
			if (barIndices.empty() || histogram[currIndex] > histogram[barIndices.top()])
			{
				barIndices.push(currIndex);
				++currIndex;
			}

			/* If this bar's height is lower than that of the bar on top of the
			 * stack, then we have found the stopping point for the right side
			 * of the rectangle where the top stack bar is the shortest bar in
			 * the rectangle.
			 *
			 * Then, the left side of this rectangle is located where the index
			 * of the previously top node of the stack. It is guaranteed that all
			 * bars between the previous and current top node are taller than the
			 * current top node, as they need to have been popped before the
			 * current top node could have been pushed.
			 *
			 * Edge case: If the stack is empty, then all elements before this node
			 * are taller than this node. Then, the max width of the rectangle
			 * that has the current top of the stack as the shortest rectangle is
			 * equivalent to the right side of the rectangle. */
			else
			{
				/* Store the top index of the stack. */
				int topIndex = barIndices.top();
				barIndices.pop();

				/* Calculate the area of the widest rectangle where the top bar
				 * is the shortest bar in the rectangle. */
				int height = histogram[topIndex];
				int length = barIndices.empty() ? currIndex 
					: (currIndex - barIndices.top() - 1);

				int topIndexArea = height * length;

				if (topIndexArea > maxArea)
				{
					maxArea = topIndexArea;
				}
			}
		}

		/* If there are any remaining bars in the stack, pop them and for each bar,
		 * calculate the area with each bar as the shortest bar in that rectangle. */
		while (!barIndices.empty())
		{
			int topIndex = barIndices.top();
			barIndices.pop();

			/* Calculate the area of the widest rectangle where the top bar
			 * is the shortest bar in the rectangle. */
			int height = histogram[topIndex];
			int length = barIndices.empty() ? currIndex 
				: (currIndex - barIndices.top() - 1);

			int topIndexArea = height * length;

			if (topIndexArea > maxArea)
			{
				maxArea = topIndexArea;
			}
		}

		return maxArea;
	}
};

#endif	// _LARGEST_RECTANGLE_IN_HISTOGRAM_H_