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
	add(list, "Test", "123");
	bool result = isEmpty(list);
	deleteList(&list);
	return !result;
}

bool getHeadValueTest(void)
{
	struct List* list = createList();
	add(list, "Test", "123");
	bool result = strcmp(getHeadValue(true, list), "Test") == 0 && strcmp(getHeadValue(false, list), "123") == 0;
	deleteList(&list);
	return result;
}

bool isOnlyOneElementLeftTest(void)
{
	struct List* list = createList();
	add(list, "Test", "123");
	bool result = isOnlyOneElementLeft(list);
	add(list, "SecondTest", "234");
	result = result && !isOnlyOneElementLeft(list);
	deleteList(&list);
	return result;
}

bool deleteHeadTest(void)
{
	struct List* list = createList();
	add(list, "Test", "123");
	add(list, "SecondTest", "234");
	deleteHead(list);
	bool result = strcmp(getHeadValue(true, list), "SecondTest") == 0 && strcmp(getHeadValue(false, list), "234") == 0 &&
		isOnlyOneElementLeft(list);
	deleteHead(list);
	result = result && isEmpty(list);
	deleteList(&list);
	return result;
}

bool listLengthTest(void)
{
	struct List* list = createList();
	add(list, "Test", "123");
	add(list, "SecondTest", "234");
	add(list, "ThirdTest", "345");
	bool result = listLength(list) == 3;
	deleteList(&list);
	return result;
}

bool listTests(void)
{
	return deleteListTest() && isEmptyTest() && addTest() && getHeadValueTest() && isOnlyOneElementLeftTest() &&
		deleteHeadTest() && listLengthTest();
}