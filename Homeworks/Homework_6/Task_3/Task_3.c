#include "List.h"
#include "MergeSort.h"
#include "MergeSortTests.h"
#include "ListTests.h"
#include "ReadFromFile.h"
#include "ReadFromFileTest.h"
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define FILE_NAME "phoneBook.txt"

void main(void)
{
	if (!listTests() || !mergeSortTests() || !readFromFileTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct List* list = createList();
	if (!readFromFile(list, FILE_NAME))
	{
		printf("Файл не найден");
		deleteList(&list);
		return;
	}
	printf("Исходный список:\n");
	printList(list);
	bool sortType = false;
	printf("\n0 - отсортировать список по номерам телефона,\n");
	printf("1 - отсортировать список по именам\n\n");
	int input = 0;
	scanf("%i", &input);
	if (input > 1 || input < 0)
	{
		printf("Неправильный номер комманды");
		deleteList(&list);
		return;
	}
	sortType = input == 1;
	struct List* sortedList = sort(sortType, list);
	printf("\nОтсортированный список:\n");
	printList(sortedList);
	deleteList(&sortedList);
}