#include "StringReading.h"
#include "FromInfixToPostfix.h"
#include "FromInfixToPostfixTests.h"
#include "../Stack/StackTests.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

#define STRING_LENGHT 100

void main(void)
{
	if (!stackTests() || !fromInfixToPostfixTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	printf("Введите арифметическое выражение в инфиксной форме: ");
	char string[STRING_LENGHT];
	char result[STRING_LENGHT];
	for (int i = 0; i < STRING_LENGHT; ++i)
	{
		string[i] = '\0';
		result[i] = '\0';
	}
	stringReading(string, STRING_LENGHT);
	int fromInfixToPostfixReturnCode = fromInfixToPostfix(string, result);
	switch (fromInfixToPostfixReturnCode)
	{
	case CORRECT_WORK_CODE:
		printf("Выражение в постфиксной форме: ");
		for (int i = 0; i < strlen(result); ++i)
		{
			printf("%c ", result[i]);
		}
		break;
	case ERROR_CODE_STACK_NOT_CREATED:
		printf("Ошибка создания стека");
		break;
	case ERROR_CODE_NOT_FOUND_BRACKET:
		printf("Нарушен скобочный баланс");
		break;
	}
}