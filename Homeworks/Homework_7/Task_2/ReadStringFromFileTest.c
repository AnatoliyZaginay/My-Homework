#include "ReadStringFromFile.h"

#include <string.h>

bool readStringFromFileTest(void)
{
	char line[100] = { 0 };
	return !readStringFromFile(line, 100, "nonexistent_file.txt") && readStringFromFile(line, 100, "test.txt") &&
		strcmp(line, "( + 9 ( - 8 5 ) )") == 0;
}