#pragma once

#include <stdbool.h>

struct Stack;

//Создаёт стек
struct Stack* createStack(void);

//Проверяет, содержится ли в стеке хотя бы один элемент
bool isEmpty(struct Stack* stack);

//Добавляет элемент в стек
void push(struct Stack* stack, int value);

//Возвращает значение с верхушки стека
int stackTop(struct Stack* stack);

//Снимает элемент с верхушки стека
int pop(struct Stack* stack);

//Удаляет стек
void deleteStack(struct Stack** stack);