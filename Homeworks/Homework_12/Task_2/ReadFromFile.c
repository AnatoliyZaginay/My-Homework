#include "ReadFromFile.h"

#include <stdio.h>
#include <stdlib.h>

int getTextLength(const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return -1;
	}
	int length = 0;
	while (!feof(file))
	{
		fgetc(file);
		++length;
	}
	fclose(file);
	return length;
}

char* readFromFile(const char* fileName)
{
	const length = getTextLength(fileName);
	if (length == -1)
	{
		return NULL;
	}
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return NULL;
	}
	char* string = calloc(length + 1, sizeof(char));
	for (int i = 0; i < length - 1; ++i)
	{
		string[i] = fgetc(file);
	}
	string[length] = '\0';
	fclose(file);
	return string;
}