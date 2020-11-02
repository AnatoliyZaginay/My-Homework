#include "SortedListTests.h"

#include "SortedList.h"
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

bool deleteTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	bool result = !delete(list, 3) && delete(list, 1) && delete(list, 2) && isEmpty(list);
	deleteList(&list);
	return result;
}

bool isSortedTest(void)
{
	struct List* list = createList();
	add(list, 9);
	add(list, 3);
	add(list, 11);
	add(list, 0);
	add(list, 5);
	struct ListElement* currentElement = list->head;
	while (currentElement->next != NULL)
	{
		if (currentElement->value > currentElement->next->value)
		{
			return false;
		}
		currentElement = currentElement->next;
	}
	deleteList(&list);
	return true;
}

bool sortedListTest(void)
{
	return deleteListTest() && isEmptyTest() && addTest() && deleteTest() && isSortedTest();
}