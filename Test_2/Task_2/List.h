#pragma once

#include <stdbool.h>

#define STRING_LENGTH 100

struct List;

// ������ ������
struct List* createList(void);

// ���������, ���� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

// ��������� ������� � ������
void addElementToList(struct List* list, char* value);

// ��������� ���������� �� � ������ ������� � ��������� ���������
bool checkValue(struct List* list, char* value);

// ������� ������ ������� ������
void deleteHead(struct List* list);

// ������� ������
void deleteList(struct List** list);

// ���������� �������� ������� �������� ������
char* getHeadValue(struct List* list);

// ������������� ������
void printList(struct List* list);