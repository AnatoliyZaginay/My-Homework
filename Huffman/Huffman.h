#pragma once

struct TreeElement;

// ������ �� ������ �������� �������� ������ �� ��������� ��������
struct TreeElement* buildTree(char* string);

// ������������� ���� ������� ������
void printCodes(struct TreeElement* root, char* code, int index);

// ������� ������
void deleteTree(struct TreeElement* root);