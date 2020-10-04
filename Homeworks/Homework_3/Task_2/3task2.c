#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

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

bool binarySearch(int array[], int leftBorder, int rightBorder, int element)
{
	const int middle = (rightBorder + leftBorder) / 2;
	if (array[middle] == element)
	{
		return true;
	}
	if (rightBorder <= leftBorder)
	{
		return false;
	}
	if (element > array[middle])
	{
		return binarySearch(array, middle + 1, rightBorder, element);
	}
	return binarySearch(array, leftBorder, middle - 1, element);
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

bool testBinarySearchArrayIncludesElements()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	return binarySearch(array, 0, 9999, 0) && binarySearch(array, 0, 9999, 4999) &&
		binarySearch(array, 0, 9999, -5000) && binarySearch(array, 0, 9999, 4686) &&
		binarySearch(array, 0, 9999, -4687);
}

bool testBinarySearchArrayNotIncludesElements()
{
	int array[10000];
	arrayInitializationSorted(array, 10000, 5000);
	array[5000] = 1;
	return !(binarySearch(array, 0, 9999, 5000) || binarySearch(array, 0, 9999, -5001) ||
		binarySearch(array, 0, 9999, 0));
}

bool testBinarySearchOneElement()
{
	int array[1] = { 0 };
	return binarySearch(array, 0, 0, 0) && !binarySearch(array, 0, 0, 1);
}

void main()
{
	if (!testQuickSortUnsorted() || !testQuickSortSorted() || !testQuickSortSameElements() ||
		!testQuickSortOneElement() || !testBinarySearchArrayIncludesElements() ||
		!testBinarySearchArrayNotIncludesElements() || !testBinarySearchOneElement())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int n = 0;
	printf("Введите размер массива: ");
	scanf("%i", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	arrayRandomInitialization(array, n);
	printf("\nСгенерированный массив: ");
	arrayPrint(array, n);
	quickSort(array, 0, n - 1);
	int k = 0;
	printf("\n\nВведите количество случайных чисел: ");
	scanf("%i", &k);
	for (int i = 0; i < k; ++i)
	{
		const int randomNumber = rand() % 100;
		printf("Число %i %s в сгенерированном массиве\n", randomNumber, 
			binarySearch(array, 0, n - 1, randomNumber) ? "найдено" : "не найдено");
	}
	free(array);
}