#pragma once

#include <stdbool.h>

// Возвращает указатель на строку, содержащую текст из файла (с владением возвращаемым указателем)
char* readFromFile(const char* fileName);