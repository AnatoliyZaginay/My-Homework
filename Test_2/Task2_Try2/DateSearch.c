#include "DateSearch.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DATE_LENGTH 8

struct Date
{
	int day;
	int month;
	int year;
};

bool compareDates(struct Date* firstDate, struct Date* secondDate)
{
	if (firstDate->year > secondDate->year)
	{
		return true;
	}
	if (firstDate->year < secondDate->year)
	{
		return false;
	}
	if (firstDate->month > secondDate->month)
	{
		return true;
	}
	if (firstDate->month < secondDate->month)
	{
		return false;
	}
	if (firstDate->day >= secondDate->day)
	{
		return true;
	}
	return false;
}

struct Date* searchMaximumDate(const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		return NULL;
	}
	struct Date* maxDate = calloc(1, sizeof(struct Date));
	if (maxDate == NULL)
	{
		return NULL;
	}
	while (!feof(file))
	{
		struct Date* newDate = calloc(1, sizeof(struct Date));
		fscanf(file, "%i.%i.%i", &newDate->day, &newDate->month, &newDate->year);
		if (!compareDates(maxDate, newDate))
		{
			maxDate->day = newDate->day;
			maxDate->month = newDate->month;
			maxDate->year = newDate->year;
		}
		free(newDate);
	}
	fclose(file);
	return maxDate;
}

void printDate(struct Date* date)
{
	printf("%i.%i.%i", date->day, date->month, date->year);
}

int getDate(struct Date* date, int partNumber)
{
	switch (partNumber)
	{
	case 0:
		return date->day;
	case 1:
		return date->month;
	case 2:
		return date->year;
	}
}
