#include "binaryArrayOperations.h"

#include "arrayOperations.h"
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

void binaryArrayNegativeNumberHelp(int binaryArray[], const int size)
{
	binaryNumberInversion(binaryArray, size);
	int binaryOne[ARRAY_SIZE] = { 1 };
	int binaryArrayResult[ARRAY_SIZE] = { 0 };
	binarySum(binaryArray, binaryOne, binaryArrayResult, size);
	copyArray(binaryArray, binaryArrayResult, size);
}

int fromBinaryToDecimal(int binaryArray[], const int size)
{
	int decimalNumber = 0;
	bool isNegative = binaryArray[size - 1] == 1;
	if (isNegative)
	{
		binaryArrayNegativeNumberHelp(binaryArray, size);
	}
	int power = 1;
	for (int i = 0; i < size; ++i)
	{
		decimalNumber += binaryArray[i] * power;
		power *= 2;
	}
	if (isNegative)
	{
		decimalNumber = -decimalNumber;
	}
	return decimalNumber;
}

void convertToBinary(int number, int binaryArray[], const int size)
{
	bool isNegative = number < 0;
	if (isNegative)
	{
		number = -number;
	}
	int currentIndex = 0;
	while (number > 0)
	{
		if (number & 1)
		{
			binaryArray[currentIndex] = 1;
		}
		++currentIndex;
		number = number >> 1;
	}
	if (isNegative)
	{
		binaryArrayNegativeNumberHelp(binaryArray, size);
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