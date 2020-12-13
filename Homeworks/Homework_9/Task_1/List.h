#pragma once

#include <stdbool.h>

struct List;

// ������ ������
struct List* createList(void);

// ���������, ���������� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

// ��������� ������� � ������,
// value ������� �� �������� �����������
void addElementToList(struct List* list, char* value, const int count);

// ���������, ���������� �� � ������ ���������� ��������,
// value ������� �� �������� �����������
bool checkValue(struct List* list, char* value);

// ��������� 1 � ���������� �������� ������ � ��������� ���������,
// value ������� �� �������� �����������
void updateCount(struct List* list, char* value);

// ���������� �������� ������� �������� � ������ (� ��������� ������������ ����������)
char* getValueFromHead(struct List* list);

// ���������� ���������� ������� �������� � ������
int getCountFromHead(struct List* list);

// ������� ������ ������� � ������
void deleteHead(struct List* list);

// ������� ������
void deleteList(struct List** list);

// ������������� ��� �������� ������
void printList(struct List* list);