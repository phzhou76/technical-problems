#pragma once
#ifndef _CONTAINER_WITH_MOST_WATER_H_
#define _CONTAINER_WITH_MOST_WATER_H_

#include "pch.h"

/**
 * Problem: Given n non-negative integers a1, a2, ... an, where each represents
 * a point at (i, ai). There are n vertical lines that are drawn such that two
 * endpoints of line i is at (i, ai) and (i, 0). 
 *
 * Find two lines, which together with the x-axis, forms a container that contains
 * the most water. Note that the container cannot be slanted, and n is at least 2.	
 */
class ContainerWithMostWater
{
public:
	int maxArea(std::vector<int>& height) {
		int maxArea = 0;
		
		/* The following solution is a brute force solution, since it generates
		 * all possible containers and determines which container holds the most
		 * water. Thus, this algorithm has a O(n^2) runtime and a O(1) space 
		 * complexity. */
#if 0
		/* Width of containers can go from 1 to the number of lines - 1, as the
		 * lines form the sides of the containers. */
		for (int containerWidth = 1; containerWidth < height.size(); ++containerWidth)
		{
			/* The index of the right side is equal to the index of the left side
			 * plus the container width. Stop iterating when the index of the right
			 * side is at the last line in the array. */
			for (int leftSideIndex = 0; leftSideIndex + containerWidth < height.size();
				++leftSideIndex)
			{
				/* Area of container can be calculated by finding the minimum of 
				 * the heights of the left and right sides and multiplying it by
				 * the width of the container. */
				int containerArea = std::min(height[leftSideIndex], 
					height[leftSideIndex + containerWidth]) * containerWidth;
				if (containerArea > maxArea)
				{
					maxArea = containerArea;
				}
			}
		}
#endif

		/* The solution to this problem can be optimized by using a two pointer
		 * strategy. Consider the area between the leftmost and rightmost lines. 
		 * To maximize the area between the lines, we need to look at higher lines.
		 *
		 * So, if we move the higher of the two lines inwards towards the center,
		 * will that possibly lead to an increase in the area between the two 
		 * lines? No, since the area of the container is being limited by the
		 * shorter of the two lines. Even if the next line inward was higher, the
		 * area of the container couldn't utilize the higher line, since the lower
		 * line is bottlenecking the area. 
		 *
		 * Then, if we move the shorter of the two lines inwards towards the center,
		 * it's possible that we may encounter a higher line, which could be 
		 * utilized to generate a greater container area. */

		int leftIndex = 0;
		int rightIndex = height.size() - 1;

		while (leftIndex < rightIndex)
		{
			int containerArea = std::min(height[leftIndex], height[rightIndex])
				* (rightIndex - leftIndex);
			maxArea = std::max(maxArea, containerArea);

			/* Move the shorter of the two lines to possibly obtain a taller 
			 * line. */
			if (height[leftIndex] < height[rightIndex])
			{
				++leftIndex;
			}
			else
			{
				++rightIndex;
			}
		}

		return maxArea;
	}
};

#endif	// _CONTAINER_WITH_MOST_WATER_H_