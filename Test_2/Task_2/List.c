#include "List.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ListElement
{
	char* string;
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

void addElementToList(struct List* list, char* value)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->next = NULL;
	newElement->string = malloc(strlen(value) + 1);
	if (newElement->string != NULL)
	{
		strcpy(newElement->string, value);
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
		if (strcmp(currentElement->string, value) == 0)
		{
			return true;
		}
		currentElement = currentElement->next;
	}
	return false;
}

void deleteHead(struct List* list)
{
	struct ListElement* deletedElement = list->head;
	list->head = list->head->next;
	free(deletedElement->string);
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

char* getHeadValue(struct List* list)
{
	return list->head->string;
}

void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		printf("%s\n", currentElement->string);
		currentElement = currentElement->next;
	}
}