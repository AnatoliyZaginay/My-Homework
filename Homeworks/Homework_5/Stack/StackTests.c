#include "StackTests.h"

#include "Stack.h"
#include <stdlib.h>

bool deleteStackTest(void)
{
	struct Stack* stack = createStack();
	deleteStack(&stack);
	return stack == NULL;
}

bool isEmptyTest(void)
{
	struct Stack* stack = createStack();
	bool result = isEmpty(stack);
	deleteStack(&stack);
	return result;
}

bool pushTest(void)
{
	struct Stack* stack = createStack();
	push(stack, 1);
	bool result = isEmpty(stack);
	deleteStack(&stack);
	return !result;
}

bool popTest(void)
{
	struct Stack* stack = createStack();
	push(stack, 1);
	push(stack, 2);
	bool result = (pop(stack) == 2 && pop(stack) == 1 &&
		isEmpty(stack) && pop(stack) == 0);
	deleteStack(&stack);
	return result;
}

bool stackTopTest(void)
{
	struct Stack* stack = createStack();
	push(stack, 1);
	push(stack, 2);
	bool result = (stackTop(stack) == 2 && pop(stack) == 2 && stackTop(stack) == 1 &&
		pop(stack) == 1 && isEmpty(stack) && stackTop(stack) == 0);
	deleteStack(&stack);
	return result;
}

bool stackTests(void)
{
	return deleteStackTest() && isEmptyTest() &&
		pushTest() && popTest() && stackTopTest();
}