#pragma once

#include <stdbool.h>

struct ListElement
{
	int value;
	struct ListElement* next;
};

struct List
{
	struct ListElement* head;
};

struct List* createList(void);

bool isEmpty(struct List* list);

void add(struct List* list, int value);

bool delete(struct List* list, int value);

void deleteList(struct List** list);

void printList(struct List* list);