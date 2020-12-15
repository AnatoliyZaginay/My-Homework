#pragma once

#include <stdbool.h>

#define NAME_LENGTH 40
#define PHONENUMBER_LENGTH 40

struct List;

// ������� ������
struct List* createList(void);

// ���������, ���� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

// ��������� �������� � ������
void add(struct List* list, int number);

// ������� �� ������� ������, ������� � ������� ������������ ��������
void printList(struct List* list);

// ������� ������
void deleteList(struct List** list);

// ������� ������ ������� � ������
void deleteHead(struct List* list);

// ���������� ����� ������
int listLength(struct List* list);

// ��������� �������� ������� �������� � ������ (� ����������� �� valueType ���������� ���� ���, ���� ����� ��������)
int getHeadValue(struct List* list);

// ���������, ������ �� ���� ������� ������� � ������
bool isOnlyOneElementLeft(struct List* list);

// ������������� ������
void printList(struct List* list);