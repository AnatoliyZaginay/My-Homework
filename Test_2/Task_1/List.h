#pragma once

#include <stdbool.h>

struct List;

// Создаёт список
struct List* createList(void);

// Проверяет, содержится ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

// Добавляет значение в список
void add(struct List* list, int value);

// Удаляет список
void deleteList(struct List** list);

// Возвращает значение элемента списка по его индексу
int getValue(struct List* list, int index);

// Возвращает длину списка
int getLength(struct List* list);

// Печатает список
void printList(struct List* list);