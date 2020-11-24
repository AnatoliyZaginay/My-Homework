#include "ReadFromFile.h"

#include <stdio.h>
#include <stdlib.h>

#include "ReadFromFile.h"

#include <stdio.h>

bool readFromFile(struct List* list, const char fileName[])
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return false;
	}
	while (!feof(file))
	{
		int value = 0;
		fscanf(file, "%i", &value);
		add(list, value);
	}
	fclose(file);
	return true;
}