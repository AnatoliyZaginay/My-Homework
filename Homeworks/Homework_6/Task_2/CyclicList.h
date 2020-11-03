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
	struct ListElement* tail;
};

//������� ������
struct List* createList(void);

//���������, ���� �� � ������ ���� �� ���� �������
bool isEmpty(struct List* list);

//��������� �������� � ������
void add(struct List* list, int value);

//������� �� ������������ ������ �������, �� ������� ��������� ���������� � ������� �������
void deleteNextElement(struct ListElement* element, struct List* list);

//������� ������
void deleteList(struct List** list);

//���������� �������� ���������� ��������, ������� ��������� � ����������� ������, ����� �������� ��������� ��������� � ������������ ��������
int lastElement(struct List* list, int period);