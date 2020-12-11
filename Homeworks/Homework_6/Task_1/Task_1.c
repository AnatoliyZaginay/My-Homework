#include "SortedList.h"
#include "SortedListTests.h"
#include <stdio.h>
#include <locale.h>

void commands(void)
{
	printf("Выберите комманду:\n");
	printf("0 - выйти\n");
	printf("1 – добавить значение в сортированный список\n");
	printf("2 – удалить значение из списка\n");
	printf("3 – распечатать список\n\n");
}

void main(void)
{
	if (!sortedListTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct List* list = createList();
	int commandNumber = -1;
	while (commandNumber != 0)
	{
		commands();
		scanf("%i", &commandNumber);
		int value = 0;
		switch (commandNumber)
		{
		case 0:
			printf("Программа завершена");
			break;
		case 1:
			printf("Введите значение, которое хотите добавить в сортированный список: ");
			scanf("%i", &value);
			add(list, value);
			printf("Значение добавлено\n\n");
			break;
		case 2:
			printf("Введите значение, которое хотите удалить из сортированного списка: ");
			scanf("%i", &value);
			if (delete(list, value))
			{
				printf("Значение удалено\n\n");
			}
			else
			{
				printf("Введённого значение нет в списке\n\n");
			}
			break;
		case 3:
			printf("Значение элементов списка: ");
			printList(list);
			printf("\n\n");
			break;
		default:
			printf("Введите корректный номер комманды\n\n");
			break;
		}
	}
	deleteList(&list);
}