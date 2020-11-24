#include "ListTests.h"

#include "List.h"
#include <stdlib.h>

bool deleteListTest(void)
{
	struct List* list = createList();
	deleteList(&list);
	return list == NULL;
}

bool isEmptyTest(void)
{
	struct List* list = createList();
	bool result = isEmpty(list);
	deleteList(&list);
	return result;
}

bool addTest(void)
{
	struct List* list = createList();
	add(list, 1);
	bool result = isEmpty(list);
	deleteList(&list);
	return !result;
}

bool getLengthTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 1);
	add(list, 1);
	add(list, 1);
	bool result = getLength(list) == 4;
	deleteList(&list);
	return result;
}

bool getValueTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	bool result = getValue(list, 1) == 1 && getValue(list, 2) == 2 && getValue(list, 3) == 3 && getValue(list, 4) == 4;
	deleteList(&list);
	return result;
}

bool listTests(void)
{
	return deleteListTest() && isEmptyTest() && addTest() && getLengthTest() && getValueTest();
}