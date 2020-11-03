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
};

//Создаёт список
struct List* createList(void);

//Проверяет, содержится ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

//Добавляет в список новый элемент, сохраняя сортированность
void add(struct List* list, int value);

//Удаляет из списка элемент по значению, возращает false в случае если элемент с таким значением не был найден
bool delete(struct List* list, int value);

//Удаляет список
void deleteList(struct List** list);

//Выводит значения всех элементов списка
void printList(struct List* list);