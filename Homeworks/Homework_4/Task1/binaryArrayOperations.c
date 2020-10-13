#include "binaryArrayOperations.h"

#include <stdio.h>
#include <stdbool.h>

void binaryNumberInversion(int binaryArray[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (binaryArray[i] == 1)
		{
			binaryArray[i] = 0;
		}
		else
		{
			binaryArray[i] = 1;
		}
	}
}

void binarySum(int firstBinaryArray[], int secondBinaryArray[], int resultBinaryArray[], const int size)
{
	int addToNextDigit = 0;
	for (int i = 0; i < size; ++i)
	{
		resultBinaryArray[i] = (firstBinaryArray[i] + secondBinaryArray[i] + addToNextDigit) % 2;
		addToNextDigit = (firstBinaryArray[i] + secondBinaryArray[i] + addToNextDigit) / 2;
	}
}

int fromBinaryToDecimal(int binaryArray[], const int size)
{
	int decimalNumber = 0;
	bool isNegative = binaryArray[size - 1] == 1;
	if (isNegative)
	{
		binaryNumberInversion(binaryArray, size);
	}
	int power = 1;
	for (int i = 0; i < size; ++i)
	{
		decimalNumber += binaryArray[i] * power;
		power *= 2;
	}
	if (isNegative)
	{
		decimalNumber = -decimalNumber - 1;
	}
	return decimalNumber;
}

void convertToBinary(int number, int binaryArray[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		binaryArray[i] = number & 1;
		number = number >> 1;
	}
}

void printBinaryArray(int binaryArray[], const int size)
{
	bool insignificantZeros = false;
	for (int i = size - 1; i > 0; --i)
	{
		if (!insignificantZeros && binaryArray[i] != 0)
		{
			insignificantZeros = true;
		}
		if (insignificantZeros)
		{
			printf("%i", binaryArray[i]);
		}
	}
	printf("%i", binaryArray[0]);
}