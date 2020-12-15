#include "List.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListElement
{
	int number;
	struct ListElement* next;
};

struct List
{
	struct ListElement* head;
	struct ListElement* tail;
	int length;
};

struct List* createList(void)
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList != NULL)
	{
		newList->head = NULL;
		newList->length = 0;
	}
	return newList;
}

bool isEmpty(struct List* list)
{
	return list->head == NULL;
}

void add(struct List* list, int number)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	++(list->length);
	newElement->number = number;
	newElement->next = NULL;
	if (isEmpty(list))
	{
		list->head = newElement;
		list->tail = list->head;
		return;
	}
	list->tail->next = newElement;
	list->tail = newElement;
}

int getHeadValue(struct List* list)
{
	return list->head->number;
}

void deleteHead(struct List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	struct ListElement* oldHead = list->head;
	list->head = list->head->next;
	--(list->length);
	free(oldHead);
}

void deleteList(struct List** list)
{
	while (!isEmpty(*list))
	{
		deleteHead(*list);
	}
	free(*list);
	*list = NULL;
}

int listLength(struct List* list)
{
	return list->length;
}

bool isOnlyOneElementLeft(struct List* list)
{
	return list->head == list->tail;
}

void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	int currentNumber = list->head->number;
	int count = 0;
	while (currentElement != NULL)
	{
		if (currentElement->number == currentNumber)
		{
			++count;
		}
		else
		{
			printf("%i - %i раз(а)\n", currentNumber, count);
			currentNumber = currentElement->number;
			count = 1;
		}
		currentElement = currentElement->next;
	}
	printf("%i - %i раз(а)\n", currentNumber, count);
}