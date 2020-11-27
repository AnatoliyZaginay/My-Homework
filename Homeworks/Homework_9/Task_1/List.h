#pragma once

#include <stdbool.h>

struct List;

// Создаёт список
struct List* createList(void);

// Проверяет, содержится ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

// Добавляет элемент в список
void addElementToList(struct List* list, char* value, const int count);

// Проверяет, содержится ли в списке полученное значение
bool checkValue(struct List* list, char* value);

// Добавляет 1 к количеству элемента списка с указанным значением
void updateCount(struct List* list, char* value);

// Возвращает значение первого элемента в списке
char* getValueFromHead(struct List* list);

// Возвращает количество первого элемента в списке
int getCountFromHead(struct List* list);

// Удаляет первый элемент в списке
void deleteHead(struct List* list);

// Удаляет список
void deleteList(struct List** list);

// Распечатывает все элементы списка
void printList(struct List* list);