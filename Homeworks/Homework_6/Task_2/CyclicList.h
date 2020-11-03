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

//Создает список
struct List* createList(void);

//Проверяет, есть ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

//Добавляет значение в список
void add(struct List* list, int value);

//Удаляет из циклического списка элемент, на который указывает переданный в функцию элемент
void deleteNextElement(struct ListElement* element, struct List* list);

//Удаляет список
void deleteList(struct List** list);

//Возвращает значение последнего элемента, который останется в циклическом списке, после удаления остальных элементов с определенным периодом
int lastElement(struct List* list, int period);