#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define FILE_NAME "comments.txt"

void comments(const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("File not found");
		return;
	}
	bool isComment = false;
	while (!feof(file))
	{
		char currentSymbol = fgetc(file);
		if (currentSymbol == ';')
		{
			isComment = true;
		}
		if (isComment)
		{
			if (currentSymbol == '\n')
			{
				isComment = false;
			}
			printf("%c", currentSymbol);
		}
	}
	fclose(file);
}

void main(void)
{
	setlocale(LC_ALL, "Rus");
	comments(FILE_NAME);
}