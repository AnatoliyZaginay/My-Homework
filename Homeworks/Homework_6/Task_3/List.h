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
void add(struct List* list, char name[], char phoneNumber[]);

// ������� �� ������� ������, ������� � ������� ������������ ��������
void printList(struct List* list);

// ������� ������
void deleteList(struct List** list);

// ������� ������ ������� � ������
void deleteHead(struct List* list);

// ���������� ����� ������
int listLength(struct List* list);

// ��������� �������� ������� �������� � ������ (� ����������� �� valueType ���������� ���� ���, ���� ����� ��������)
char* getHeadValue(bool valueType, struct List* list);

// ���������, ������ �� ���� ������� ������� � ������
bool isOnlyOneElementLeft(struct List* list);