#include "CyclicList.h"

#include <stdlib.h>

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

void deleteNextElement(struct ListElement* element, struct List* list)
{
	struct ListElement* deletedElement = element->next;
	element->next = element->next->next;
	free(deletedElement);
	list->head = element;
	list->tail = element->next;
}

void deleteList(struct List** list)
{
	while ((*list)->head != (*list)->tail)
	{
		deleteNextElement((*list)->head, *list);
	}
	free((*list)->head);
	free(*list);
	*list = NULL;
}

int lastElement(struct List* list, int period)
{
	if (period <= 0 || isEmpty(list))
	{
		return -1;
	}
	int currentPosition = 0;
	struct ListElement* currentElement = list->head;
	while (list->head != list->tail)
	{
		++currentPosition;
		if (currentPosition % period == 0)
		{
			deleteNextElement(currentElement, list);
		}
		else
		{
			currentElement = currentElement->next;
		}
	}
	return currentElement->value;
}