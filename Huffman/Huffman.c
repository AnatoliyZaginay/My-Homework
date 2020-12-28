#include "Huffman.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SYMBOL_TABLE_SIZE 256

struct TreeElement
{
	unsigned char symbol;
	int frequency;
	struct TreeElement* left;
	struct TreeElement* right;
};

struct Forest
{
	int length;
	struct TreeElement** elements;
};

void fillSymbolTable(char* string, int table[])
{
	const int length = strlen(string);
	for (int i = 0; i < length; ++i)
	{
		unsigned char symbol = (unsigned char)string[i];
		++table[symbol];
	}
}

int countUniqueSymbols(int table[])
{
	int countOfUniqueSymbols = 0;
	for (int i = 0; i < SYMBOL_TABLE_SIZE; ++i)
	{
		if (table[i] != 0)
		{
			++countOfUniqueSymbols;
		}
	}
	return countOfUniqueSymbols;
}

struct Forest* createForest(char* string)
{
	struct Forest* forest = calloc(1, sizeof(struct Forest));
	if (forest == NULL)
	{
		return NULL;
	}
	int symbolTable[SYMBOL_TABLE_SIZE] = { 0 };
	fillSymbolTable(string, symbolTable);
	forest->length = countUniqueSymbols(symbolTable);
	forest->elements = calloc(forest->length, sizeof(struct TreeElement*));
	if (forest->elements == NULL)
	{
		free(forest);
		return NULL;
	}
	for (int i = 0; i < forest->length; ++i)
	{
		forest->elements[i] = calloc(1, sizeof(struct TreeElement));
	}
	int currentElementIndex = 0;
	for (int i = 0; i < SYMBOL_TABLE_SIZE; ++i)
	{
		if (symbolTable[i] != 0)
		{
			forest->elements[currentElementIndex]->symbol = i;
			forest->elements[currentElementIndex]->frequency = symbolTable[i];
			++currentElementIndex;
		}
	}
	return forest;
}

struct TreeElement* buildTree(char* string)
{
	struct Forest* forest = createForest(string);
	while (forest->length > 1)
	{
		int indexOfFirstMinimum = 0;
		for (int i = 0; i < forest->length; ++i)
		{
			if (forest->elements[i]->frequency < forest->elements[indexOfFirstMinimum]->frequency)
			{
				indexOfFirstMinimum = i;
			}
		}
		int indexOfSecondMinimum = 0;
		if (indexOfSecondMinimum == indexOfFirstMinimum)
		{
			indexOfSecondMinimum = 1;
		}
		for (int i = 0; i < forest->length; ++i)
		{
			if (i != indexOfFirstMinimum && forest->elements[i]->frequency < forest->elements[indexOfSecondMinimum]->frequency)
			{
				indexOfSecondMinimum = i;
			}
		}
		struct TreeElement* newElement = calloc(1, sizeof(struct TreeElement));
		newElement->frequency = forest->elements[indexOfFirstMinimum]->frequency + forest->elements[indexOfSecondMinimum]->frequency;
		newElement->left = forest->elements[indexOfFirstMinimum];
		newElement->right = forest->elements[indexOfSecondMinimum];
		forest->elements[indexOfFirstMinimum] = newElement;
		for (int i = indexOfSecondMinimum; i < forest->length - 1; ++i)
		{
			forest->elements[i] = forest->elements[i + 1];
		}
		--forest->length;
	}
	struct TreeElement* root = forest->elements[0];
	free(forest->elements);
	free(forest);
	return root;
}

void printCodes(struct TreeElement* root, char* code, int index)
{
	if (root->symbol != '\0')
	{
		printf("%c - %s\n", root->symbol, code);
		return;
	}
	code[index] = '0';
	code[index + 1] = '\0';
	printCodes(root->left, code, index + 1);
	code[index] = '1';
	code[index + 1] = '\0';
	printCodes(root->right, code, index + 1);
}

void deleteTree(struct TreeElement* root)
{
	if (root == NULL)
	{
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}