#include "TestReverseList.h"

#include "List.h"
#include "ReverseList.h"

bool reverseListTest(void)
{
	struct List* list = createList();
	add(list, 1);
	add(list, 2);
	add(list, 3);
	add(list, 4);
	add(list, 5);
	struct List* reversedList = reverseList(list);
	const int listLength = getLength(list);
	const int reversedListLength = getLength(reversedList);
	bool result = listLength == reversedListLength;
	for (int i = 0; i < listLength; ++i)
	{
		result = getValue(list, i + 1) == getValue(reversedList, reversedListLength - i);
	}
	deleteList(&list);
	deleteList(&reversedList);
	return result;
}