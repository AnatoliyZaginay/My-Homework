#pragma once

struct TreeElement;

// Создаёт по строке символов двоичное дерево по алгоритму Хаффмана
struct TreeElement* buildTree(char* string);

// Распечатывает коды листьев дерева
void printCodes(struct TreeElement* root, char* code, int index);

// Удаляет дерево
void deleteTree(struct TreeElement* root);