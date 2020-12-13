#pragma once

#include <stdbool.h>

struct Dictionary;

// ������ �������
struct Dictionary* createDictionary(void);

// ���������, ������������������ �������
bool dictionaryBalance(struct Dictionary* dictionary);

// ��������� � ������� ������� �� ����������� ����� � ��������,
// key � value �������� �� �������� �����������
void addElement(struct Dictionary* dictionary, char* key, char* value);

// ���������, ���� �� � ������� ���� �� ���� �������
bool isEmpty(struct Dictionary* dictionary);

// ���������� �������� �� ������� �� �����,
// key ������� �� �������� �����������,
// ������������ ��������� ������� �� �������� dictionary
char* getValue(struct Dictionary* dictionary, char* key);

// ���������, ���������� �� ���������� ���� � �������
// key ������� �� �������� �����������
bool checkKey(struct Dictionary* dictionary, char* key);

// ������� ������� �� ������� �� �����, ���������� false, ���� ���������� ���� �� ���������� � �������,
// key ������� �� �������� �����������
bool deleteElement(struct Dictionary* dictionary, char* key);

// ������� �������
void deleteDictionary(struct Dictionary** dictionary);