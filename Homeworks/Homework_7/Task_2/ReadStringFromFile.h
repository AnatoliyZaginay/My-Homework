#pragma once

#include <stdbool.h>

// —читывает строку из файла в string[], возвращает false, если не удалось открыть файл
bool readStringFromFile(char string[], int length, char fileName[]);