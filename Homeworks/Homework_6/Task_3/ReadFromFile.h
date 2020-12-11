#pragma once

#include "List.h"
#include <stdbool.h>

// —читывает данные из файла в список, возврщает false, если файл с таким названием не был найден
bool readFromFile(struct List* list, char fileName[]);