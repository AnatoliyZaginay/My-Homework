#pragma once

#include <stdbool.h>

// опирует содержимое второго массива в первый (массивы должны быть одного размера)
void copyArray(int firstArray[], int secondArray[], const int size);

//—равнивает совпадение элементов массива
bool compareArrays(int firstArray[], int secondArray[], const int size);