#include "ReadFromFileTest.h"

#include "ReadFromFile.h"
#include <stdlib.h>
#include <string.h>

bool readFromFileTest(void)
{
	char* firtString = readFromFile("wrongName.txt");
	char* secondString = readFromFile("test.txt");
	bool result = firtString == NULL && strcmp(secondString, "test") == 0;
	free(secondString);
	return result;
}