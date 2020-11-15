#pragma once

#include <stdbool.h>

struct Tree;

struct Tree* createTree(void);

// Заполняет дерево по арифметическому выражению
void fillTree(struct Tree* tree, char arithmeticExpression[]);

// Проверяет, есть ли в дереве хотя бы один элемент
bool isEmpty(struct Tree* tree);

// Обходит дерево в глубину и выводит значения его элементов
void printTree(struct Tree* tree);

// Считает значение дерева разбора арифметического выражения
float calculateTree(struct Tree* tree);

// Удаляет дерево
void deleteTree(struct Tree** tree);