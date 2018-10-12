#pragma once
#ifndef _HEIGHT_RECONSTRUCTION_H_
#define _HEIGHT_RECONSTRUCTION_H_

#include "pch.h"

/**
 * Problem: Suppose you have a random list of people standing in a queue. Each
 * person is described by a pair of integers (h, k), where:
 *	h: Height of the person.
 *	k: Number of people in front of this person who have a height greater than
 *		or equal to h.
 *
 * Write an algorithm to reconstruct the queue. Note that the input list of
 * people is not in the correct order.
 */
class HeightReconstruction
{
public:

	/* Look for the tallest people in the queue, and sort them in a subarray, with
	 * the person with 0 taller people in front. */
	std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>> &people)
	{

	}
};

#endif	// _HEIGHT_RECONSTRUCTION_H_