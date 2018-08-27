#include "pch.h"
#include "PalindromePermutation.h"

/**
 * Implementation with a hash map. Since a palindrome is a string that has even
 * counts on all of its chars, or even counts on all of its chars and an odd count
 * for at most one of its chars, a hash map can be used to keep track.
 */
bool PalindromePermutation::checkIsPermutationOfPalindrome(std::string inputString)
{
	if (inputString.length() < 2)
	{
		return true;
	}

	/* Capitalization seems to be ignored. */
	std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);

	/* Number of chars in the string with an odd count - max 1 is allowed. */
	int oddCharCount = 0;
	std::unordered_map<char, int> charCounts;

	for (int i = 0; i < inputString.length(); ++i)
	{
		/* Whitespaces seem to be ignored. */
		if (inputString.at(i) != ' ')
		{
			if (charCounts.find(inputString.at(i)) == charCounts.end())
			{
				charCounts.insert(std::pair<char, int>(inputString.at(i), 1));
				++oddCharCount;
			}
			else
			{
				charCounts.at(inputString.at(i)) += 1;

				if ((charCounts.at(inputString.at(i)) % 2) == 0)
				{
					--oddCharCount;
				}
				else
				{
					++oddCharCount;
				}
			}
		}
	}

	/* A string is a permutation of a palindrome if one of two conditions are true:
	 *	1. All char counts are even - i.e. the odd char count is 0.
	 *	2. Only one char count is odd, the rest are even - i.e. the odd char count
	 *		is 1.
	 */
	return oddCharCount < 2;
}

/**
 * Implementation with bit vectors. We don't actually need to know the counts of
 * each char; we only need to know if each char has an even or odd count, which
 * can be represented with a bool. This can be implemented with a hash map that
 * maps chars to bools, but we can reduce the space complexity by around 8-fold
 * by using a bit vector instead to mark whether a char's count is even or odd.
 *
 * At the end, since at most one char can be odd, check all bit arrays to see that
 * at most one bit has been set to 1.
 */
bool PalindromePermutation::checkIsPermutationOfPalindromeBitVector(std::string inputString,
	int alphabetSize)
{
	if (inputString.length() < 2)
	{
		return true;
	}

	/* Ignore capitalization. */
	std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);

	int numBitVectors = calculateBitVectorSize(alphabetSize);
	std::vector<int> bitVectors(numBitVectors, 0);

	/* Toggle bits on and off to represent odd and even counts, respectively. */
	for (int i = 0; i < inputString.length(); ++i)
	{
		if (inputString.at(i) != ' ')
		{
			toggleBit(bitVectors, (int)inputString.at(i));
		}
	}

	return isValidPalindromePermutation(bitVectors);
}

int PalindromePermutation::calculateBitVectorSize(int numElements)
{
	return (numElements / 32) + ((numElements % 32) == 0 ? 0 : 1);
}

void PalindromePermutation::toggleBit(std::vector<int> &bitVectors, int bitIndex)
{
	int bitVectorIndex = bitIndex / 32;
	int bitShift = bitIndex % 32;
	int mask = 1 << bitShift;

	/* Bit was off, need to turn on. */
	if ((bitVectors[bitVectorIndex] & mask) == 0)
	{
		bitVectors[bitVectorIndex] |= mask;
	}
	/* Bit was on, need to turn off. */
	else
	{
		bitVectors[bitVectorIndex] &= ~mask;
	}
}

bool PalindromePermutation::isValidPalindromePermutation(std::vector<int> &bitVectors)
{
	bool isBitSet = false;

	for (int i = 0; i < bitVectors.size(); ++i)
	{
		if (bitVectors[i] != 0)
		{
			/* Determine if there is at most one bit set in the bit vector. */
			int mask = bitVectors[i] - 1;
			int result = bitVectors[i] & mask;

			/* The bit vector has more than one bit set. */
			if (result != 0)
			{
				return false;
			}
			/* The bit vector has only one bit set. */
			else
			{
				/* Bit has been set previously. */
				if (isBitSet)
				{
					return false;
				}

				isBitSet = true;
			}
		}
	}

	return true;
}

void PalindromePermutation::testPalindromePermutation()
{
	/* Valid strings. */
	std::vector<std::string> validStrings{ "", "a", "bb", "bba", "ddcc", "dfedfe", "qazxsweqazxsw" };

	/* Invalid strings. */
	std::vector<std::string> invalidStrings{ "quack", "bv", "cvd", "ddad", "ssawqrkkka" };

	int numSuccessful = 0;
	int numTotal = validStrings.size() + invalidStrings.size();

	std::cout << "Performing tests on PalindromePermutation solutions..." << std::endl;

	/* Hash map implementation tests. */
	std::cout << std::endl << "Running tests on hash map implementation..." << std::endl << std::endl;

	for (int i = 0; i < validStrings.size(); ++i)
	{
		std::cout << "Test (\"" << validStrings.at(i) << "\"): ";

		if (checkIsPermutationOfPalindrome(validStrings.at(i)))
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

		if (!checkIsPermutationOfPalindrome(invalidStrings.at(i)))
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

		if (checkIsPermutationOfPalindromeBitVector(validStrings.at(i), 256))
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

		if (!checkIsPermutationOfPalindromeBitVector(invalidStrings.at(i), 256))
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
