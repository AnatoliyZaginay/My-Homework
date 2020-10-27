#include "phoneBookOperationsTests.h"

#include "phoneBookOperations.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkContact(struct Contact array[], const int index, const char expectedName[NAME_LENGTH], const char expectedNumber[NUMBER_LENGTH])
{
	return strcmp(array[index].name, expectedName) == 0 && strcmp(array[index].phoneNumber, expectedNumber) == 0;
}

bool testAddContact(void)
{
	struct Contact testPhoneBook[3];
	int index = 0;
	addContact(testPhoneBook, &index, "Max", "111");
	addContact(testPhoneBook, &index, "Mike", "222");
	addContact(testPhoneBook, &index, "Tim", "333");
	return index = 3 && checkContact(testPhoneBook, 0, "Max", "111") && checkContact(testPhoneBook, 1, "Mike", "222") &&
		checkContact(testPhoneBook, 2, "Tim", "333");
}

bool testPhoneNumberSearch(void)
{
	struct Contact testPhoneBook[3] = { { "Max", "111" }, { "Mike", "222" }, {"Tim", "333" } };
	return phoneNumberSearch(testPhoneBook, 3, "Tim") == 2 && phoneNumberSearch(testPhoneBook, 3, "Alex") == -1;
}

bool testNameSearch(void)
{
	struct Contact testPhoneBook[3] = { { "Max", "111" }, { "Mike", "222" }, {"Tim", "333" } };
	return nameSearch(testPhoneBook, 3, "333") == 2 && nameSearch(testPhoneBook, 3, "444") == -1;
}

bool testReadFile(void)
{
	struct Contact testPhoneBook[3];
	int index = 0;
	readFile(testPhoneBook, "testReadFile.txt", &index);
	return index = 3 && checkContact(testPhoneBook, 0, "Max", "111") && checkContact(testPhoneBook, 1, "Mike", "222") &&
		checkContact(testPhoneBook, 2, "Tim", "333");
}

bool testSaveFile(void)
{
	struct Contact testPhoneBook[3] = { { "Max", "111" }, { "Mike", "222" }, {"Tim", "333" } };
	saveFile(testPhoneBook, "testSaveFile.txt", 3);
	struct Contact testPhoneBookAfterSave[3];
	int index = 0;
	readFile(testPhoneBookAfterSave, "testSaveFile.txt", &index);
	return index = 3 && checkContact(testPhoneBookAfterSave, 0, "Max", "111") && checkContact(testPhoneBookAfterSave, 1, "Mike", "222") &&
		checkContact(testPhoneBookAfterSave, 2, "Tim", "333");
}