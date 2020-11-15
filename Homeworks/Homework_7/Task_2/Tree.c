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
	struct Tree* newTree = malloc(sizeof(struct Tree));
	if (newTree != NULL)
	{
		newTree->root = NULL;
	}
	return newTree;
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

struct TreeElement* addTreeElement(char arithmeticExpression[], int* currentIndex, int length)
{
	struct TreeElement* newElement = malloc(sizeof(struct TreeElement));
	if (newElement == NULL)
	{
		return NULL;
	}
	newElement->number = 0;
	newElement->symbol = '\0';
	newElement->left = NULL;
	newElement->right = NULL;
	while ((*currentIndex) <= length && (arithmeticExpression[*currentIndex] == ' ' || arithmeticExpression[*currentIndex] == '(' ||
		arithmeticExpression[*currentIndex] == ')'))
	{
		++(*currentIndex);
	}
	if ((*currentIndex) > length)
	{
		free(newElement);
		return NULL;
	}
	if (arithmeticExpression[*currentIndex] == '+' ||
		(arithmeticExpression[*currentIndex] == '-' && !isdigit(arithmeticExpression[*currentIndex + 1])) ||
		arithmeticExpression[*currentIndex] == '*' || arithmeticExpression[*currentIndex] == '/')
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

void printSubtree(struct TreeElement* element)
{
	if (element->symbol != '\0')
	{
		printf("( %c ", element->symbol);
		printSubtree(element->left);
		printSubtree(element->right);
		printf(") ");
		return;
	}
	printf("%i ", element->number);
}

void printTree(struct Tree* tree)
{
	printSubtree(tree->root);
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