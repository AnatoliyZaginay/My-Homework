#include "List.h"
#include "ListTests.h"
#include "ReverseList.h"
#include "TestReverseList.h"
#include "ReadFromFile.h"
#include <stdio.h>
#include <locale.h>

#define FILE_NAME "list.txt"

void main(void)
{
	if (!reverseListTest() || !listTests())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct List* list = createList();
	if (list == NULL)
	{
		printf("Ошибка создания списка");
		return;
	}
	if (!readFromFile(list, "list.txt"))
	{
		deleteList(&list);
		printf("Файл не найден");
		return;
	}
	struct List* reversedList = reverseList(list);
	printf("Исходный список: ");
	printList(list);
	printf("\nПеревёрнутый список: ");
	printList(reversedList);
	deleteList(&list);
	deleteList(&reversedList);
}