#pragma once

#include <stdbool.h>

struct HashTable;

// ������� ���-�������
void deleteHashTable(struct HashTable** hashTable);

// ������ ���-�������
struct HashTable* createHashTable(void);

// ��������� �������� � ���-�������,
// value ������� �� �������� �����������
void add(struct HashTable* hashTable, char* value);

// ������������� ��� �������� ���-�������
void printHashTable(struct HashTable* hashTable);

// ���������� ����������� ���������� ���-�������
float getFillFactor(struct HashTable* hashTable);

// ���������� ����� ������������� ������ � �������� ���-�������
int getMaxListLength(struct HashTable* hashTable);

// ���������� ������� ����� ������ � �������� ���-�������
float getAverageListLength(struct HashTable* hashTable);

// ���������, ���������� �� � ���-������� ���� �� ���� �������
bool isHashTableEmpty(struct HashTable* hashTable);

// ���������, ���������� �� � ���-������� ���������� ��������,
// value ������� �� �������� �����������
bool checkValueInHashTable(struct HashTable* hashTable, char* value);