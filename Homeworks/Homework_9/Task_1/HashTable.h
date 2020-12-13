#pragma once

#include <stdbool.h>

struct HashTable;

// Удаляет хеш-таблицу
void deleteHashTable(struct HashTable** hashTable);

// Создаёт хеш-таблицу
struct HashTable* createHashTable(void);

// Добавляет значение в хеш-таблицу,
// value остаётся во владении вызывающего
void add(struct HashTable* hashTable, char* value);

// Распечатывает все элементы хеш-таблицы
void printHashTable(struct HashTable* hashTable);

// Возвращает коэффициент заполнения хеш-таблицы
float getFillFactor(struct HashTable* hashTable);

// Возвращает длину максимального списка в сегменте хеш-таблицы
int getMaxListLength(struct HashTable* hashTable);

// Возвращает среднюю длину списка в сегменте хещ-таблицы
float getAverageListLength(struct HashTable* hashTable);

// Проверяет, содержится ли в хеш-таблице хотя бы один элемент
bool isHashTableEmpty(struct HashTable* hashTable);

// Проверяет, содержится ли в хеш-таблице полученное значение,
// value остаётся во владении вызывающего
bool checkValueInHashTable(struct HashTable* hashTable, char* value);