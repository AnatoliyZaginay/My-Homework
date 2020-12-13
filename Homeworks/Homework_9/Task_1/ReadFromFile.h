#pragma once

#include <stdbool.h>

// Заполняет хеш-таблицу значениями из файла
bool readFromFile(struct HashTable* hashTable, const char* fileName);