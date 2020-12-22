#include "Queue.h"
#include "QueueTests.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void commands(void)
{
	printf("\n0 - выйти\n");
	printf("1 - добавить значение\n");
	printf("2 - вернуть самое приоритетное значение в очереди\n\n");
}

void main(void)
{
	if (!queueTests())
	{
		printf("Tests failed");
		return;
	}
	struct Queue* queue = createQueue();
	if (queue == NULL)
	{
		printf("Ошибка создания очереди");
		return;
	}
	setlocale(LC_ALL, "Rus");
	commands();
	int commandNumber = 0;
	printf("Введите номер команды: ", &commandNumber);
	scanf("%i", &commandNumber);
	while (commandNumber != 0)
	{
		switch (commandNumber)
		{
		case 1:
		{
			int value = 0;
			int priority = 0;
			printf("Введите значение: ");
			scanf("%i", &value);
			printf("Введите приоритет: ");
			scanf("%i", &priority);
			enqueue(queue, value, priority);
			break;
		}
		case 2:
		{
			int value = dequeue(queue);
			printf("Полученное значение: %i\n", value);
		}
		default:
			printf("Введите правильный номер команды\n");
		}
		commands();
		printf("Введите номер команды: ", &commandNumber);
		scanf("%i", &commandNumber);
	}
	printf("Программа завершена");
	deleteQueue(&queue);
}