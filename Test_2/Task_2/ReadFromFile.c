#include "ReadFromFile.h"

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializationString(char string[], const int length)
{
	for (int i = 0; i < length; ++i)
	{
		string[i] = '\0';
	}
}

void readFromFile(const char* fileName, struct List* list)
{
	FILE* file = fopen(fileName, "r");
	int currentIndex = 0;
	char string[STRING_LENGTH] = "";
	char symbol = fgetc(file);
	while (symbol != EOF)
	{
		if (symbol == '\n' || symbol == '\0')
		{
			addElementToList(list, string);
			currentIndex = 0;
			initializationString(string, strlen(string));
			symbol = fgetc(file);
			continue;
		}
		string[currentIndex] = symbol;
		++currentIndex;
		symbol = fgetc(file);
	}
	addElementToList(list, string);
	fclose(file);
}