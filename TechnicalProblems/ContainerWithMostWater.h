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

		return maxArea;
	}
};

#endif	// _CONTAINER_WITH_MOST_WATER_H_