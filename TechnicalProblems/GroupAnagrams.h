#pragma once
#ifndef _GROUP_ANAGRAMS_H_
#define _GROUP_ANAGRAMS_H_

#include "pch.h"

/**
 * Given an array of strings, group anagrams together.
 *
 * Note:
 *	1. All inputs will be in lowercase.
 *	2. The order of your output does not matter.
 *
 * Source: https://leetcode.com/problems/group-anagrams/
 */
class GroupAnagrams
{
public:

	/* Hashing Solution: If we need to find groups of strings that are anagrams
	 * and place them next to each other, then we can use a hash map that maps
	 * strings with identical character counts to their original string indices.
	 *
	 * Use a sorting algorithm to rearrange each string in the input list of
	 * strings so that anagrams will produce the same hash values.
	 *
	 * However, a linear approach could also be used to create identical hashes.
	 * This would involve counting each character in the string, and then
	 * putting the counts of each character in a string. For example, if the
	 * input string was ababcdcd, then the output string would look like
	 * a2b2c2d2.
	 */
	std::vector<std::vector<std::string>> groupAnagrams(
		std::vector<std::string> &strs)
	{
		/* Maps sorted strings to the indices where the unsorted strings came
		 * from. We'll need to create a copy of the input so that the original
		 * input isn't corrupted from sorting. */
		std::unordered_map<std::string, std::vector<int>> stringIndices;
		std::vector<std::string> strsCopy = std::vector<std::string>(strs);

		/* Since anagrams have the same character counts, we can sort them so
		 * that anagrams will hash to the same value. */
		for (int i = 0; i < strsCopy.size(); ++i)
		{
			std::sort(strsCopy[i].begin(), strsCopy[i].end());

			if (stringIndices.find(strsCopy[i]) == stringIndices.end())
			{
				stringIndices[strsCopy[i]] = std::vector<int>(1, i);
			}
			else
			{
				stringIndices[strsCopy[i]].push_back(i);
			}
		}

		/* Extract the values from the uncorrupted input list and place them
		 * into the same groups. */
		std::vector<std::vector<std::string>> anagramGroups;

		for (auto it : stringIndices)
		{
			anagramGroups.push_back(std::vector<std::string>());

			for (auto stringIndex : it.second)
			{
				anagramGroups.back().push_back(strs[stringIndex]);
			}
		}

		return anagramGroups;
	}
};

#endif	// _GROUP_ANAGRAMS_H_