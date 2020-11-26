#include "List.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ListElement
{
	char* value;
	int count;
	struct ListElement* next;
};

struct List
{
	struct ListElement* head;
};

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

void addElementToList(struct List* list, char* value, const int count)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->next = NULL;
	newElement->count = count;
	newElement->value = malloc(strlen(value) + 1);
	if (newElement->value != NULL)
	{
		strcpy(newElement->value, value);
	}
	if (isEmpty(list))
	{
		list->head = newElement;
		return;
	}
	newElement->next = list->head;
	list->head = newElement;
}

bool checkValue(struct List* list, char* value)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		if (strcmp(currentElement->value, value) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}

void updateCount(struct List* list, char* value)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		if (strcmp(currentElement->value, value) == 0)
		{
			++(currentElement->count);
			return;
		}
		currentElement = currentElement->next;
	}
}

char* getValueFromHead(struct List* list)
{
	char* value = malloc(strlen(list->head->value) + 1);
	if (value != NULL)
	{
		strcpy(value, list->head->value);
	}
	return value;
}

int getCountFromHead(struct List* list)
{
	return list->head->count;
}

void deleteHead(struct List* list)
{
	struct ListElement* deletedElement = list->head;
	list->head = list->head->next;
	free(deletedElement->value);
	free(deletedElement);
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

void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		printf("%s - %i\n", currentElement->value, currentElement->count);
		currentElement = currentElement->next;
	}
}