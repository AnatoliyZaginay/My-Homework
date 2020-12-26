#include "SearchComments.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 4
#define COLUMNS 3
#define COMMENT_LENGTH 500
#define STATE_TABLE_FILE "StateTable.txt"

bool createStateTabe(const char* fileName, int stateTable[LINES][COLUMNS])
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return false;
	}
	for (int i = 0; i < LINES; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			fscanf(file, "%i", &stateTable[i][j]);
		}
	}
	fclose(file);
	return true;
}

int fromSymbolToIndex(const char symbol)
{
	if (symbol == '/')
	{
		return 1;
	}
	if (symbol == '*')
	{
		return 2;
	}
	return 0;
}

bool searchComments(char* line, char* comments)
{
	int stateTable[LINES][COLUMNS] = { { 0 }, { 0 } };
	if (!createStateTabe(STATE_TABLE_FILE, stateTable))
	{
		return false;
	}
	int currentState = 0;
	int commentIndex = 0;
	char* comment = calloc(COMMENT_LENGTH, sizeof(char));
	for (int i = 0; i < strlen(line); ++i)
	{
		const int index = fromSymbolToIndex(line[i]);
		int nextState = stateTable[currentState][index];
		if (nextState == 1 && currentState == 1)
		{
			continue;
		}
		if (nextState == 0 && currentState != 3)
		{
			if (comment != NULL)
			{
				free(comment);
				comment = NULL;
			}
			commentIndex = 0;
		}
		else
		{
			if (comment == NULL)
			{
				comment = calloc(COMMENT_LENGTH, sizeof(char));
			}
			comment[commentIndex] = line[i];
			++commentIndex;
		}
		if (nextState == 0 && currentState == 3)
		{
			strcat(comments, comment);
			strcat(comments, "\n\n");
			free(comment);
			comment = NULL;
			commentIndex = 0;
		}
		currentState = nextState;
	}
	if (comment != NULL)
	{
		free(comment);
	}
	return true;
}