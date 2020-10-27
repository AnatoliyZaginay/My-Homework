#pragma once

#include <stdbool.h>

struct Stack;

//������ ����
struct Stack* createStack(void);

//���������, ���������� �� � ����� ���� �� ���� �������
bool isEmpty(struct Stack* stack);

//��������� ������� � ����
void push(struct Stack* stack, int value);

//���������� �������� � �������� �����
int stackTop(struct Stack* stack);

//������� ������� � �������� �����
int pop(struct Stack* stack);

//������� ����
void deleteStack(struct Stack** stack);