#include "SortTest.h"

#include "Sort.h"
#include <string.h>

bool sortTest(void)
{
	struct List* list = createList();
	add(list, 7);
	add(list, 3);
	add(list, 5);
	struct List* sortedList = sort(list);
	int number = getHeadValue(sortedList);
	deleteHead(sortedList);
	while (!isEmpty(sortedList))
	{
		int nextNumber = getHeadValue(sortedList);
		deleteHead(sortedList);
		if (number > nextNumber)
		{
			deleteList(&sortedList);
			return false;
		}
		number = nextNumber;
	}
	deleteList(&sortedList);
	return true;
}