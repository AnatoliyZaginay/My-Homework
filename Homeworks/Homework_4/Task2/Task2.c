#include "arraySort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define ARRAY_SIZE 25
#define FILE_NAME "array.txt"

void arrayInitializationFromFile(int array[], int size, const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("File not found");
		return;
	}
	for (int i = 0; i < size; ++i)
	{
		fscanf(file, "%i", &array[i]);
	}
	fclose(file);
}

bool isSorted(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (array[i - 1] > array[i])
		{
			return false;
		}
	}
	return true;
}

void arrayInitialization(int array[], int size, int deductedElement)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = size - i - deductedElement;
	}
}

void arrayInitializationSorted(int array[], int size, int deductedElement)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = i - deductedElement;
	}
}

void arrayInitializationWithElement(int array[], int size, int element)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = element;
	}
}

void arrayPrint(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i ", array[i]);
	}
}

int frequentElementOfArray(int array[], int size)
{
	int frequentElement = array[0];
	int numberOfCurrentElement = 1;
	int numberOfFrequentElement = 1;
	for (int i = 1; i < size; ++i)
	{
		if (array[i] == array[i - 1])
		{
			++numberOfCurrentElement;
			if (numberOfCurrentElement > numberOfFrequentElement)
			{
				frequentElement = array[i];
				numberOfFrequentElement = numberOfCurrentElement;
			}
		}
		else
		{
			numberOfCurrentElement = 1;
		}
	}
	return frequentElement;
}

bool testQuickSortUnsorted()
{
	int array[10000];
	arrayInitialization(array, 10000, 5000);
	sort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortSorted()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	sort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortSameElements()
{
	int array[10000];
	arrayInitializationWithElement(array, 10000, 5);
	sort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortOneElement()
{
	int array[1] = { 0 };
	sort(array, 0, 0);
	return isSorted(array, 1);
}

bool testFrequentElementTwoFrequentElements()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	array[5001] = 0;
	array[5003] = 2;
	return frequentElementOfArray(array, 10000) == 0;
}

bool testFrequentElementLastElement()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	array[9998] = array[9999];
	return frequentElementOfArray(array, 10000) == 4999;
}

bool testFrequentElementFirstElement()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	return frequentElementOfArray(array, 10000) == -5000;
}

bool testArrayInitializationFromFile()
{
	int array[25] = { 0 };
	arrayInitializationFromFile(array, 25, "testArray.txt");
	for (int i = 0; i < 25; ++i)
	{
		if (array[i] != i + 1)
		{
			return false;
		}
	}
	return true;
}

bool testsResult()
{
	return testQuickSortUnsorted() && testQuickSortSorted() && testQuickSortSameElements() &&
		testQuickSortOneElement() && testFrequentElementTwoFrequentElements() &&
		testFrequentElementLastElement() && testFrequentElementFirstElement() &&
		testArrayInitializationFromFile();
}

void main()
{
	if (!testsResult())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE] = { 0 };
	arrayInitializationFromFile(array, ARRAY_SIZE, FILE_NAME);
	printf("Массив, полученный из файла: ");
	arrayPrint(array, ARRAY_SIZE);
	sort(array, 0, ARRAY_SIZE - 1);
	printf("\n\nНаиболее часто встречающийся элемент в массиве: %i", frequentElementOfArray(array, ARRAY_SIZE));
}