#include "ListAndMergeSortTests.h"

#include "List.h"
#include "MergeSort.h"
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

bool deleteTailTest(void)
{
	struct List* list = createList();
	add(list, "Test", "123");
	add(list, "SecondTest", "234");
	deleteTail(list);
	bool result = strcmp(list->tail->name, "SecondTest") == 0 && strcmp(list->tail->phoneNumber, "234") == 0 &&
		list->tail == list->head;
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
	deleteList(&list);
	return result;
}

bool mergeSortNameTest(void)
{
	struct List* list = createList();
	add(list, "Mark", "12");
	add(list, "Mike", "1");
	add(list, "Max", "2");
	struct List* sortedList = sort(true, list);
	struct ListElement* currentElement = sortedList->tail;
	while (currentElement->next != NULL)
	{
		if (strcmp(currentElement->name, currentElement->next->name) > 0)
		{
			deleteList(&sortedList);
			return false;
		}
		currentElement = currentElement->next;
	}
	deleteList(&sortedList);
	return true;
}

bool mergeSortNumberTest(void)
{
	struct List* list = createList();
	add(list, "Mark", "12");
	add(list, "Mike", "1");
	add(list, "Max", "2");
	struct List* sortedList = sort(false, list);
	struct ListElement* currentElement = sortedList->tail;
	while (currentElement->next != NULL)
	{
		if (strcmp(currentElement->phoneNumber, currentElement->next->phoneNumber) > 0)
		{
			deleteList(&sortedList);
			return false;
		}
		currentElement = currentElement->next;
	}
	deleteList(&sortedList);
	return true;
}

bool listAndMergeSortTests(void)
{
	return deleteListTest() && isEmptyTest() && addTest() &&
		deleteTailTest() && listLengthTest() && mergeSortNameTest() && mergeSortNumberTest();
}