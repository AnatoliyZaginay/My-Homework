#pragma once

#include <stdbool.h>

struct Dictionary;

// Создаёт словарь
struct Dictionary* createDictionary(void);

// Проверяет, сбалансированность словаря
bool dictionaryBalance(struct Dictionary* dictionary);

// Добавляет в словарь элемент по полученному ключу и значению,
// key и value остаются во владении вызывающего
void addElement(struct Dictionary* dictionary, char* key, char* value);

// Проверяет, есть ли в словаре хотя бы один элемент
bool isEmpty(struct Dictionary* dictionary);

// Возвращает значение из словаря по ключу,
// key остаётся во владении вызывающего,
// возвращаемый указатель остаётся во владении dictionary
char* getValue(struct Dictionary* dictionary, char* key);

// Проверяет, содержится ли полученный ключ в словаре
// key остаётся во владении вызывающего
bool checkKey(struct Dictionary* dictionary, char* key);

// Удвляет элемент из словаря по ключу, возвращает false, если полученный ключ не содержится в словаре,
// key остаётся во владении вызывающего
bool deleteElement(struct Dictionary* dictionary, char* key);

// Удаляет словарь
void deleteDictionary(struct Dictionary** dictionary);