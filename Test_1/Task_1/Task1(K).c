#include <stdio.h>
#include <locale.h>

#define ARRAY_SIZE 5

void arrayInitialization(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i элемент: ", i + 1);
		scanf("%i", &array[i]);
	}
}

void arrayPrint(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%i ", array[i]);
	}
}

void swapArrayElements(int array[], int firstIndex, int secondIndex)
{
	const int change = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = change;
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

void arrayReverse(int array[], int leftBorder, int rightBorder)
{
	for (int i = 0; i <= (rightBorder - leftBorder) / 2; ++i)
	{
		const int change = array[leftBorder + i];
		array[leftBorder + i] = array[rightBorder - i];
		array[rightBorder - i] = change;
	}
}

float average(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += array[i];
	}
	return sum / size;
}

void operations()
{
	printf("Операции:\n");
	printf("0 – выйти\n");
	printf("1 – заполнить массив чисел случайными значениями\n");
	printf("2 – отсортировать массив\n");
	printf("3 – развернуть массив\n");
	printf("4 – посчитать среднее арифметическое элементов массива\n\n");
}

void arrayAfterOperation(int array[], int size)
{
	printf("Массив после выполнения операции: ");
	arrayPrint(array, size);
	printf("\n\n");
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int array[ARRAY_SIZE];
	printf("Введите %i элементов массива\n", ARRAY_SIZE);
	arrayInitialization(array, ARRAY_SIZE);
	printf("\n");
	operations();
	int operationNumber = 0;
	printf("Введите номер операции: ");
	scanf("%i", &operationNumber);
	while (operationNumber != 0)
	{
		if (operationNumber == 1)
		{
			arrayRandomInitialization(array, ARRAY_SIZE);
			arrayAfterOperation(array, ARRAY_SIZE);
		}
		if (operationNumber == 2)
		{
			quickSort(array, 0, ARRAY_SIZE - 1);
			arrayAfterOperation(array, ARRAY_SIZE);
		}
		if (operationNumber == 3)
		{
			arrayReverse(array, 0, ARRAY_SIZE - 1);
			arrayAfterOperation(array, ARRAY_SIZE);
		}
		if (operationNumber == 4)
		{
			printf("Среднее арифметическое элементов массива: %f\n\n", average(array, ARRAY_SIZE));
		}
		if (operationNumber > 4 || operationNumber < 0)
		{
			printf("Введите корректный номер операции\n\n");
		}
		operations();
		printf("Введите номер операции: ");
		scanf("%i", &operationNumber);
	}
	printf("Программа завершена");
}