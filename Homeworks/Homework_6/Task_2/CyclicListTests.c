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

bool deleteNextElementTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	deleteNextElement(list->tail, list);
	bool result = list->head->value == 1 && list->tail->value == 1 && list->head == list->tail;
	deleteList(&list);
	return result;
}

bool lastElementTest(void)
{
	struct List* oneElementList = createList();
	struct List* firstList = createList();
	struct List* secondList = createList();
	struct List* thirdList = createList();
	struct List* emptyList = createList();
	add(oneElementList, 1);
	for (int i = 1; i <= 10; ++i)
	{
		add(firstList, i);
		add(secondList, i);
		add(thirdList, i);
	}
	bool result = lastElement(firstList, 0) == -1 && lastElement(firstList, -1) == -1 && lastElement(emptyList, 2) == -1 &&
		lastElement(firstList, 1) == 10 && lastElement(secondList, 2) == 5 && lastElement(thirdList, 16) == 7 &&
		lastElement(oneElementList, 2) == 1;
	deleteList(&oneElementList);
	deleteList(&firstList);
	deleteList(&secondList);
	deleteList(&thirdList);
	deleteList(&emptyList);
	return result;
}

bool cyclicListTests(void)
{
	return deleteListTest() && isEmptyTest() && addTest() && deleteNextElementTest() && lastElementTest();
}