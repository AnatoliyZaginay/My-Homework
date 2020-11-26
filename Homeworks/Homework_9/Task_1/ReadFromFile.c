#include "ReadFromFile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

#define WORD_LENGTH 60

bool readFromFile(struct HashTable* hashTable, const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		char* line = "";
		return false;
	}
	while (!feof(file))
	{
		char word[WORD_LENGTH] = "";
		fscanf(file, "%s", word);
		if (strlen(word) > 0)
		{
			add(hashTable, word);
		}
	}
	fclose(file);
	return true;
}