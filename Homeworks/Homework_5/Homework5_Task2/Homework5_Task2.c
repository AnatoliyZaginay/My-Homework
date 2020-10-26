#include "../Stack/StackTests.h"
#include "BracketsBalance.h"
#include "BracketsBalanceTests.h"
#include <stdio.h>
#include <locale.h>

#define LINE_LENGHT 100

void main(void)
{
	if (!stackTests() || !bracketsBalanceTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	printf("Введите скобочную последовательность: ");
	char string[LINE_LENGHT];
	scanf("%s", &string);
	if (isBalanced(string))
	{
		printf("Скобочный баланс выполняется");
	}
	else
	{
		printf("Скобочный баланс не выполняется");
	}
}