#pragma once

#include "List.h"
#include <stdbool.h>

// —читывает список с файла
bool readFromFile(struct List* list, const char fileName[]);