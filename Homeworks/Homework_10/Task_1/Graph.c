#include "Graph.h"

#include <stdlib.h>
#include <stdio.h>

struct Country
{
	int capitalNumber;
	bool* cities;
};

struct Graph
{
	int vertices;
	int** matrix;
	bool* used;
	int numberOfCountries;
	struct Country** countries;
};

struct Graph* createGraph(const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return NULL;
	}
	struct Graph* newGraph = calloc(1, sizeof(struct Graph));
	if (newGraph == NULL)
	{
		return NULL;
	}
	int n = 0;
	fscanf(file, "%i", &n);
	newGraph->vertices = n;
	newGraph->matrix = calloc(n, sizeof(int*));
	newGraph->used = calloc(n, sizeof(bool));
	for (int i = 0; i < n; ++i)
	{
		newGraph->matrix[i] = calloc(n, sizeof(int));
	}
	int m = 0;
	fscanf(file, "%i", &m);
	for (int i = 0; i < m; ++i)
	{
		int firstVertex = 0;
		int secondVertex = 0;
		int length = 0;
		fscanf(file, "%i %i %i", &firstVertex, &secondVertex, &length);
		newGraph->matrix[firstVertex - 1][secondVertex - 1] = length;
		newGraph->matrix[secondVertex - 1][firstVertex - 1] = length;
	}
	int k = 0;
	fscanf(file, "%i", &k);
	newGraph->countries = calloc(k, sizeof(struct Country*));
	newGraph->numberOfCountries = k;
	for (int i = 0; i < k; ++i)
	{
		int number = 0;
		fscanf(file, "%i", &number);
		newGraph->countries[i] = calloc(1, sizeof(struct Country));
		newGraph->countries[i]->cities = calloc(n, sizeof(bool));
		newGraph->countries[i]->capitalNumber = number - 1;
		newGraph->countries[i]->cities[number - 1] = true;
		newGraph->used[number - 1] = true;
	}
	return newGraph;
	fclose(file);
}

void deleteGraph(struct Graph** graph)
{
	for (int i = 0; i < (*graph)->vertices; ++i)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free((*graph)->used);
	for (int i = 0; i < (*graph)->numberOfCountries; ++i)
	{
		free((*graph)->countries[i]->cities);
		free((*graph)->countries[i]);
	}
	free((*graph)->countries);
	free(*graph);
	*graph = NULL;
}

bool addCity(struct Graph* graph, const int numberOfCountry)
{
	int minLength = INT_MAX;
	int minCity = -1;
	for (int i = 0; i < graph->vertices; ++i)
	{
		if (graph->countries[numberOfCountry]->cities[i])
		{
			for (int j = 0; j < graph->vertices; ++j)
			{
				if (!(graph->used[j]) && graph->matrix[i][j] > 0 && graph->matrix[i][j] < minLength)
				{
					minLength = graph->matrix[i][j];
					minCity = j;
				}
			}
		}
	}
	if (minCity == -1)
	{
		return false;
	}
	graph->used[minCity] = true;
	graph->countries[numberOfCountry]->cities[minCity] = true;
	return true;
}

void createCountries(struct Graph* graph)
{
	int usedCities = graph->numberOfCountries;
	int currentMove = 0;
	while (usedCities < graph->vertices)
	{
		const int numberOfCurrentCountry = currentMove % graph->numberOfCountries;
		if (addCity(graph, numberOfCurrentCountry))
		{
			++usedCities;
		}
		++currentMove;
	}
}

void printCountries(struct Graph* graph)
{
	for (int i = 0; i < graph->numberOfCountries; ++i)
	{
		printf("Номер государства: %i\n", i + 1);
		printf("Столица государства: %i ", graph->countries[i]->capitalNumber + 1);
		printf("\nГорода государства: ");
		for (int j = 0; j < graph->vertices; ++j)
		{
			if (graph->countries[i]->cities[j])
			{
				printf("%i ", j + 1);
			}
		}
		printf("\n\n");
	}
}

bool* getCountryCities(struct Graph* graph, const int numberOfCountry)
{
	return graph->countries[numberOfCountry]->cities;
}

int getCountryCapital(struct Graph* graph, const int numberOfCountry)
{
	return graph->countries[numberOfCountry]->capitalNumber;
}

int getNumberOfVertices(struct Graph* graph)
{
	return graph->vertices;
}