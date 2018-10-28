#pragma once
#ifndef _DIAGONAL_TRAVERSE_H_
#define _DIAGONAL_TRAVERSE_H_

#include "pch.h"

/**
 * Given a matrix of M * N elements (M rows, N columns), return all elements of 
 * the matrix in diagonal order, as follows:
 *
 * Input:
 * [1, 2, 3]
 * [4, 5, 6]
 * [7, 8, 9]
 *
 * Output: [1, 2, 4, 7, 5, 3, 6, 8, 9]
 *
 * Questions:
 *	1. What should be returned if the matrix is empty, or if it is 
 *		one-dimensional?
 *
 * Source: https://leetcode.com/problems/diagonal-traverse/description/
 */
class DiagonalTraverse
{
public:

	/* There are two possible traversals for diagonals - upwards, or downwards.
	 * Thus, there needs to be a bool to signify whether or not the current
	 * diagonal is upwards or downwards in slope. 
	 *
	 * Possible directions:
	 *	1. Upwards: -1 to row, +1 to column on every iteration.
	 *	2. Downwards: +1 to row, -1 to column on every iteration.
	 *
	 * Then, we need to consider what happens when the diagonals reach their last
	 * element. The last element of the diagonal can be detected if the coordinate
	 * position of the next element is out of bounds of the matrix.
	 *
	 * For upward diagonals:
	 *	1. If there is an element to the right of the last element in the upward
	 *		diagonal, then that is the start of the next diagonal. Use the row
	 *		of the current element, but add one to the column.
	 *	2. Else, there isn't an element to the right of the last element in the 
	 *		upward diagonal. Then, the element below is the start of the next 
	 *		diagonal. Add one to the row, but keep the original value of the column.
	 *
	 * For downward diagonals:
	 *	1. If there is an element below the last element in the downward diagonal,
	 *		then that is the start of the next diagonal. Add one to the row of the
	 *		current element, but keep the original value of the column.
	 *	2. Else, there isn't an element below the last element in the downward
	 *		diagonal. Then, the element to the right is the start of the diagonal.
	 *		Keep the original row of the last element, but add one to the column.
	 *
	 * Invert the upward bool at the end of every diagonal. Eventually, when both
	 * the row and the column go out of bounds, then we know we've gone through
	 * every element. 
	 */
	std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &matrix)
	{

	}
};

#endif	// _DIAGONAL_TRAVERSE_H_