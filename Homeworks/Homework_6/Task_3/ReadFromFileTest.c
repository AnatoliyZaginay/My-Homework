#include "ReadFromFileTest.h"

#include "List.h"
#include "ReadFromFile.h"
#include <string.h>

bool readFromFileTest(void)
{
	struct List* list = createList();
	bool result = !readFromFile(list, "test.txt") && readFromFile(list, "testPhoneBook.txt") &&
		strcmp(getHeadValue(true, list), "John") == 0 && strcmp(getHeadValue(false, list), "1") == 0;
	deleteHead(list);
	result = result && strcmp(getHeadValue(true, list), "Carl") == 0 && strcmp(getHeadValue(false, list), "12") == 0;
	deleteHead(list);
	result = result && strcmp(getHeadValue(true, list),"Jake") == 0 && strcmp(getHeadValue(false, list), "123") == 0;
	deleteList(&list);
	return result;
}