#include "CyclicList.h"

#include <stdlib.h>

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
		newList->head = NULL;
		newList->tail = NULL;
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
	newElement->next = list->tail;
	if (isEmpty(list))
	{
		list->head = newElement;
		list->tail = list->head;
	}
	list->head->next = newElement;
	list->head = newElement;
}

void deleteElementByNumber(struct List* list, const int number)
{
	struct ListElement* currentElement = list->head;
	for (int i = 1; i < number; ++i)
	{
		currentElement = currentElement->next;
	}
	struct ListElement* deletedElement = currentElement->next;
	currentElement->next = currentElement->next->next;
	list->head = currentElement;
	list->tail = currentElement->next;
	free(deletedElement);
}

bool isOnlyOneElementLeft(struct List* list)
{
	return list->head == list->tail;
}

int getValueFromHead(struct List* list)
{
	return list->head->value;
}

void deleteList(struct List** list)
{
	while (!isOnlyOneElementLeft(*list))
	{
		deleteElementByNumber((*list), 1);
	}
	free((*list)->head);
	free(*list);
	*list = NULL;
}