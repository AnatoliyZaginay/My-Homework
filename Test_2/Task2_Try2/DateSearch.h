#pragma once

struct Date;

// ���� ������������ ���� � �����, �������� ������������ ���������� ��������� ������������
struct Date* searchMaximumDate(const char* fileName);

// ������������� ����
void printDate(struct Date* date);

// ���������� ����� ���� (����, ����� ��� ���)
int getDate(struct Date* date, int partNumber);