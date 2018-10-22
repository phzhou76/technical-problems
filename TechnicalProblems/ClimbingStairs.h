#pragma once
#ifndef _CLIMBING_STAIRS_H_
#define _CLIMBING_STAIRS_H_

#include "pch.h"

/**
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Input n will be a positive integer.
 *
 * Source: https://leetcode.com/problems/climbing-stairs/description/
 */
class ClimbingStairs
{
public:
	int climbStairs(int n)
	{
		/* Bottom-up Approach: Just like the bottom-up approach below, a cache
		 * will be created to hold the number of ways to reach the top. However,
		 * there is an optimization that can be made in that only the two most
		 * recent steps (i - 2 and i - 1) need to be saved.
		 *
		 * Set oneStepCache to 1, and then proceed until n. Extract the number
		 * of ways to reach the top from n steps from oneStepCache, since it will
		 * be stored there.
		 *
		 * Time Complexity: O(n), where n is the number of steps.
		 * Space Complexity: O(1).
		 */
#if 1
		int oneStepCache = 1;
		int twoStepCache = 0;

		for (int i = 1; i <= n; ++i)
		{
			int oneStep = (i - 1 >= 0) ? oneStepCache : 0;
			int twoStep = (i - 2 >= 0) ? twoStepCache : 0;

			twoStepCache = oneStep;
			oneStepCache = oneStep + twoStep;
		}

		return oneStepCache;
#endif

		/* Bottom-up Approach: Create a cache where each index holds the number
		 * of ways to reach the top (cache[0] will hold 1 as the base case).
		 * E.g. cache[2] will hold the number of ways to reach the top, given a
		 * staircase of 2 steps.
		 *
		 * Set cache[0] to 1, since it's the base case. Then, calculate cache[1],
		 * cache[2], and so on until cache[n] is calculated.
		 *
		 * Time Complexity: O(n), where n is the number of steps.
		 * Space Complexity: O(n), where n is the number of steps.
		 */
#if 0
		std::vector<int> cache(n + 1, 0);
		cache[0] = 1;

		for (int i = 1; i <= n; ++i)
		{
			/* Because we're calculating from the bottom up, it's guaranteed that
			 * cache[i - 1] and cache[i - 2] exist as long as they are both within
			 * array bounds, since i - 1 and i - 2 must have been calculated
			 * before i. */
			int oneStep = (i - 1 >= 0) ? cache[i - 1] : 0;
			int twoStep = (i - 2 >= 0) ? cache[i - 2] : 0;
			cache[i] = oneStep + twoStep;
		}

		return cache[n];
#endif

		/* Top-down Approach: Create a cache where each index holds the number
		 * of ways to reach the top (cache[0] will hold 1 as the base case).
		 * E.g. cache[2] will hold the number of ways to reach the top, given a
		 * staircase of 2 steps.
		 *
		 * Start at the top, where the input is n. Recursively call the method
		 * until the base case has been reached, but cache any values that have
		 * been calculated so that those values can be instantly accessed late
		 * on.
		 *
		 * Time Complexity: O(n), where n is the number of steps.
		 * Space Complexity: O(n), where n is the number of steps.
		 */
#if 0
		std::vector<int> cache(n + 1, -1);
		climbStairsHelper(n, cache);
		return cache[n];
#endif
	}

	void climbStairsHelper(int n, std::vector<int> &cache)
	{
		/* Base Case: If no steps are left, return 1. */
		if (n == 0)
		{
			cache[n] = 1;
			return;
		}

		/* Obtain the number of paths to the top if one step is taken. If the
		 * value hasn't been cached yet, then make the recursive call for the
		 * number of paths to the top if one step is taken to calculate and cache
		 * that value. */
		int oneStep = 0;
		if (n - 1 >= 0)
		{
			if (cache[n - 1] == -1)
			{
				climbStairsHelper(n - 1, cache);
			}

			/* Cache spot for one step away is guaranteed to be set now. */
			oneStep = cache[n - 1];
		}

		/* Obtain the number of paths to the top if two steps is taken. If the
		 * value hasn't been cached yet, then make the recursive call for the
		 * number of paths to the top if two steps is taken to calculate and cache
		 * that value. */
		int twoStep = 0;
		if (n - 2 >= 0)
		{
			if (cache[n - 2] == -1)
			{
				climbStairsHelper(n - 2, cache);
			}

			/* Cache spot for two steps away is guaranteed to be set now. */
			twoStep = cache[n - 2];
		}

		/* Cache the calculated value. */
		cache[n] = oneStep + twoStep;
	}
};

#endif	// _CLIMBING_STAIRS_H_