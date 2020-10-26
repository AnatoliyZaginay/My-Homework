#include "Stack.h"

#include <stdlib.h>

struct StackElement
{
	int value;
	struct StackElement* next;
};

struct Stack
{
	struct StackElement* head;
};

struct Stack* createStack(void)
{
	struct Stack* newStack = malloc(sizeof(struct Stack));
	newStack->head = NULL;
	return newStack;
}

bool isEmpty(struct Stack* stack)
{
	return stack->head == NULL;
}

void push(struct Stack* stack, int value)
{
	struct StackElement* newElement = malloc(sizeof(struct StackElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

int pop(struct Stack* stack)
{
	if (stack == NULL || isEmpty(stack))
	{
		return 0;
	}
	int value = stack->head->value;
	struct StackElement* oldHead = stack->head;
	stack->head = stack->head->next;
	free(oldHead);
	return value;
}

void deleteStack(struct Stack** stack)
{
	while (!isEmpty(*stack))
	{
		pop(*stack);
	}
	free(*stack);
	*stack = NULL;
}