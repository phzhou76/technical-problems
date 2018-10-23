#pragma once
#ifndef _TOWERS_OF_HANOI_H_
#define _TOWERS_OF_HANOI_H_

#include "pch.h"

/**
 * In the classic problem of the Towers of Hanoi, you have 3 towers and N disks
 * of different sizes which can slide onto any tower. The puzzle starts with
 * disks sorted in ascending order of size from top to bottom (i.e. each disk
 * sits on top of a larger disk). You have the following constraints:
 *
 *	1. Only one disk can be moved at a time.
 *	2. A disk is slid off the top of one tower onto another tower.
 *	3. A disk cannot be placed on top of a smaller disk.
 *
 * Write a program to move the disks from the first tower to the last using
 * stacks.
 *
 * Source: Cracking the Coding Interview, 6th Edition: Problem 8.5
 */
class TowersOfHanoi
{
public:

	/* Recursive Solution: With this type of problem, a Base Case and Build
	 * approach should be used - look at how to solve the smallest case for this
	 * problem, and then figure out how to use smaller cases to build a solution
	 * for larger cases.
	 *
	 * 1 Disk: Move the disk from the start to the destination stack.
	 * 2 Disks: Move the first disk to the temporary stack, move the second disk
	 *		to the destination stack, and then move the first stack to the
	 *		destination stack.
	 *
	 * 2 Disks (Updated): Use the 1 Disk algorithm to move the first disk to a
	 *		temp stack. Then, move the second disk to the destination stack.
	 *		After that, think of the temp stack as the "start" stack, the start
	 *		stack as the "temp" stack, and move the 1 Disk in the temp stack to
	 *		the destination stack.
	 *
	 * 3 Disks: Use the 2 Disks algorithm to move the first two disks to a temp
	 *		stack. Then, move the third disk to the destination stack. After that,
	 *		think of the temp stack as the "start" stack, the start stack as the
	 *		"temp" stack, and move the 2 Disks in the temp stack to the
	 *		destination stack.
	 * 4 Disks: Use the 3 Disks algorithm to move the first three disks to a temp
	 *		stack. Then, move the fourth disk to the destination stack. After
	 *		that, think of the temp stack as the "start" stack, the start stack
	 *		as the "temp" stack, and move the 3 Disks in the temp stack to the
	 *		destination stack.
	 */
	void moveDisks(int n, std::stack<int> start, std::stack<int> temp,
		std::stack<int> destination)
	{
		/* Base Case (One Disk): Move the disk from the "start stack" to the
		 * "destination stack". */
		if (n <= 0)
		{
			/* Move top of start stack to top of destination stack. */
			destination.push(start.top());
			start.pop();
		}

		/* Recursive Case: Move n - 1 disks to the temp stack. */
		moveDisks(n - 1, start, destination, temp);

		/* Only the nth disk is on the start stack. Move the top of the start
		 * stack to the top of the destination stack. */
		destination.push(start.top());
		start.pop();

		/* Then, move the n - 1 disks from the temp stack to the destination
		 * stack. */
		moveDisks(n - 1, temp, start, destination);
	}
};

#endif	// _TOWERS_OF_HANOI_H_