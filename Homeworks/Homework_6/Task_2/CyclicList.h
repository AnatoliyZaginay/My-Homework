#pragma once

#include <stdbool.h>

struct List;

// ������� ������
struct List* createList(void);

// ���������, ���� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

// ��������� �������� � ������
void add(struct List* list, int value);

// ������� ������� �� ������ �� ��� ������
void deleteElementByNumber(struct List* list, const int number);

// ���������, ���������� �� � ������ ������ ���� ������
bool isOnlyOneElementLeft(struct List* list);

// ���������� �������� ���������� �������� � ������
int getValueFromHead(struct List* list);

// ������� ������
void deleteList(struct List** list);