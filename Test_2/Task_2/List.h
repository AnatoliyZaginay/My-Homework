#pragma once

#include <stdbool.h>

#define STRING_LENGTH 100

struct List;

// Создаёт список
struct List* createList(void);

// Проверяет, есть ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

// Добавляет элемент в список
void addElementToList(struct List* list, char* value);

// Проверяет содержится ли в списке элемент с указанным значением
bool checkValue(struct List* list, char* value);

// Удаляет первый элемент списка
void deleteHead(struct List* list);

// Удаляет список
void deleteList(struct List** list);

// Возвращает значение первого элемента списка
char* getHeadValue(struct List* list);

// Распечатывает список
void printList(struct List* list);