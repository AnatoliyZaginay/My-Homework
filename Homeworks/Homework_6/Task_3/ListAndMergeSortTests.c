#include "ListAndMergeSortTests.h"

#include "List.h"
#include "MergeSort.h"
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
	add(list, "Test", "123");
	bool result = isEmpty(list);
	deleteList(&list);
	return !result;
}

bool deleteTailTest(void)
{
	struct List* list = createList();
	add(list, "Test", "123");
	add(list, "SecondTest", "234");
	deleteTail(list);
	bool result = list->tail->name == "SecondTest" && list->tail->phoneNumber == "234" && list->tail == list->head;
	deleteTail(list);
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
	deleteList(list);
	return result;
}

bool mergeSortTest(void)
{
	struct List* list = createList();
	add(list, "Mark", "12");
	add(list, "Mike", "1");
	add(list, "Max", "2");
}