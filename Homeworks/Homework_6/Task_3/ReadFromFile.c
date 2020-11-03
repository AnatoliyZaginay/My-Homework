#include "ReadFromFile.h"

#include <stdio.h>

bool readFromFile(struct List* list, char fileName[])
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return false;
	}
	while (!feof(file))
	{
		char name[NAME_LENGTH];
		char phoneNumber[PHONENUMBER_LENGTH];
		fscanf(file, "%s - %s", &name, &phoneNumber);
		add(list, name, phoneNumber);
	}
	fclose(file);
	return true;
}