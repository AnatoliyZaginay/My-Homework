#pragma once

#include "List.h"

// В зависимости от параметра sortType выполняет над списком сортировку слиянием либо относительно имени, либо относительно номера телефона, возвращает отсортированный список
struct List* sort(bool sortType, struct List* list);