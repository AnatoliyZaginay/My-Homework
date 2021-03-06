#include "FromInfixToPostfix.h"

#include "../Stack/Stack.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int fromInfixToPostfix(char line[], char resultLine[])
{
	struct Stack* stack = createStack();
	if (stack == NULL)
	{
		return ERROR_CODE_STACK_NOT_CREATED;
	}
	int currentIndex = 0;
	for (int i = 0; i < strlen(line); ++i)
	{
		if (isdigit(line[i]))
		{
			resultLine[currentIndex] = line[i];
			++currentIndex;
		}
		else
		{
			switch (line[i])
			{
			case '+':
			case '-':
				while (!isEmpty(stack) && stackTop(stack) != '(')
				{
					resultLine[currentIndex] = pop(stack);
					++currentIndex;
				}
				push(stack, line[i]);
				break;
			case '*':
			case '/':
				if (!isEmpty(stack) && stackTop(stack) != '(' &&
					(stackTop(stack) == '*' || stackTop(stack) == '/'))
				{
					resultLine[currentIndex] = pop(stack);
					++currentIndex;
				}
				push(stack, line[i]);
				break;
			case '(':
				push(stack, line[i]);
				break;
			case ')':
				while (stackTop(stack) != '(')
				{
					if (isEmpty(stack))
					{
						deleteStack(&stack);
						return ERROR_CODE_NOT_FOUND_BRACKET;
					}
					resultLine[currentIndex] = pop(stack);
					++currentIndex;
				}
				pop(stack);
				break;
			}
		}
	}
	while (!isEmpty(stack))
	{
		if (stackTop(stack) == '(')
		{
			deleteStack(&stack);
			return ERROR_CODE_NOT_FOUND_BRACKET;
		}
		resultLine[currentIndex] = pop(stack);
		++currentIndex;
	}
	deleteStack(&stack);
	return CORRECT_WORK_CODE;
}