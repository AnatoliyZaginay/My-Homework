#include "ReadStringFromFile.h"
#include "ReadStringFromFileTest.h"
#include "Tree.h"
#include "TreeTests.h"
#include <stdio.h>
#include <locale.h> 

#define FILE_NAME "arithmeticExpression.txt"
#define STRING_LENGTH 100

void main(void)
{
	if (!readStringFromFileTest() || !treeTests())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	char arithmeticExpressison[STRING_LENGTH] = { 0 };
	if (!readStringFromFile(arithmeticExpressison, STRING_LENGTH, FILE_NAME))
	{
		printf("File not found");
		return;
	}
	struct Tree* tree = createTree();
	fillTree(tree, arithmeticExpressison);
	printf("Арифметическое выражение, записанное в виде дерева разбора арифметического выражения: ");
	printTree(tree);
	printf("\nЗначение арифметического выражения: %f", calculateTree(tree));
	deleteTree(&tree);
}