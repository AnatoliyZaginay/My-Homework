#include "SortedList.h"

#include <stdlib.h>
#include <stdio.h>

struct List* createList(void)
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList != NULL)
	{
		newList->head = NULL;
	}
	return newList;
}

bool isEmpty(struct List* list)
{
	return list->head == NULL;
}

void add(struct List* list, int value)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	newElement->next = NULL;
	if (isEmpty(list))
	{
		list->head = newElement;
		return;
	}
	if (newElement->value < list->head->value)
	{
		newElement->next = list->head;
		list->head = newElement;
		return;
	}
	struct ListElement* currentElement = list->head;
	while (currentElement->next != NULL && currentElement->next->value < value)
	{
		currentElement = currentElement->next;
	}
	newElement->next = currentElement->next;
	currentElement->next = newElement;
	return;
}

bool delete(struct List* list, int value)
{
	if (isEmpty(list))
	{
		return false;
	}
	if (list->head->value == value)
	{
		struct ListElement* deletedElement = list->head;
		list->head = list->head->next;
		free(deletedElement);
		return true;
	}
	struct ListElement* currentElement = list->head;
	while (currentElement->next != NULL && currentElement->next->value <= value)
	{
		if (currentElement->next->value == value)
		{
			struct ListElement* deletedElement = currentElement->next;
			currentElement->next = currentElement->next->next;
			free(deletedElement);
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}

void deleteList(struct List** list)
{
	while (!isEmpty(*list))
	{
		struct ListElement* deletedElement = (*list)->head;
		(*list)->head = (*list)->head->next;
		free(deletedElement);
	}
	free(*list);
	*list = NULL;
}

void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		printf("%i ", currentElement->value);
		currentElement = currentElement->next;
	}
	return;
}