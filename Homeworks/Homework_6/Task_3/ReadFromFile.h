#pragma once

#include "List.h"
#include <stdbool.h>

// ��������� ������ �� ����� � ������, ��������� false, ���� ���� � ����� ��������� �� ��� ������
bool readFromFile(struct List* list, char fileName[]);