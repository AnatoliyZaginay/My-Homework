#pragma once

enum ERROR_CODE
{
	ERROR_CODE_STACK_NOT_CREATED,
	ERROR_CODE_NOT_FOUND_BRACKET,
	CORRECT_WORK_CODE,
};

// Переводит арифметическое выражение из инфиксной формы в постфиксную
int fromInfixToPostfix(char line[], char resultLine[]);