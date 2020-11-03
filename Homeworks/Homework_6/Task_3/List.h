#pragma once

#include <stdbool.h>

#define NAME_LENGTH 40
#define PHONENUMBER_LENGTH 40

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
};

struct List* createList(void);

bool isEmpty(struct List* list);

void add(struct List* list, char name[], char phoneNumber[]);

void printList(struct List* list);

void deleteList(struct List** list);

void deleteTail(struct List* list);

int listLength(struct List* list);