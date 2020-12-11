#include "StringReading.h"

#include <stdio.h>

void stringReading(char line[], int const lenght)
{
	char symbol = '\0';
	scanf("%c", &symbol);
	int currentLenght = 0;
	while (symbol != '\n' && currentLenght < lenght)
	{
		if (symbol != ' ')
		{
			line[currentLenght] = symbol;
			++currentLenght;
		}
		scanf("%c", &symbol);
	}
}