#pragma once

#include <stdbool.h>

#define NAME_LENGTH 40
#define PHONENUMBER_LENGTH 40

struct ListElement
{
	char name[NAME_LENGTH];
	char phoneNumber[PHONENUMBER_LENGTH];
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
void add(struct List* list, char name[], char phoneNumber[]);

//Выводит на консоль список, начиная с первого добавленного элемента
void printList(struct List* list);

//Удаляет список
void deleteList(struct List** list);

//Удаляет первый элемент в списке
void deleteTail(struct List* list);

//Возвращает длину списка
int listLength(struct List* list);