#include "DateSearchTest.h"

#include "DateSearch.h"
#include <stdlib.h>

bool searchMaximumDateTest(void)
{
	struct Date* date = searchMaximumDate("wrong.txt");
	bool result = date == NULL;
	date = searchMaximumDate("test1.txt");
	result = result && getDate(date, 0) == 12 && getDate(date, 1) == 12 && getDate(date, 2) == 2012;
	free(date);
	date = searchMaximumDate("test2.txt");
	result = result && getDate(date, 0) == 12 && getDate(date, 1) == 2 && getDate(date, 2) == 2021;
	free(date);
	return result;
}