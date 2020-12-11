#pragma once

#include <stdbool.h>

struct List;

// ������ ������
struct List* createList(void);

// ���������, ���������� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

// ��������� � ������ ����� �������, �������� ���������������
void add(struct List* list, int value);

// ������� �� ������ ������� �� ��������, ��������� false � ������ ���� ������� � ����� ��������� �� ��� ������
bool delete(struct List* list, int value);

// ���������� �������� ������� �������� ������
int getValueFromHead(struct List* list);

// ������� ������
void deleteList(struct List** list);

// ������� �������� ���� ��������� ������
void printList(struct List* list);