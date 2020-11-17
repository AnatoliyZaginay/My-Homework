#pragma once

#include <stdbool.h>

struct Dictionary;

// Создаёт словарь
struct Dictionary* createDictionary(void);

// Проверяет, сбалансированность словаря
bool dictionaryBalance(struct Dictionary* dictionary);

// Добавляет в словарь элемент по полученному ключу
void addElement(struct Dictionary* dictionary, int key, char* value);

// Проверяет, есть ли в словаре хотя бы один элемент
bool isEmpty(struct Dictionary* dictionary);

// Возвращает значение из словаря по ключу
char* getValue(struct Dictionary* dictionary, int key);

// Проверяет, содержится ли полученный ключ в словаре
bool checkKey(struct Dictionary* dictionary, int key);

// Удвляет элемент из словаря по ключу, возвращает false, если полученный ключ не содержится в словаре
bool deleteElement(struct Dictionary* dictionary, int key);

// Удаляет словарь
void deleteDictionary(struct Dictionary** dictionary);