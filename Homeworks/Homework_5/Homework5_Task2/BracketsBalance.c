#include "BracketsBalance.h"

#include "../Stack/Stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char getOpenedBracket(const char bracket)
{
	if (bracket == ')')
	{
		return '(';
	}
	if (bracket == ']')
	{
		return '[';
	}
	return '{';
}

bool isBalanced(const char bracketSequence[])
{
	struct Stack* stack = createStack();
	if (stack == NULL)
	{
		printf("Ошибка создания стека\n");
		return false;
	}
	for (int i = 0; i < strlen(bracketSequence); ++i)
	{
		if (bracketSequence[i] == '(' || bracketSequence[i] == '[' || bracketSequence[i] == '{')
		{
			push(stack, bracketSequence[i]);
		}
		if (bracketSequence[i] == ')' || bracketSequence[i] == ']' || bracketSequence[i] == '}')
		{
			if (isEmpty(stack) || pop(stack) != getOpenedBracket(bracketSequence[i]))
			{
				deleteStack(&stack);
				return false;
			}
		}
	}
	if (!isEmpty(stack))
	{
		deleteStack(&stack);
		return false;
	}
	deleteStack(&stack);
	return true;
}