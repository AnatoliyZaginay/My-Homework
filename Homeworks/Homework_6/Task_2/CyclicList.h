#pragma once

#include <stdbool.h>

struct List;

// Создает список
struct List* createList(void);

// Проверяет, есть ли в списке хотя бы один элемент
bool isEmpty(struct List* list);

// Добавляет значение в список
void add(struct List* list, int value);

// Удаляет элемент из списка по его номеру
void deleteElementByNumber(struct List* list, const int number);

// Проверяет, содержится ли в списке только один элемен
bool isOnlyOneElementLeft(struct List* list);

// Возвращает значение последнего элемента в списке
int getValueFromHead(struct List* list);

// Удаляет список
void deleteList(struct List** list);