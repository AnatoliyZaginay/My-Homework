#include "List.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListElement
{
	char name[NAME_LENGTH];
	char phoneNumber[PHONENUMBER_LENGTH];
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

void add(struct List* list, char* name, char* phoneNumber)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	++(list->length);
	strcpy(newElement->name, name);
	strcpy(newElement->phoneNumber, phoneNumber);
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

char* getHeadValue(bool valueType, struct List* list)
{
	if (valueType)
	{
		return list->head->name;
	}
	return list->head->phoneNumber;
}

void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		printf("%s - %s\n", currentElement->name, currentElement->phoneNumber);
		currentElement = currentElement->next;
	}
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