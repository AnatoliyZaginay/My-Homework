#include "SearchComments.h"
#include "SearchCommentsTest.h"
#include "ReadFromFile.h"
#include "ReadFromFileTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define FILE_NAME "text.txt"
#define LENGTH 10000

void main(void)
{
	if (!searchCommentsTest() || !readFromFileTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	char* line = readFromFile(FILE_NAME);
	if (line == NULL)
	{
		printf("Ошибка чтения из файла");
		return;
	}
	char comments[LENGTH] = "";
	if (!searchComments(line, comments))
	{
		printf("Файл таблицы состояний не найден");
		return;
	}
	free(line);
	printf("Найденные комментарии:\n");
	printf("%s", comments);
}