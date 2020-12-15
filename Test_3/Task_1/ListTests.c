#include "ListTests.h"

#include "List.h"
#include <stdlib.h>
#include <string.h>

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

bool getHeadValueTest(void)
{
	struct List* list = createList();
	add(list, 1);
	bool result = getHeadValue(list) == 1;
	deleteList(&list);
	return result;
}

bool isOnlyOneElementLeftTest(void)
{
	struct List* list = createList();
	add(list, 1);
	bool result = isOnlyOneElementLeft(list);
	add(list, 2);
	result = result && !isOnlyOneElementLeft(list);
	deleteList(&list);
	return result;
}

bool deleteHeadTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	deleteHead(list);
	bool result = getHeadValue(list) == 2 &&
		isOnlyOneElementLeft(list);
	deleteHead(list);
	result = result && isEmpty(list);
	deleteList(&list);
	return result;
}

bool listLengthTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	bool result = listLength(list) == 3;
	deleteList(&list);
	return result;
}

bool listTests(void)
{
	return deleteListTest() && isEmptyTest() && addTest() && getHeadValueTest() && isOnlyOneElementLeftTest() &&
		deleteHeadTest() && listLengthTest();
}