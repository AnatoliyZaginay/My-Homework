#pragma once

#include <stdbool.h>

struct Graph;

// ������ ���� �� ���������� �� �����
struct Graph* createGraph(const char* fileName);

// ������� ����
void deleteGraph(struct Graph** graph);

// ������ �����������, �������� �� �������� �������� ��������
void createCountries(struct Graph* graph);

// ������������� ���������� � ���� ������������
void printCountries(struct Graph* graph);

// ���������� ��������� �� ������� ������ �������, ������������ � �����������, �� ������ �����������
bool* getCountryCities(struct Graph* graph, const int numberOfCountry);

// ���������� ����� ������, ����������� �������� �����������, �� ������ �� �����������
int getCountryCapital(struct Graph* graph, const int numberOfCountry);

// ���������� ���������� ���� ������� (������ �����)
int getNumberOfVertices(struct Graph* graph);