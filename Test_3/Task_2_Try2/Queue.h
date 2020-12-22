#pragma once

#include <stdbool.h>

struct Queue;

// Создаёт очередь
struct Queue* createQueue(void);

// Проверяет, содержится ли в очереди хотя бы один элемент
bool isEmpty(struct Queue* queue);

// Добавляет в очередь значение, учитывая приоритет
void enqueue(struct Queue* queue, int value, int priority);

// Возвращает из очереди значение с наибольшим приоритетом
int dequeue(struct Queue* queue);

// Удаляет очередь
void deleteQueue(struct Queue** queue);