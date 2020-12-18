#include "AlgorithmKMP.h"

#include <string.h>
#include <stdlib.h>

void prefixFunction(char* string, int* prefixArray)
{
	prefixArray[0] = 0;
	int i = 1;
	int j = 0;
	while (i < strlen(string))
	{
		if (string[i] == string[j])
		{
			prefixArray[i] = j + 1;
			++i;
			++j;
			continue;
		}
		if (j == 0)
		{
			prefixArray[i] = 0;
			++i;
		}
		else
		{
			j = prefixArray[j - 1];
		}
	}
}

int searchSubstring(char* string, char* substring)
{
	int* prefixArray = calloc(strlen(substring), sizeof(int));
	prefixFunction(substring, prefixArray);
	int i = 0;
	int j = 0;
	while (i < strlen(string))
	{
		if (string[i] == substring[j])
		{
			++i;
			++j;
			if (j == strlen(substring))
			{
				free(prefixArray);
				return i - j;
			}
			continue;
		}
		if (j == 0)
		{
			++i;
		}
		else
		{
			j = prefixArray[j - 1];
		}
	}
	free(prefixArray);
	return -1;
}