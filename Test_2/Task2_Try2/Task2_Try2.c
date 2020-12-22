#include "DateSearch.h"
#include "DateSearchTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(void)
{
	if (!searchMaximumDateTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct Date* maxDate = searchMaximumDate("text.txt");
	printf("Максимальная дата: ");
	printDate(maxDate);
	free(maxDate);
}