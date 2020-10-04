#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

#define ARRAY_SIZE 100000

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

void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				const int change = array[j];
				array[j] = array[j + 1];
				array[j + 1] = change;
			}
		}
	}
}

void countingSort(int array[], int size)
{
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	const int counterArraySize = max - min + 1;
	int* counterArray = (int*)calloc(counterArraySize, sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		++counterArray[array[i] - min];
	}
	int arrayIndex = 0;
	for (int i = 0; i < counterArraySize; ++i)
	{
		while (counterArray[i] > 0)
		{
			array[arrayIndex] = i + min;
			++arrayIndex;
			--counterArray[i];
		}
	}
	free(counterArray);
}

bool testSortUnsorted()
{
	int firstArray[10000];
	arrayInitialization(firstArray, 10000, 5000);
	bubbleSort(firstArray, 10000);
	int secondArray[10000];
	arrayInitialization(secondArray, 10000, 5000);
	countingSort(secondArray, 10000);
	return isSorted(firstArray, 10000) && isSorted(secondArray, 10000);
}

bool testSortSorted()
{
	int firstArray[] = { 1 };
	bubbleSort(firstArray, 1);
	int secondArray[] = { 1 };
	countingSort(secondArray, 1);
	return isSorted(firstArray, 1) && isSorted(secondArray, 1);
}

bool testSortSorted2()
{
	int firstArray[10000];
	arrayInitializationSorted(firstArray, 10000, 5000);
	bubbleSort(firstArray, 10000);
	int secondArray[10000];
	arrayInitializationSorted(secondArray, 10000, 5000);
	countingSort(secondArray, 10000);
	return isSorted(firstArray, 10000) && isSorted(secondArray, 10000);
}

bool testSortSorted3()
{
	int firstArray[1000];
	arrayInitializationWithElement(firstArray, 1000, -5);
	bubbleSort(firstArray, 1000);
	int secondArray[1000];
	arrayInitializationWithElement(secondArray, 1000, -5);
	countingSort(secondArray, 1000);
	return isSorted(firstArray, 1000) && isSorted(secondArray, 1000);
}

void main()
{
	if (!testSortUnsorted() || !testSortSorted() || !testSortSorted2() || !testSortSorted3())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE];
	arrayInitialization(array, ARRAY_SIZE, 0);
	float timePassed = (float)clock() / CLOCKS_PER_SEC;
	countingSort(array, ARRAY_SIZE);
	const float timeCountingSort = (float)clock() / CLOCKS_PER_SEC - timePassed;
	printf("Время, затраченное на сортировку подсчётом, для массива из %i элементов - %f секунд\n", ARRAY_SIZE, timeCountingSort);
	arrayInitialization(array, ARRAY_SIZE, 0);
	timePassed = (float)clock() / CLOCKS_PER_SEC;
	bubbleSort(array, ARRAY_SIZE);
	const float timeBubbleSort = (float)clock() / CLOCKS_PER_SEC - timePassed;
	printf("Время, затраченное на сортировку пузырьком, для массива из %i элементов - %f секунд", ARRAY_SIZE, timeBubbleSort);
}