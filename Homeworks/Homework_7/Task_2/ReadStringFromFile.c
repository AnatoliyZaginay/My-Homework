#include "ReadStringFromFile.h"
#include <stdio.h>

bool readStringFromFile(char string[], int length, char fileName[])
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return false;
	}
	fgets(string, length, file);
	fclose(file);
	return true;
}