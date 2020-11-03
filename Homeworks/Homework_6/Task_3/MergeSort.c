#include "MergeSort.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void transfer(struct List* list, struct List* transferableList, int number)
{
	for (int i = 0; i < number; ++i)
	{
		if (isEmpty(transferableList))
		{
			return;
		}
		add(list, transferableList->tail->name, transferableList->tail->phoneNumber);
		deleteTail(transferableList);
	}
}

struct List* merge(bool sortType, struct List* firstList, struct List* secondList)
{
	struct List* mainList = createList();
	while (listLength(firstList) > 0 && listLength(secondList) > 0)
	{
		int change = 0;
		if (sortType)
		{
			change = strcmp(firstList->tail->name, secondList->tail->name);
		}
		else
		{
			change = strcmp(firstList->tail->phoneNumber, secondList->tail->phoneNumber);
		}
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

struct List* sort(bool sortType, struct List* list)
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
	firstList = sort(sortType, firstList);
	secondList = sort(sortType, secondList);
	return merge(sortType, firstList, secondList);
}