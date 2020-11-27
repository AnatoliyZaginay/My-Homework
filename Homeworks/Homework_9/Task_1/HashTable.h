#pragma once

#include <stdbool.h>

struct HashTable;

// Создаёт хеш-таблицу
struct HashTable* createHashTable(void);

// Добавляет значение в хеш-таблицу
void add(struct HashTable* hashTable, char* value);

// Удаляет хеш-таблицу
void deleteHashTable(struct HashTable** hashTable);

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

// Проверяет, содержится ли в хеш-таблице полученное значение
bool checkValueInHashTable(struct HashTable* hashTable, char* value);