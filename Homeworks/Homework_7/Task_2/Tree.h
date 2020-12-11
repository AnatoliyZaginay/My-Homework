#pragma once

#include <stdbool.h>

struct Tree;

// ������ ������
struct Tree* createTree(void);

// ��������� ������ �� ��������������� ���������
void fillTree(struct Tree* tree, char arithmeticExpression[]);

// ���������, ���� �� � ������ ���� �� ���� �������
bool isEmpty(struct Tree* tree);

// ������� ������ � ������� � ������� �������� ��� ��������� � ������
void printTree(struct Tree* tree, char string[]);

// ������� �������� ������ ������� ��������������� ���������
float calculateTree(struct Tree* tree);

// ������� ������
void deleteTree(struct Tree** tree);