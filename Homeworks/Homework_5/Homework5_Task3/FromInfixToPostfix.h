#pragma once

#define ERROR_CODE_STACK_NOT_CREATED -1
#define ERROR_CODE_NOT_FOUND_BRACKET -2
#define CORRECT_WORK_CODE 0

//Переводит арифметическое выражение из инфиксной формы в постфиксную
int fromInfixToPostfix(char line[], char resultLine[]);