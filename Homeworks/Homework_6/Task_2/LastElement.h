#pragma once

#include "CyclicList.h"

// Возвращает значение последнего элемента, который останется в циклическом списке, после удаления остальных элементов с определенным периодом
int lastElement(struct List* list, int period);