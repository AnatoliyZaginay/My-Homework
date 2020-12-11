#pragma once

enum ERROR_CODE
{
	ERROR_CODE_NOT_ENOUGH_NUMBERS,
	ERROR_CODE_NOT_ENOUGH_OPERATIONS,
	ERROR_CODE_DIVISION_BY_ZERO,
	ERROR_CODE_WRONG_LINE,
	ERROR_CODE_STACK_NOT_CREATED,
	CORRECT_WORK_CODE
};

// Возвращает результат работы постфиксного калькулятора
int postfixCalculator(const char line[], int* result);