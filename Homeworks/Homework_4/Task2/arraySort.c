#include "arraySort.h"

#include <stdio.h>

void swapArrayElements(int array[], int firstIndex, int secondIndex)
{
	const int change = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = change;
}

void sort(int array[], int leftBorder, int rightBorder)
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
		sort(array, leftBorder, right);
	}
	if (left < rightBorder)
	{
		sort(array, left, rightBorder);
	}
}