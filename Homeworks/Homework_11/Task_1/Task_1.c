#include "AlgorithmKMP.h"
#include "AlgorithmKMPTest.h"
#include "ReadFromFile.h"
#include "ReadFromFileTest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define SUBSTRING_LENGTH 100

void main(void)
{
	if (!readFromFileTest() || !searchSubstringTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	char* string = readFromFile("text.txt");
	if (string == NULL)
	{
		printf("Ошибка чтения файла");
		return;
	}
	char substring[SUBSTRING_LENGTH] = "";
	printf("Введите подстроку: ");
	scanf("%s", &substring);
	const int position = searchSubstring(string, substring);
	if (position == -1)
	{
		printf("Подстрока не встречается в тексте");
	}
	else
	{
		printf("Позиция первого вхождения подстроки в текст: %i - %i", position, position + strlen(substring) - 1);
	}
	free(string);
}