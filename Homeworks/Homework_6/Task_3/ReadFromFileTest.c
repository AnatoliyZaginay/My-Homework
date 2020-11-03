#include "ReadFromFileTest.h"

#include "List.h"
#include "ReadFromFile.h"
#include <string.h>

bool readFromFileTest(void)
{
	struct List* list = createList();
	bool result = !readFromFile(list, "test.txt") && readFromFile(list, "testPhoneBook.txt") &&
		strcmp(list->tail->name, "John") == 0 && strcmp(list->tail->phoneNumber, "1") == 0 &&
		strcmp(list->tail->next->name, "Carl") == 0 && strcmp(list->tail->next->phoneNumber, "12") == 0 &&
		strcmp(list->tail->next->next->name,"Jake") == 0 && strcmp(list->tail->next->next->phoneNumber, "123") == 0;
	deleteList(&list);
	return result;
}