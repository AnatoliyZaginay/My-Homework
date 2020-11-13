#pragma once

#include <stdbool.h>

struct Dictionary;

// Создаёт словарь
struct Dictionary* createDictionary(void);

// Добавляет в словарь значение по ключу
void addElement(struct Dictionary* dictionary, int key, char* value);

// Проверяет, есть ли в словаре хотя бы один элемент
bool isEmpty(struct Dictionary* dictionary);

// Возвращает значение элемента словаря по его ключу
char* getValue(struct Dictionary* dictionary, int key);

// Проверяет, есть ли словаре полученный ключ
bool checkKey(struct Dictionary* dictionary, int key);

// Удаляет элемент из словаря по его ключу
bool deleteElement(struct Dictionary* dictionary, int key);

// Удаляет словарь
void deleteDictionary(struct Dictionary** dictionary);