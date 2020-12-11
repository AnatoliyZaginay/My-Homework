#include "Tree.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define DIGIT_CODE 48

struct TreeElement
{
	int number;
	char symbol;
	struct TreeElement* left;
	struct TreeElement* right;
};

struct Tree
{
	struct TreeElement* root;
};

struct Tree* createTree(void)
{
	return calloc(1, sizeof(struct Tree));
}

int fromStringToNumber(char arithmeticExpression[], int* currentIndex, int length)
{
	int sign = 1;
	if (arithmeticExpression[*currentIndex] == '-')
	{
		sign = -1;
		++(*currentIndex);
	}
	int number = 0;
	while ((*currentIndex) <= length && isdigit(arithmeticExpression[*currentIndex]))
	{
		number = (number * 10) + arithmeticExpression[*currentIndex] - DIGIT_CODE;
		++(*currentIndex);
	}
	number *= sign;
	return number;
}

bool isOperation(const char arithmeticExpression[], int index)
{
	return arithmeticExpression[index] == '+' ||
		(arithmeticExpression[index] == '-' && !isdigit(arithmeticExpression[index + 1])) ||
		arithmeticExpression[index] == '*' || arithmeticExpression[index] == '/';
}

struct TreeElement* addTreeElement(const char arithmeticExpression[], int* currentIndex, const int length)
{
	while ((*currentIndex) <= length && (arithmeticExpression[*currentIndex] == ' ' || arithmeticExpression[*currentIndex] == '(' ||
		arithmeticExpression[*currentIndex] == ')'))
	{
		++(*currentIndex);
	}
	if ((*currentIndex) > length)
	{
		return NULL;
	}
	struct TreeElement* newElement = malloc(sizeof(struct TreeElement));
	if (newElement == NULL)
	{
		return NULL;
	}
	newElement->number = 0;
	newElement->symbol = '\0';
	newElement->left = NULL;
	newElement->right = NULL;
	if (isOperation(arithmeticExpression, *currentIndex))
	{
		newElement->symbol = arithmeticExpression[*currentIndex];
		++(*currentIndex);
		newElement->left = addTreeElement(arithmeticExpression, currentIndex, length);
		newElement->right = addTreeElement(arithmeticExpression, currentIndex, length);
		return newElement;
	}
	newElement->number = fromStringToNumber(arithmeticExpression, currentIndex, length);
	return newElement;
}

void fillTree(struct Tree* tree, char arithmeticExpression[])
{
	const int length = strlen(arithmeticExpression);
	int currentIndex = 0;
	tree->root = addTreeElement(arithmeticExpression, &currentIndex, length);
}

bool isEmpty(struct Tree* tree)
{
	return tree->root == NULL;
}

void printSubtree(struct TreeElement* element, char string[])
{
	if (element->symbol != '\0')
	{
		sprintf(string, "%s( %c ", string, element->symbol);
		printSubtree(element->left, string);
		printSubtree(element->right, string);
		sprintf(string, "%s) ", string);
		return;
	}
	sprintf(string, "%s%i ", string, element->number);
}

void printTree(struct Tree* tree, char string[])
{
	printSubtree(tree->root, string);
}

float calculateSubtree(struct TreeElement* element)
{
	if (element->symbol != '\0')
	{
		switch (element->symbol)
		{
		case '+':
			return calculateSubtree(element->left) + calculateSubtree(element->right);
		case '-':
			return calculateSubtree(element->left) - calculateSubtree(element->right);
		case '*':
			return calculateSubtree(element->left) * calculateSubtree(element->right);
		case '/':
			return calculateSubtree(element->left) / calculateSubtree(element->right);
		}
	}
	return (float)element->number;
}

float calculateTree(struct Tree* tree)
{
	return calculateSubtree(tree->root);
}

void deleteSubtree(struct TreeElement* element)
{
	if (element->left != NULL)
	{
		deleteSubtree(element->left);
	}
	if (element->right != NULL)
	{
		deleteSubtree(element->right);
	}
	free(element);
}

void deleteTree(struct Tree** tree)
{
	if (*tree != NULL && (*tree)->root != NULL)
	{
		deleteSubtree((*tree)->root);
	}
	free(*tree);
	*tree = NULL;
}