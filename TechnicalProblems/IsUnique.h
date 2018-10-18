#pragma once
#ifndef _IS_UNIQUE_H_
#define _IS_UNIQUE_H_

#include "pch.h"

/**
 * Problem: Implement an algorithm to determine if a string has all unique
 * characters. What if you cannot use additional data structures?
 *
 * Questions:
 *	1. What char set is being used?
 *	2. Can I assume that standard sorting algorithms will not use additional
 *		data structures?
 *	3. Is the algorithm case sensitive?
 */
class IsUnique
{
public:

	/** Implementation with a hash map. Note that a hash table would be better
	 * in this situation, since we don't need to know the counts, we just need
	 * to know that they exist. */
	static bool determineIsUnique(std::string inputString)
	{
		if (inputString.length() < 2)
		{
			return true;
		}

		std::unordered_map<char, bool> seenChar;

		for (int i = 0; i < inputString.length(); ++i)
		{
			if (seenChar.find(inputString.at(i)) != seenChar.end())
			{
				return false;
			}

			seenChar.insert(std::pair<char, bool>(inputString.at(i), true));
		}

		return true;
	}

	/** Implementation with an array. */
	static bool determineIsUnique(std::string inputString, const int alphabetSize)
	{
		if (inputString.length() < 2)
		{
			return true;
		}

		/* If a string is longer than possible number of chars, there are copies. */
		if (inputString.length() > alphabetSize)
		{
			return false;
		}

		std::vector<bool> seenChar;
		for (int i = 0; i < alphabetSize; ++i)
		{
			seenChar.push_back(false);
		}

		for (int i = 0; i < inputString.length(); ++i)
		{
			if (seenChar[(int)inputString.at(i)])
			{
				return false;
			}

			seenChar[(int)inputString.at(i)] = true;
		}

		return true;
	}

	/** Implementation with a bit vector; takes 8 times less space than an array. */
	static bool determineIsUniqueBitVector(std::string inputString, const int alphabetSize)
	{
		if (inputString.length() < 2)
		{
			return true;
		}

		if (inputString.length() > alphabetSize)
		{
			return false;
		}

		std::vector<int> seenCharBitVector;
		int bitVectorSize = determineBitVectorSize(alphabetSize);

		for (int i = 0; i < bitVectorSize; ++i)
		{
			seenCharBitVector.push_back(0);
		}

		for (int i = 0; i < inputString.length(); ++i)
		{
			int charValue = (int)inputString.at(i);
			if (getBit(seenCharBitVector, charValue))
			{
				return false;
			}

			setBit(seenCharBitVector, charValue, true);
		}

		return true;
	}

	/**
	 * Returns the number of bit vectors required to record bit information on
	 * the given number of elements.
	 *
	 * @param numElements The number of elements to record data on.
	 *
	 * @return The required number of bit vectors.
	 */
	static int determineBitVectorSize(const int numElements)
	{
		return (numElements / 32) + ((numElements % 32) > 0 ? 1 : 0);
	}

	/**
	 * Gets the value of a specific bit in the bit vectors.
	 *
	 * @param bitVectors The bit vectors.
	 * @param charValue The int value of the char to check.
	 *
	 * @return True if the bit for the char has been set to 1, false if the
	 *		bit for the char has been set to 0.
	 */
	static bool getBit(std::vector<int> &bitVectors, int charValue)
	{
		int bitVectorIndex = charValue / 32;
		int bitShift = charValue % 32;
		int mask = 1 << bitShift;
		return (bitVectors.at(bitVectorIndex) & mask) != 0;
	}

	/**
	 * Sets the value of a specific bit in the bit vectors.
	 *
	 * @param bitVectors The bit vectors.
	 * @param charValue The int value of the char.
	 * @param setValue True sets the bit to 1, false sets the bit to 0.
	 */
	static void setBit(std::vector<int> &bitVectors, int charValue, bool setValue)
	{
		int bitVectorIndex = charValue / 32;
		int bitShift = charValue % 32;
		int mask = 1 << bitShift;

		if (setValue)
		{
			bitVectors.at(bitVectorIndex) |= mask;
		}
		else
		{
			bitVectors.at(bitVectorIndex) &= ~mask;
		}
	}

