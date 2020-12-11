#include "LastElementTest.h"

#include "LastElement.h"

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