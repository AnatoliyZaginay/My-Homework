#include "phoneBookOperations.h"

#include <stdio.h>
#include <string.h>

void readFile(struct Contact array[], const char fileName[], int* currentIndex)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Файл \"%s\" не найден\n\n", fileName);
		return;
	}
	while (!feof(file) && *currentIndex < PHONEBOOK_LENGTH)
	{
		fscanf(file, "%s %s\n", &array[*currentIndex].name, &array[*currentIndex].phoneNumber);
		++* currentIndex;
	}
	fclose(file);
}

void saveFile(struct Contact array[], const char fileName[], const int lasIndex)
{
	FILE* file = fopen(fileName, "w");
	if (file == NULL)
	{
		printf("File not found");
		return;
	}
	for (int i = 0; i < lasIndex; ++i)
	{
		fprintf(file, "%s %s\n", array[i].name, array[i].phoneNumber);
	}
	fclose(file);
}

void addContact(struct Contact array[], int* currentIndex, const char name[NAME_LENGTH], const char number[NUMBER_LENGTH])
{
	if (*currentIndex >= PHONEBOOK_LENGTH)
	{
		printf("В телефонном справочнике не осталось места для новых контактов\n");
		return;
	}
	strcpy(array[*currentIndex].name, name);
	strcpy(array[*currentIndex].phoneNumber, number);
	++* currentIndex;
}

void writePhoneBook(struct Contact array[], const int lastIndex)
{
	for (int i = 0; i < lastIndex; ++i)
	{
		printf("%s %s\n", array[i].name, array[i].phoneNumber);
	}
}

int nameSearch(struct Contact array[], const int lastIndex, const char number[NUMBER_LENGTH])
{
	for (int i = 0; i < lastIndex; ++i)
	{
		if (strcmp(number, array[i].phoneNumber) == 0)
		{
			return i;
		}
	}
	return -1;
}

int phoneNumberSearch(struct Contact array[], const int lastIndex, const char name[NAME_LENGTH])
{
	for (int i = 0; i < lastIndex; ++i)
	{
		if (strcmp(name, array[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}