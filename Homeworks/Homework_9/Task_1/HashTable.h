#pragma once

struct HashTable;

struct HashTable* createHashTable(void);

void add(struct HashTable* hashTable, char* value);

void deleteHashTable(struct HashTable** hashTable);

void printHashTable(struct HashTable* hashTable);

float getFillFactor(struct HashTable* hashTable);

int getMaxListLength(struct HashTable* hashTable);

float getAverageListLength(struct HashTable* hashTable);