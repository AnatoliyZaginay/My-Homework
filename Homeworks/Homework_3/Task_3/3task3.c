#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define ARRAY_SIZE 100

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

void swapArrayElements(int array[], int firstIndex, int secondIndex)
{
	const int change = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = change;
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

void arrayRandomInitialization(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 100;
	}
}

void quickSort(int array[], int leftBorder, int rightBorder)
{
	int left = leftBorder;
	int right = rightBorder;
	const int pivot = array[(leftBorder + rightBorder) / 2];
	while (left <= right)
	{
		while (array[left] < pivot)
		{
			++left;
		}
		while (array[right] > pivot)
		{
			--right;
		}
		if (left <= right)
		{
			swapArrayElements(array, left, right);
			++left;
			--right;
		}
	}
	if (right > leftBorder)
	{
		quickSort(array, leftBorder, right);
	}
	if (left < rightBorder)
	{
		quickSort(array, left, rightBorder);
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
	quickSort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortSorted()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	quickSort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortSameElements()
{
	int array[10000];
	arrayInitializationWithElement(array, 10000, 5);
	quickSort(array, 0, 9999);
	return isSorted(array, 10000);
}

bool testQuickSortOneElement()
{
	int array[1] = { 0 };
	quickSort(array, 0, 0);
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

void main()
{
	if (!testQuickSortUnsorted() || !testQuickSortSorted() || !testQuickSortSameElements() ||
		!testQuickSortOneElement() || !testFrequentElementTwoFrequentElements() || 
		!testFrequentElementLastElement() || !testFrequentElementFirstElement())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE];
	arrayRandomInitialization(array, ARRAY_SIZE);
	printf("Сгенерированный массив: ");
	arrayPrint(array, ARRAY_SIZE);
	quickSort(array, 0, ARRAY_SIZE - 1);
	printf("\n\nНаиболее часто встречающийся элемент в массиве: %i", frequentElementOfArray(array, ARRAY_SIZE));
}