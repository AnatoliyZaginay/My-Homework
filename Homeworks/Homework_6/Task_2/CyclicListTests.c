#include "CyclicListTests.h"

#include "CyclicList.h"
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

bool getValueFromHeadTest(void)
{
	struct List* list = createList();
	add(list, 1);
	bool result = getValueFromHead(list) == 1;
	add(list, 2);
	result = result && getValueFromHead(list) == 2;
	add(list, 3);
	result = result && getValueFromHead(list) == 3;
	deleteList(&list);
	return result;
}

bool deleteElementByNumberTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	deleteElementByNumber(list, 1);
	bool result = getValueFromHead(list) && isOnlyOneElementLeft(list);
	deleteList(&list);
	return result;
}

bool cyclicListTests(void)
{
	return deleteListTest() && isEmptyTest() && addTest() && isOnlyOneElementLeftTest() &&getValueFromHeadTest() && deleteElementByNumberTest();
}