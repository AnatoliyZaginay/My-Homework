#include "MergeSortTests.h"

#include "MergeSort.h"
#include <string.h>

bool mergeSortNameTest(void)
{
	struct List* list = createList();
	add(list, "Mark", "12");
	add(list, "Mike", "1");
	add(list, "Max", "2");
	struct List* sortedList = sort(true, list);
	char value[NAME_LENGTH] = "";
	strcpy(value, getHeadValue(true, sortedList));
	deleteHead(sortedList);
	while (!isEmpty(sortedList))
	{
		char nextValue[NAME_LENGTH] = "";
		strcpy(nextValue, getHeadValue(true, sortedList));
		deleteHead(sortedList);
		if (strcmp(value, nextValue) > 0)
		{
			deleteList(&sortedList);
			return false;
		}
		strcpy(value, nextValue);
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
	char value[PHONENUMBER_LENGTH] = "";
	strcpy(value, getHeadValue(false, sortedList));
	deleteHead(sortedList);
	while (!isEmpty(sortedList))
	{
		char nextValue[PHONENUMBER_LENGTH] = "";
		strcpy(nextValue, getHeadValue(false, sortedList));
		deleteHead(sortedList);
		if (strcmp(value, nextValue) > 0)
		{
			deleteList(&sortedList);
			return false;
		}
		strcpy(value, nextValue);
	}
	deleteList(&sortedList);
	return true;
}

bool mergeSortTests(void)
{
	return mergeSortNameTest() && mergeSortNumberTest();
}