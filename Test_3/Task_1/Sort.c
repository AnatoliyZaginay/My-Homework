#include "Sort.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void transfer(struct List* destination, struct List* source, int number)
{
	for (int i = 0; i < number; ++i)
	{
		if (isEmpty(source))
		{
			return;
		}
		const int number = getHeadValue(source);
		add(destination, number);
		deleteHead(source);
	}
}

struct List* merge(struct List* firstList, struct List* secondList)
{
	struct List* mainList = createList();
	while (listLength(firstList) > 0 && listLength(secondList) > 0)
	{
		int change = getHeadValue(firstList) - getHeadValue(secondList);
		if (change <= 0)
		{
			transfer(mainList, firstList, 1);
		}
		else
		{
			transfer(mainList, secondList, 1);
		}
	}
	if (listLength(firstList) == 0)
	{
		transfer(mainList, secondList, listLength(secondList));
	}
	else
	{
		transfer(mainList, firstList, listLength(firstList));
	}
	deleteList(&firstList);
	deleteList(&secondList);
	return mainList;
}

struct List* sort(struct List* list)
{
	if (listLength(list) <= 1)
	{
		return list;
	}
	struct List* firstList = createList();
	struct List* secondList = createList();
	transfer(firstList, list, listLength(list) / 2);
	transfer(secondList, list, listLength(list));
	deleteList(&list);
	firstList = sort(firstList);
	secondList = sort(secondList);
	return merge(firstList, secondList);
}