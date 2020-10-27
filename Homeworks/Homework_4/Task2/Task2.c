#include "arraySort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define FILE_NAME "array.txt"

int numberOfElementsInFile(const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("File not found\n");
		return 0;
	}
	int arraySize = 0;
	while (!feof(file))
	{
		++arraySize;
		int element = 0;
		fscanf(file, "%i", &element);
	}
	fclose(file);
	return arraySize;
}

void arrayInitializationFromFile(int array[], int size, const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("File not found\n");
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

bool testQuickSortUnsorted(void)
{
	int array[10000];
	arrayInitialization(array, 10000, 5000);
	sort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortSorted(void)
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	sort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortSameElements(void)
{
	int array[10000];
	arrayInitializationWithElement(array, 10000, 5);
	sort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortOneElement(void)
{
	int array[1] = { 0 };
	sort(array, 0, 0);
	return isSorted(array, 1);
}

bool testFrequentElementTwoFrequentElements(void)
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	array[5001] = 0;
	array[5003] = 2;
	return frequentElementOfArray(array, 10000) == 0;
}

bool testFrequentElementLastElement(void)
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	array[9998] = array[9999];
	return frequentElementOfArray(array, 10000) == 4999;
}

bool testFrequentElementFirstElement(void)
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	return frequentElementOfArray(array, 10000) == -5000;
}

bool testArrayInitializationFromFile(void)
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

bool testNumberOfElementsInFile(void)
{
	return numberOfElementsInFile("testArray.txt") == 25;
}

bool testsResult(void)
{
	return testQuickSortUnsorted() && testQuickSortSorted() && testQuickSortSameElements() &&
		testQuickSortOneElement() && testFrequentElementTwoFrequentElements() &&
		testFrequentElementLastElement() && testFrequentElementFirstElement() &&
		testArrayInitializationFromFile() && testNumberOfElementsInFile();
}

void main(void)
{
	if (!testsResult())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	const int arraySize = numberOfElementsInFile(FILE_NAME);
	int* array = (int*)malloc(sizeof(int) * arraySize);
	arrayInitializationFromFile(array, arraySize, FILE_NAME);
	printf("Массив, полученный из файла: ");
	arrayPrint(array, arraySize);
	sort(array, 0, arraySize - 1);
	printf("\n\nНаиболее часто встречающийся элемент в массиве: %i", frequentElementOfArray(array, arraySize));
	free(array);
}