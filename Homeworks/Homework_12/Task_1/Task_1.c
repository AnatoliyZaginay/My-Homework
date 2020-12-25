#include "RealNumberLexer.h"
#include "RealNumberLexerTest.h"
#include <stdio.h>
#include <locale.h>

#define LENGTH 100

void main(void)
{
	if (!isRealNumberTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	printf("Введите последовательность символов: ");
	char line[LENGTH] = "";
	scanf("%s", &line);
	if (isRealNumber(line))
	{
		printf("Введённая последовательность является вещественным числом");
	}
	else
	{
		printf("Введённая последовательность не является вещественным числом");
	}
}