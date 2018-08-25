#include "pch.h"
#include "CheckPermutation.h"

/** Implemented with a hash map to count character counts in each string. */
bool CheckPermutation::checkPermutation(std::string stringA, std::string stringB)
{
	/* Two strings cannot be permutations of each other if different length. */
	if (stringA.length() != stringB.length())
	{
		return false;
	}

	std::unordered_map<char, int> charCounts;

	/* Sweep through one of the strings to count its chars. */
	for (int i = 0; i < stringA.length(); ++i)
	{
		if (charCounts.find(stringA.at(i)) == charCounts.end())
		{
			charCounts.insert(std::pair<char, int>(stringA.at(i), 1));
		}
		else
		{
			charCounts.at(stringA.at(i)) += 1;
		}
	}

	/* Then, check for the chars in the other string. */
	for (int i = 0; i < stringB.length(); ++i)
	{
		/* Can't be a permutation if one string has a char that the other doesn't. */
		if (charCounts.find(stringB.at(i)) == charCounts.end())
		{
			return false;
		}

		charCounts.at(stringB.at(i)) -= 1;

		/* Occurs if one string has more of a certain char than the other string. */
		if (charCounts.at(stringB.at(i)) < 0)
		{
			return false;
		}
	}

	/* If the method successfully exits the loop without returning false, then
	 * a few things can be deduced. First, both strings have the same chars.
	 * Second, neither string has more of any char than the other string. Combining
	 * these two statements means that both strings have the same chars and
	 * have the same count of each char, which makes the strings permutations
	 * of each other.
	 */
	return true;
}

/** Implemented without any data structures, since the C++ sort() method sorts in-place. */
bool CheckPermutation::checkPermutationNoDataStructures(std::string stringA, std::string stringB)
{
	if (stringA.length() != stringB.length())
	{
		return false;
	}

	std::sort(stringA.begin(), stringA.end());
	std::sort(stringB.begin(), stringB.end());

	for (int i = 0; i < stringA.length(); ++i)
	{
		if (stringA.at(i) != stringB.at(i))
		{
			return false;
		}
	}

	return true;
}

/**
 * Performs tests on the CheckPermutation solutions.
 */
void CheckPermutation::testCheckPermutation()
{
	/* Valid string pairs. */
	std::vector<std::pair<std::string, std::string>> validStringPairs{
		{"",""},
		{"aBc", "Bca"},
		{"qwert", "treqw"},
		{ "!@QW#ER$%T", "Q!@WE#RT%$"}
	};

	/* Invalid string pairs. */
	std::vector<std::pair<std::string, std::string>> invalidStringPairs{
		{"","f"},
		{"aBc", "BCa"},
		{"qwert", "QWERT"},
		{ "!@QW#ER$%T", "Q!@WRT%$"}
	};

	int numSuccessful = 0;
	int numTotal = validStringPairs.size() + invalidStringPairs.size();

	std::cout << "Performing tests on CheckPermutation solutions..." << std::endl;

	/* Hash map implementation tests. */
	std::cout << std::endl << "Running tests on hash map implementation..." << std::endl << std::endl;

	for (int i = 0; i < validStringPairs.size(); ++i)
	{
		std::cout << "Test {\"" << validStringPairs.at(i).first << "\", \"" 
			<< validStringPairs.at(i).second << "\"}: ";

		if (checkPermutation(validStringPairs.at(i).first, validStringPairs.at(i).second))
		{
			std::cout << "Success" << std::endl;
			++numSuccessful;
		}
		else
		{
			std::cout << "Failure" << std::endl;
		}
	}

	for (int i = 0; i < invalidStringPairs.size(); ++i)
	{
		std::cout << "Test {\"" << invalidStringPairs.at(i).first << "\", \""
			<< invalidStringPairs.at(i).second << "\"}: ";

		if (!checkPermutation(invalidStringPairs.at(i).first, invalidStringPairs.at(i).second))
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

	/* Sort implementation tests. */
	std::cout << std::endl << "Running tests on sort implementation..." << std::endl << std::endl;

	for (int i = 0; i < validStringPairs.size(); ++i)
	{
		std::cout << "Test {\"" << validStringPairs.at(i).first << "\", \""
			<< validStringPairs.at(i).second << "\"}: ";

		if (checkPermutationNoDataStructures(validStringPairs.at(i).first, validStringPairs.at(i).second))
		{
			std::cout << "Success" << std::endl;
			++numSuccessful;
		}
		else
		{
			std::cout << "Failure" << std::endl;
		}
	}

	for (int i = 0; i < invalidStringPairs.size(); ++i)
	{
		std::cout << "Test {\"" << invalidStringPairs.at(i).first << "\", \""
			<< invalidStringPairs.at(i).second << "\"}: ";

		if (!checkPermutationNoDataStructures(invalidStringPairs.at(i).first, invalidStringPairs.at(i).second))
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
}
