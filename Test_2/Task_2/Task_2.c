#include <stdio.h>
#include "ReadFromFile.h"
#include "List.h"
#include "ListTests.h"
#include "RemoveCopies.h"
#include <locale.h>

#define FILE_NAME "text.txt"

void main(void)
{
	if (!listTests())
	{
		printf("Tests Failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct List* list = createList();
	if (list == NULL)
	{
		printf("Ошибка создания списка");
		return;
	}
	readFromFile(FILE_NAME, list);
	printf("Исходный список:\n");
	printList(list);
	printf("\nСписок после удаления повторяющихся:\n");
	list = removeCopies(list);
	printList(list);
	deleteList(&list);
}