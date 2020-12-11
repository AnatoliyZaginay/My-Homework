#include "StringReading.h"

#include <stdio.h>

void stringReading(char line[], int const length)
{
	char symbol = '\0';
	scanf("%c", &symbol);
	int currentLength = 0;
	while (symbol != '\n' && currentLength < length)
	{
		if (symbol != ' ')
		{
			line[currentLength] = symbol;
			++currentLength;
		}
		scanf("%c", &symbol);
	}
}