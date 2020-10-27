#pragma once

#define ERROR_CODE_NOT_ENOUGH_NUMBERS -1
#define ERROR_CODE_NOT_ENOUGH_OPERATIONS -2
#define ERROR_CODE_DIVISION_BY_ZERO -3
#define ERROR_CODE_WRONG_LINE -4
#define ERROR_CODE_STACK_NOT_CREATED -5
#define CORRECT_WORK_CODE 0

//Возвращает результат работы постфиксного калькулятора
int postfixCalculator(const char line[], int* result);