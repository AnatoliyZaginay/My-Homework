#include "List.h"

#include <stdlib.h>
#include <stdio.h>

struct ListElement
{
	int value;
	struct ListElement* next;
};

struct List
{
	struct ListElement* head;
	struct ListElement* tail;
};

struct List* createList(void)
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList != NULL)
	{
		newList->tail = NULL;
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
		list->tail = newElement;
		list->head = list->tail;
		return;
	}
	list->tail->next = newElement;
	list->tail = newElement;
}

void deleteList(struct List** list)
{
	while (!isEmpty(*list))
	{
		struct ListElement* deletedElement = (*list)->head;
		if ((*list)->head->next == NULL)
		{
			(*list)->head = NULL;
			(*list)->tail = NULL;
			free(deletedElement);
			continue;
		}
		(*list)->head = (*list)->head->next;
		free(deletedElement);
	}
	free(*list);
	*list = NULL;
}

int getValue(struct List* list, int index)
{
	struct ListElement* currentElement = list->head;
	for (int i = 1; i < index; ++i)
	{
		if (currentElement != NULL)
		{
			currentElement = currentElement->next;
		}
	}
	return currentElement->value;
}

int getLength(struct List* list)
{
	struct ListElement* currentElement = list->head;
	int length = 0;
	while (currentElement != NULL)
	{
		++length;
		currentElement = currentElement->next;
	}
	return length;
}

void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		printf("%i ", currentElement->value);
		currentElement = currentElement->next;
	}
}