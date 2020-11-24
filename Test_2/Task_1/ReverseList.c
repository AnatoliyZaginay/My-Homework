#include "ReverseList.h"

#include <stdlib.h>

struct List* reverseList(struct List* source)
{
	struct List* newList = createList();
	if (newList == NULL)
	{
		return source;
	}
	const int length = getLength(source);
	for (int i = 0; i < length; ++i)
	{
		int value = getValue(source, length - i);
		add(newList, value);
	}
	return newList;
}