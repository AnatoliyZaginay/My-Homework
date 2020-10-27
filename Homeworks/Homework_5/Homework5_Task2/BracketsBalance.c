#include "BracketsBalance.h"

#include "../Stack/Stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ROUND_BRACKET_CODE (int)'('
#define SQUARE_BRACKET_CODE (int)'['
#define CURLY_BRACKET_CODE (int)'{'

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
			push(stack, (int)bracketSequence[i]);
		}
		if (bracketSequence[i] == ')' || bracketSequence[i] == ']' || bracketSequence[i] == '}')
		{
			if (isEmpty(stack))
			{
				deleteStack(&stack);
				return false;
			}
			switch (bracketSequence[i])
			{
			case ')':
				if (pop(stack) != ROUND_BRACKET_CODE)
				{
					deleteStack(&stack);
					return false;
				}
				break;
			case ']':
				if (pop(stack) != SQUARE_BRACKET_CODE)
				{
					deleteStack(&stack);
					return false;
				}
				break;
			case '}':
				if (pop(stack) != CURLY_BRACKET_CODE)
				{
					deleteStack(&stack);
					return false;
				}
				break;
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