#include "arrayOperations.h"

#include <stdio.h>
#include <stdbool.h>

bool compareArrays(int firstArray[], int secondArray[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (firstArray[i] != secondArray[i])
		{
			return false;
		}
	}
	return true;
}