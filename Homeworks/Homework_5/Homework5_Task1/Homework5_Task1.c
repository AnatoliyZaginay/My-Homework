#include "StringReading.h"
#include "PostfixCalculator.h"
#include "PostfixCalculatorTests.h"
#include "../Stack/StackTests.h"
#include <stdio.h>
#include <locale.h>

#define STRING_LENGHT 100

void main(void)
{
	if (!postfixCalculatorTest() || !stackTests())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	char string[STRING_LENGHT];
	for (int i = 0; i < STRING_LENGHT; ++i)
	{
		string[i] = '\0';
	}
	printf("Введите арифметическое выражение в постфиксном виде: ");
	stringReading(string, STRING_LENGHT);
	int result = 0;
	const int postfixCalculatorReturnCode = postfixCalculator(string, &result);
	switch (postfixCalculatorReturnCode)
	{
	case CORRECT_WORK_CODE:
		printf("Результат работы калькулятора: %i", result);
		break;
	case ERROR_CODE_NOT_ENOUGH_NUMBERS:
		printf("Неправильное арифметическое выражение (недостаточно чисел для выполнения операции)");
		break;
	case ERROR_CODE_NOT_ENOUGH_OPERATIONS:
		printf("Неправильное арифметическое выражение (недостаточно операций)");
		break;
	case ERROR_CODE_WRONG_LINE:
		printf("Неправильное арифметическое выражение (вводить разрешено только числа и арифметические операции)");
		break;
	case ERROR_CODE_DIVISION_BY_ZERO:
		printf("На ноль делить нельзя");
		break;
	case ERROR_CODE_STACK_NOT_CREATED:
		printf("Ошибка создания стека");
		break;
	}
}