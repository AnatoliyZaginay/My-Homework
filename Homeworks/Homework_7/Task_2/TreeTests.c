#include "TreeTests.h"

#include "Tree.h"
#include <stdlib.h>

bool deleteTreeTest(void)
{
	struct Tree* tree = createTree();
	deleteTree(&tree);
	return tree == NULL;
}

bool isEmptyTest(void)
{
	struct Tree* tree = createTree();
	bool result = isEmpty(tree);
	deleteTree(&tree);
	return result;
}

bool fillTreeTest(void)
{
	struct Tree* tree = createTree();
	fillTree(tree, "( + 1 2 )");
	bool result = !isEmpty(tree);
	deleteTree(&tree);
	return result;
}

bool calculateTreeTest(void)
{
	struct Tree* firstTree = createTree();
	struct Tree* secondTree = createTree();
	fillTree(firstTree, "( * ( / 4 2 ) ( + ( - -3 -9 ) 8 )");
	fillTree(secondTree, "( - 150 ( * 25 ( + 7 ( / -32 16 ) ) ) )");
	bool result = calculateTree(firstTree) == 28 && calculateTree(secondTree) == 25;
	deleteTree(&firstTree);
	deleteTree(&secondTree);
	return result;
}

bool treeTests(void)
{
	return deleteTreeTest() && isEmptyTest() && fillTreeTest() && calculateTreeTest();
}