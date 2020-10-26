#include "postfixCalculator.h"

#include "../Stack/Stack.h"
#include <string.h>
#include <ctype.h>

#define DIGIT_CODE 48

int postfixCalculator(const char line[], int* result)
{
	struct Stack* stack = createStack();
	for (int i = 0; i < strlen(line); ++i)
	{
		if (isdigit(line[i]))
		{
			int number = (int)line[i] - DIGIT_CODE;
			push(stack, number);
			continue;
		}
		if (line[i] == '+' || line[i] == '-' ||
			line[i] == '*' || line[i] == '/')
		{
			if (isEmpty(stack))
			{
				deleteStack(&stack);
				return ERROR_CODE_NOT_ENOUGH_NUMBERS;
			}
			const int firstNumber = pop(stack);
			if (isEmpty(stack))
			{
				deleteStack(&stack);
				return ERROR_CODE_NOT_ENOUGH_NUMBERS;
			}
			const int secondNumber = pop(stack);
			switch (line[i])
			{
			case '+':
				push(stack, firstNumber + secondNumber);
				break;
			case '-':
				push(stack, secondNumber - firstNumber);
				break;
			case '*':
				push(stack, firstNumber * secondNumber);
				break;
			case '/':
				if (firstNumber == 0)
				{
					deleteStack(&stack);
					return ERROR_CODE_DIVISION_BY_ZERO;
				}
				push(stack, secondNumber / firstNumber);
				break;
			}
		}
		else
		{
			deleteStack(&stack);
			return ERROR_CODE_WRONG_LINE;
		}
	}
	*result = pop(stack);
	if (!isEmpty(stack))
	{
		deleteStack(&stack);
		return ERROR_CODE_NOT_ENOUGH_OPERATIONS;
	}
	deleteStack(&stack);
	return CORRECT_WORK_CODE;
}