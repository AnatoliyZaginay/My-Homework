#pragma once

#include <stdbool.h>

struct List;

// ������ ������
struct List* createList(void);

// ���������, ���������� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

// ��������� �������� � ������
void add(struct List* list, int value);

// ������� ������
void deleteList(struct List** list);

// ���������� �������� �������� ������ �� ��� �������
int getValue(struct List* list, int index);

// ���������� ����� ������
int getLength(struct List* list);

// �������� ������
void printList(struct List* list);