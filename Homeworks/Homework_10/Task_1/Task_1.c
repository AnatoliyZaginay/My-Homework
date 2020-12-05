#include "Graph.h"
#include "GraphTests.h"
#include <stdio.h>
#include <locale.h>

#define FILE_NAME "graph.txt"

void main(void)
{
	if (!graphTests())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct Graph* graph = createGraph(FILE_NAME);
	if (graph == NULL)
	{
		printf("Ошибка создания графа");
		return;
	}
	createCountries(graph);
	printCountries(graph);
	deleteGraph(&graph);
}