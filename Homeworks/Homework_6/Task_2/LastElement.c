#include "LastElement.h"

int lastElement(struct List* list, int period)
{
	if (period <= 0 || isEmpty(list))
	{
		return -1;
	}
	while (!isOnlyOneElementLeft(list))
	{
		deleteElementByNumber(list, period);
	}
	return getValueFromHead(list);
}