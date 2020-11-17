#pragma once

#include <stdbool.h>

struct Dictionary;

// ������ �������
struct Dictionary* createDictionary(void);

// ���������, ������������������ �������
bool dictionaryBalance(struct Dictionary* dictionary);

// ��������� � ������� ������� �� ����������� �����
void addElement(struct Dictionary* dictionary, int key, char* value);

// ���������, ���� �� � ������� ���� �� ���� �������
bool isEmpty(struct Dictionary* dictionary);

// ���������� �������� �� ������� �� �����
char* getValue(struct Dictionary* dictionary, int key);

// ���������, ���������� �� ���������� ���� � �������
bool checkKey(struct Dictionary* dictionary, int key);

// ������� ������� �� ������� �� �����, ���������� false, ���� ���������� ���� �� ���������� � �������
bool deleteElement(struct Dictionary* dictionary, int key);

// ������� �������
void deleteDictionary(struct Dictionary** dictionary);