#pragma once

#include <stdbool.h>

struct Queue;

// ������ �������
struct Queue* createQueue(void);

// ���������, ���������� �� � ������� ���� �� ���� �������
bool isEmpty(struct Queue* queue);

// ��������� � ������� ��������, �������� ���������
void enqueue(struct Queue* queue, int value, int priority);

// ���������� �� ������� �������� � ���������� �����������
int dequeue(struct Queue* queue);

// ������� �������
void deleteQueue(struct Queue** queue);