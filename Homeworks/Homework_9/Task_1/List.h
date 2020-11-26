#pragma once

#include <stdbool.h>

struct List;

struct List* createList(void);

bool isEmpty(struct List* list);

void addElementToList(struct List* list, char* value, const int count);

bool checkValue(struct List* list, char* value);

void updateCount(struct List* list, char* value);

char* getValueFromHead(struct List* list);

int getCountFromHead(struct List* list);

void deleteHead(struct List* list);

void deleteList(struct List** list);

void printList(struct List* list);