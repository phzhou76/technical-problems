#include "pch.h"
#include "URLify.h"

/**
 * Implementation with no extra data structures, assuming that the entire char
 * array can hold the updated string plus the null char to signify the end of the
 * C string. Note: The input C string must be instantiated in non-read-only memory,
 * i.e. instantiated with char a[] or char *a = malloc().
 */
void URLify::replaceSpaces(char * inputString, int stringLength)
{
	if (inputString == nullptr)
	{
		throw std::invalid_argument("Input string is null.");
	}

	int spaceCount = 0;
	for (int i = 0; i < stringLength; ++i)
	{
		if (inputString[i] == ' ')
		{
			++spaceCount;
		}
	}

	int arrayLength = stringLength + (2 * spaceCount);
	inputString[arrayLength] = '/0';

	char * oldStringPtr = inputString + (stringLength - 1);
	char * newStringPtr = inputString + (arrayLength - 1);

	/* In general, when modifying a data structure, it's better to modify any empty
	 * buffer space first to avoid overwriting data. In this case, the string should
	 * be copied from the back to the start of the string, since an empty buffer
	 * is available at the end of the string.
	 */
	while (oldStringPtr >= inputString && newStringPtr >= inputString)
	{
		if (*oldStringPtr == ' ')
		{
			*newStringPtr-- = '0';
			*newStringPtr-- = '2';
			*newStringPtr-- = '%';
			--oldStringPtr;
		}
		else
		{
			*newStringPtr-- = *oldStringPtr--;
		}
	}
}