#include "RemoveCopies.h"

#include <stdlib.h>
#include <string.h>

struct List* removeCopies(struct List* source)
{
	struct List* newList = createList();
	if (newList == NULL)
	{
		return NULL;
	}
	while (!isEmpty(source))
	{
		char string[STRING_LENGTH] = "";
		strcpy(string, getHeadValue(source));
		deleteHead(source);
		if (checkValue(newList, string))
		{
			continue;
		}
		addElementToList(newList, string);
	}
	deleteList(&source);
	return newList;
}