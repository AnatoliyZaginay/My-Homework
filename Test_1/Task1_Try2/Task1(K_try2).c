#include <stdio.h.>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define ARRAY_SIZE 30

void arrayPrint(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i ", array[i]);
	}
}

void arrayRandomInitialization(int array[], int size, int deductedNumber)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = (rand() % 1000) - deductedNumber;
	}
}

int sumOfDigits(int number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += abs(number % 10);
		number /= 10;
	}
	return sum;
}

void elementsSumOfDigits(int numbersArray[], int sumOfDigitsArray[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		sumOfDigitsArray[i] = sumOfDigits(numbersArray[i]);
	}
}

int maxSumOfDigitsInArray(int sumOfDigitsArray[], int size)
{
	int maxSum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (sumOfDigitsArray[i] > maxSum)
		{
			maxSum = sumOfDigitsArray[i];
		}
	}
	return maxSum;
}

void printElementsWithMaxSumOfDigits(int numberArray[], int sumOfDigitsArray[], int size, int maxSum)
{
	for (int i = 0; i < size; ++i)
	{
		if (sumOfDigitsArray[i] == maxSum)
		{
			printf("%i ", numberArray[i]);
		}
	}
}

void main(void)
{
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE];
	int sumOfDigits[ARRAY_SIZE] = { 0 };
	arrayRandomInitialization(array, ARRAY_SIZE, 500);
	elementsSumOfDigits(array, sumOfDigits, ARRAY_SIZE);
	printf("Исходный массив: ");
	arrayPrint(array, ARRAY_SIZE);
	printf("\n\n");
	printf("Элементы массива с наибольшей суммой цифр: ");
	int maxSum = maxSumOfDigitsInArray(sumOfDigits, ARRAY_SIZE);
	printElementsWithMaxSumOfDigits(array, sumOfDigits, ARRAY_SIZE, maxSum);
}