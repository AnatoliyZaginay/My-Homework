#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define ARRAY_SIZE 100

void arrayPrint(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i ", array[i]);
	}
}

bool isSorted(int array[], int size, int firstElement)
{
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] >= firstElement)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i < size; ++i)
	{
		if (array[i] < firstElement)
		{
			return false;
		}
	}
	return true;
}

void arrayRandomInitialization(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 100;
	}
}

void arrayInitialization(int array[], int size, int deductedElement, int firstElement)
{
	array[0] = firstElement;
	for (int i = 1; i < size; ++i)
	{
		array[i] = size - i - deductedElement;
	}
}

void arrayInitializationWithElement(int array[], int size, int element)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = element;
	}
}

void swapArrayElements(int array[], int firstIndex, int secondIndex)
{
	const int change = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = change;
}

void arraySort(int array[], int size)
{
	const int firstElement = array[0];
	int largerNumbersCount = 0;
	int lowerNumberCount = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] >= firstElement)
		{
			++largerNumbersCount;
		}
		else
		{
			++lowerNumberCount;
		}
	}
	int index = 0;
	if (largerNumbersCount >= lowerNumberCount)
	{
		for (int i = lowerNumberCount; i < size; ++i)
		{
			if (array[i] < firstElement)
			{
				while (array[index] < firstElement)
				{
					++index;
				}
				swapArrayElements(array, i, index);
			}
		}
		return;
	}
	index = lowerNumberCount;
	for (int i = 0; i < lowerNumberCount; ++i)
	{
		if (array[i] >= firstElement)
		{
			while (array[index] >= firstElement)
			{
				++index;
			}
			swapArrayElements(array, i, index);
		}
	}
}

bool testSortUnsorted()
{
	int array[10000];
	arrayInitialization(array, 10000, 5000, 3000);
	const int firstElement = array[0];
	arraySort(array, 10000);
	return isSorted(array, 10000, firstElement);
}

bool testSortNothingToChange()
{
	int array[10000];
	arrayInitialization(array, 10000, 5000, -10000);
	const int firstElement = array[0];
	arraySort(array, 10000);
	return isSorted(array, 10000, firstElement);
}

bool testSortChangeFirstElementToLast()
{
	int array[10000];
	arrayInitialization(array, 10000, 5000, 10000);
	const int firstElement = array[0];
	arraySort(array, 10000);
	return isSorted(array, 10000, firstElement);
}

bool testSortSameElements()
{
	int array[10000];
	arrayInitializationWithElement(array, 10000, 100);
	const int firstElement = array[0];
	arraySort(array, 10000);
	return isSorted(array, 10000, firstElement);
}

bool testSortOneElement()
{
	int array[] = { 0 };
	const int firstElement = array[0];
	arraySort(array, 1);
	return isSorted(array, 1, firstElement);
}

void main()
{
	if (!testSortUnsorted() || !testSortNothingToChange() || !testSortChangeFirstElementToLast() || 
		!testSortSameElements() || !testSortOneElement())
	{
		printf("Tests failed\n");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE];
	arrayRandomInitialization(array, ARRAY_SIZE);
	printf("Исходный массив:\n");
	arrayPrint(array, ARRAY_SIZE);
	arraySort(array, ARRAY_SIZE);
	printf("\n\nМассив после преобразования:");
	arrayPrint(array, ARRAY_SIZE);
}