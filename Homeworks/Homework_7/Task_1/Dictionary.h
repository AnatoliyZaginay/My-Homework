#pragma once

#include <stdbool.h>

struct Dictionary;

// ������ �������
struct Dictionary* createDictionary(void);

// ��������� � ������� �������� �� �����
void addElement(struct Dictionary* dictionary, int key, char* value);

// ���������, ���� �� � ������� ���� �� ���� �������
bool isEmpty(struct Dictionary* dictionary);

// ���������� �������� �������� ������� �� ��� �����
char* getValue(struct Dictionary* dictionary, int key);

// ���������, ���� �� ������� ���������� ����
bool checkKey(struct Dictionary* dictionary, int key);

// ������� ������� �� ������� �� ��� �����
bool deleteElement(struct Dictionary* dictionary, int key);

// ������� �������
void deleteDictionary(struct Dictionary** dictionary);