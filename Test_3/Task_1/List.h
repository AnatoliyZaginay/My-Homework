#pragma once

#include <stdbool.h>

#define NAME_LENGTH 40
#define PHONENUMBER_LENGTH 40

struct List;

// Создает список
struct List* createList(void);

// Проверяет, есть ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

// Добавляет значение в список
void add(struct List* list, int number);

// Выводит на консоль список, начиная с первого добавленного элемента
void printList(struct List* list);

// Удаляет список
void deleteList(struct List** list);

// Удаляет первый элемент в списке
void deleteHead(struct List* list);

// Возвращает длину списка
int listLength(struct List* list);

// Возврщает значение первого элемента в списке (в зависимости от valueType возвращает либо имя, либо номер телефона)
int getHeadValue(struct List* list);

// Проверяет, только ли один элемент остался в списке
bool isOnlyOneElementLeft(struct List* list);

// Распечатывает список
void printList(struct List* list);