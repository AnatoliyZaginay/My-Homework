#pragma once

#include <stdbool.h>

// ��������� ��� ��������� �� ������ line � comments (�������� ������� � �����������),
// � ������ comments ������������ ��� ����������� �� ������ line ���� /* ����������� */
// (� comments ����������� ��������� ���� �� ����� ��������� "\n\n")
bool searchComments(char* line, char* comments);