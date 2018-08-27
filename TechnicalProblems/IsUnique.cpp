#include "pch.h"
#include "IsUnique.h"

/** Implementation with a hash map. */
bool IsUnique::determineIsUnique(std::string inputString)
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
bool IsUnique::determineIsUnique(std::string inputString, const int alphabetSize)
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

/**
 * Implementation with a bit vector. Bit vectors can be used in any situation
 * where an array of bools is used.
 */
bool IsUnique::determineIsUniqueBitVector(std::string inputString, int alphabetSize)
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
int IsUnique::determineBitVectorSize(const int numElements)
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
bool IsUnique::getBit(std::vector<int> &bitVectors, int charValue)
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
void IsUnique::setBit(std::vector<int> &bitVectors, int charValue, bool setValue)
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
bool IsUnique::determineIsUniqueNoDataStructures(std::string inputString)
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

/**
 * Performs tests on the IsUnique solutions.
 */
void IsUnique::testIsUnique()
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