	/**
	 * Implementation without any data structures, assuming that standard sorting
	 * algorithms do not use any additional data structures. The C++ sort() method
	 * sorts the string in-place.
	 */
	static bool determineIsUniqueNoDataStructures(std::string inputString)
	{
		if (inputString.length() < 2)
		{
			return true;
		}

		std::sort(inputString.begin(), inputString.end());

		for (int i = 0; i < inputString.length() - 1; ++i)
		{
			if (inputString.at(i) == inputString.at(i + 1))
			{
				return false;
			}
		}

		return true;
	}

	/** Tests solutions to the Is Unique problem. */
	static void testIsUnique()
	{
		/* Valid strings. */
		std::vector<std::string> validStrings{ "", "aBc", "ftjaJe", "aqrovcxmpynj:", "AQOMXNBY!@#$(&", "AaBbCcDdEe" };

		/* Invalid strings. */
		std::vector<std::string> invalidStrings{ "aa", "cbc", "dadgajjji", "DaDjiojoijjqhmlaazaa" };

		int numSuccessful = 0;
		int numTotal = validStrings.size() + invalidStrings.size();

		std::cout << "Performing tests on IsUnique solutions..." << std::endl;

		/* Hash map implementation tests. */
		std::cout << std::endl << "Running tests on hash map implementation..." << std::endl << std::endl;

		for (int i = 0; i < validStrings.size(); ++i)
		{
			std::cout << "Test (\"" << validStrings.at(i) << "\"): ";

			if (determineIsUnique(validStrings.at(i)))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		for (int i = 0; i < invalidStrings.size(); ++i)
		{
			std::cout << "Test (\"" << invalidStrings.at(i) << "\"): ";

			if (!determineIsUnique(invalidStrings.at(i)))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		std::cout << "Number of correct tests: " << numSuccessful << "/" << numTotal << std::endl;
		numSuccessful = 0;

		/* Boolean array implementation tests. */
		std::cout << std::endl << "Running tests on boolean array implementation..." << std::endl << std::endl;

		for (int i = 0; i < validStrings.size(); ++i)
		{
			std::cout << "Test (\"" << validStrings.at(i) << "\"): ";

			if (determineIsUnique(validStrings.at(i), 256))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		for (int i = 0; i < invalidStrings.size(); ++i)
		{
			std::cout << "Test (\"" << invalidStrings.at(i) << "\"): ";

			if (!determineIsUnique(invalidStrings.at(i), 256))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		std::cout << "Number of correct tests: " << numSuccessful << "/" << numTotal << std::endl;
		numSuccessful = 0;

		/* Bit vector implementation tests. */
		std::cout << std::endl << "Running tests on bit vector implementation..." << std::endl << std::endl;

		for (int i = 0; i < validStrings.size(); ++i)
		{
			std::cout << "Test (\"" << validStrings.at(i) << "\"): ";

			if (determineIsUniqueBitVector(validStrings.at(i), 256))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		for (int i = 0; i < invalidStrings.size(); ++i)
		{
			std::cout << "Test (\"" << invalidStrings.at(i) << "\"): ";

			if (!determineIsUniqueBitVector(invalidStrings.at(i), 256))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		std::cout << "Number of correct tests: " << numSuccessful << "/" << numTotal << std::endl;
		numSuccessful = 0;

		/* No data structure implementation tests. */
		std::cout << std::endl << "Running tests on no data structure implementation..." << std::endl << std::endl;

		for (int i = 0; i < validStrings.size(); ++i)
		{
			std::cout << "Test (\"" << validStrings.at(i) << "\"): ";

			if (determineIsUniqueNoDataStructures(validStrings.at(i)))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		for (int i = 0; i < invalidStrings.size(); ++i)
		{
			std::cout << "Test (\"" << invalidStrings.at(i) << "\"): ";

			if (!determineIsUniqueNoDataStructures(invalidStrings.at(i)))
			{
				std::cout << "Success" << std::endl;
				++numSuccessful;
			}
			else
			{
				std::cout << "Failure" << std::endl;
			}
		}

		std::cout << "Number of correct tests: " << numSuccessful << "/" << numTotal
			<< std::endl << std::endl << std::endl;
	}
};

#endif	// _IS_UNIQUE_H_