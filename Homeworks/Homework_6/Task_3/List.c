#include "List.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct List* createList(void)
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList != NULL)
	{
		newList->tail = NULL;
	}
	return newList;
}

bool isEmpty(struct List* list)
{
	return list->tail == NULL;
}

void add(struct List* list, char name[], char phoneNumber[])
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	strcpy(newElement->name, name);
	strcpy(newElement->phoneNumber, phoneNumber);
	newElement->next = NULL;
	if (isEmpty(list))
	{
		list->tail = newElement;
		list->head = list->tail;
		return;
	}
	list->head->next = newElement;
	list->head = newElement;
}

void printList(struct List* list)
{
	struct ListElement* currentElement = list->tail;
	while (currentElement != NULL)
	{
		printf("%s - %s\n", currentElement->name, currentElement->phoneNumber);
		currentElement = currentElement->next;
	}
}

void deleteList(struct List** list)
{
	while (!isEmpty(*list))
	{
		struct ListElement* deletedElement = (*list)->tail;
		(*list)->tail = (*list)->tail->next;
		free(deletedElement);
	}
	free(*list);
	*list = NULL;
}

void deleteTail(struct List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	struct List* oldTail = list->tail;
	list->tail = list->tail->next;
	free(oldTail);
}

int listLength(struct List* list)
{
	struct ListElement* currentElement = list->tail;
	int length = 0;
	while (currentElement != NULL)
	{
		++length;
		currentElement = currentElement->next;
	}
	return length;
}