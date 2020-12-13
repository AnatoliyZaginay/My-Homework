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

bool addElementToListTest(void)
{
	struct List* list = createList();
	addElementToList(list, "test", 1);
	bool result = isEmpty(list);
	deleteList(&list);
	return !result;
}

bool deleteHeadTest(void)
{
	struct List* list = createList();
	addElementToList(list, "test1", 1);
	addElementToList(list, "test2", 2);
	deleteHead(list);
	deleteHead(list);
	bool result = isEmpty(list);
	deleteList(&list);
	return result;
}

bool checkValueTest(void)
{
	struct List* list = createList();
	addElementToList(list, "test1", 1);
	addElementToList(list, "test2", 2);
	addElementToList(list, "test3", 3);
	bool result = checkValue(list, "test2") && !checkValue(list, "test4");
	deleteList(&list);
	return result;
}

bool getValueFromHeadTest(void)
{
	struct List* list = createList();
	addElementToList(list, "test1", 1);
	addElementToList(list, "test2", 2);
	addElementToList(list, "test3", 3);
	char* line = getValueFromHead(list);
	bool result = strcmp(line, "test3") == 0;
	free(line);
	deleteList(&list);
	return result;
}

bool getCountFromHeadTest(void)
{
	struct List* list = createList();
	addElementToList(list, "test1", 1);
	addElementToList(list, "test2", 2);
	addElementToList(list, "test3", 3);
	bool result = getCountFromHead(list) == 3;
	deleteList(&list);
	return result;
}

bool updateCountTest(void)
{
	struct List* list = createList();
	addElementToList(list, "test1", 1);
	addElementToList(list, "test2", 2);
	addElementToList(list, "test3", 1);
	updateCount(list, "test2");
	deleteHead(list);
	bool result = getCountFromHead(list) == 3;
	deleteList(&list);
	return result;
}

bool listTests(void)
{
	return deleteListTest() && isEmptyTest() && addElementToListTest() && deleteHeadTest() && checkValueTest() &&
		getValueFromHeadTest() && getCountFromHeadTest() && updateCountTest();
}