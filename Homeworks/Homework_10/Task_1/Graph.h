#pragma once

#include <stdbool.h>

struct Graph;

// Создаёт граф по информации из файла
struct Graph* createGraph(const char* fileName);

// Удаляет граф
void deleteGraph(struct Graph** graph);

// Создаёт государства, заполняя их наиболее близкими городами
void createCountries(struct Graph* graph);

// Распечатывает информацию о всех государствах
void printCountries(struct Graph* graph);

// Возвращает указатель на булевый массив городов, содержащихся в государстве, по номеру государства
bool* getCountryCities(struct Graph* graph, const int numberOfCountry);

// Возвращает номер города, являющегося столицей государства, по номеру по государства
int getCountryCapital(struct Graph* graph, const int numberOfCountry);

// Возвращает количество всех городов (вершин графа)
int getNumberOfVertices(struct Graph* graph);