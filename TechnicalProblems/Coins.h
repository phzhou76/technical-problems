#pragma once
#ifndef _COINS_H_
#define _COINS_H_

#include "pch.h"

/**
 * Given an infinite number of quarters (25 cents), dimes (10 cents), nickels
 * (5 cents), and pennies (1 cent), write code to calculate the number of ways
 * of representing n cents.
 */
class Coins
{
public:
	int calculateCoins(int n)
	{
		/* Create a cache that holds the number of ways coins can be used to sum
		 * up to that coin value. E.g. centsCache[10] represents the number of
		 * ways coins can be used to sum up to 10 cents. */
		std::vector<int> centsCache(n + 1, 0);

		for (int i = 0; i < centsCache.size(); ++i)
		{
			if (i + 1 < centsCache.size())
			{
				++centsCache[i + 1];
			}

			if (i + 5 < centsCache.size())
			{
				++centsCache[i + 5];
			}
			if (i + 10 < centsCache.size())
			{
				++centsCache[i + 10];
			}

			if (i + 25 < centsCache.size())
			{
				++centsCache[i + 25];
			}
		}

		return centsCache.back();

#if 0
		return calculateCoinsHelper(n);
#endif
	}

	int calculateCoinsHelper(int coinsLeft)
	{
		/* Base Case: If coinsLeft is 0, then a way to represent n cents has
		 * been found. */
		if (coinsLeft == 0)
		{
			return 1;
		}

		/* Base Case: If coinsLeft is less than 0, then the value of n has been
		 * exceeded. */
		if (coinsLeft < 0)
		{
			return 0;
		}

		/* Calculate the number of ways to represent n - 25 cents if a quarter
		 * was used. */
		int quarterCount = calculateCoinsHelper(coinsLeft - 25);

		/* Calculate the number of ways to represent n - 10 cents if a dime was
		 * used. */
		int dimeCount = calculateCoinsHelper(coinsLeft - 10);

		/* Calculate the number of ways to represent n - 5 cents if a nickel was
		 * used. */
		int nickelCount = calculateCoinsHelper(coinsLeft - 5);

		/* Calculate the number of ways to represent n - 1 cents if a penny was
		 * used. */
		int pennyCount = calculateCoinsHelper(coinsLeft - 1);

		/* Add these counts up to determine the total number of ways a value of
		 * centsLeft can be created. */
		return quarterCount + dimeCount + nickelCount + pennyCount;
	}
};

#endif	// _COINS_H_