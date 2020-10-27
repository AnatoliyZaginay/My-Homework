#include <stdio.h>
#include <locale.h>

#define ARRAY_SIZE 10

void arrayInitialization(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i элемент: ", i + 1);
		scanf("%i", &array[i]);
	}
}

void swapArrayElements(int array[], int firstIndex, int secondIndex)
{
	const int change = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = change;
}

void arrayPrint(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i ", array[i]);
	}
}

void selectionSort(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIndex = i;
		for (int j = i; j < size; ++j)
		{
			if (array[j] <= array[minIndex])
			{
				minIndex = j;
			}
		}
		swapArrayElements(array, i, minIndex);
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE];
	printf("Введите массив из %i элементов\n", ARRAY_SIZE);
	arrayInitialization(array, ARRAY_SIZE);
	printf("\n\nМассив после инициализации: ");
	arrayPrint(array, ARRAY_SIZE);
	printf("\n\nМассив после сортировки выбором: ");
	selectionSort(array, ARRAY_SIZE);
	arrayPrint(array, ARRAY_SIZE);
}