#include "GraphTests.h"

#include "Graph.h"
#include <stdlib.h>

bool deleteGraphTest(void)
{
	struct Graph* graph = createGraph("graphTest1.txt");
	bool result = graph != NULL;
	deleteGraph(&graph);
	result = graph == NULL;
	return result;
}

bool getNumberOfVerticesTest(void)
{
	struct Graph* graph = createGraph("graphTest1.txt");
	bool result = getNumberOfVertices(graph) == 10;
	deleteGraph(&graph);
	return result;
}

bool getCountryCapitalTest(void)
{
	struct Graph* graph = createGraph("graphTest1.txt");
	bool result = getCountryCapital(graph, 0) == 0 && getCountryCapital(graph, 1) == 3;
	deleteGraph(&graph);
	return result;
}

bool createCountriesTest(void)
{
	struct Graph* graph = createGraph("graphTest1.txt");
	createCountries(graph);
	bool* firstCountryCities = getCountryCities(graph, 0);
	bool* secondCountryCities = getCountryCities(graph, 1);
	for (int i = 0; i < getNumberOfVertices(graph); ++i)
	{
		if (((i == 0 || i == 1 || i == 6 || i == 7 || i == 8) && !firstCountryCities[i]) ||
			((i == 2 || i == 3 || i == 4 || i == 5 || i == 9) && !secondCountryCities[i]))
		{
			deleteGraph(&graph);
			return false;
		}
	}
	bool result = getCountryCapital(graph, 0) == 0 && getCountryCapital(graph, 1) == 3;
	deleteGraph(&graph);
	return result;
}

bool createCountriesOneCityTest(void)
{
	struct Graph* graph = createGraph("graphTest1.txt");
	createCountries(graph);
	bool* countryCities = getCountryCities(graph, 0);
	bool result = countryCities[0] && getCountryCapital(graph, 0) == 0;
	deleteGraph(&graph);
	return result;
}

bool graphTests(void)
{
	return deleteGraphTest() && getNumberOfVerticesTest() && getCountryCapitalTest() && createCountriesTest() && createCountriesOneCityTest();
}