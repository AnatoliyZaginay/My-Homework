#include "List.h"
#include "ListTests.h"
#include "Sort.h"
#include "SortTest.h"
#include <stdio.h>
#include <locale.h>

void main(void)
{
	if (!listTests() || !sortTest())
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
	int number = 0;
	scanf("%i", &number);
	while (number != 0)
	{
		add(list, number);
		scanf("%i", &number);
	}
	list = sort(list);
	printList(list);
	deleteList(&list);
}