#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define NAME_LENGTH 30
#define NUMBER_LENGTH 30
#define PHONEBOOK_LENGTH 100
#define FILE_NAME "phoneBook.txt"

struct Contact
{
	char name[NAME_LENGTH];
	char phoneNumber[NUMBER_LENGTH];
};

void readFile(struct Contact array[], const char fileName[], int* currentIndex)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Файл \"%s\" не найден\n\n", FILE_NAME);
		return;
	}
	while (!feof(file) && *currentIndex < PHONEBOOK_LENGTH)
	{
		fscanf(file, "%s %s\n", &array[*currentIndex].name, &array[*currentIndex].phoneNumber);
		++*currentIndex;
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
	strcpy(array[*currentIndex].name, name);
	strcpy(array[*currentIndex].phoneNumber, number);
	++*currentIndex;
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

void operations()
{
	printf("Операции:\n");
	printf("0 - выйти\n");
	printf("1 - добавить контакт\n");
	printf("2 - распечатать все имеющиеся контакты\n");
	printf("3 - найти номер телефона по имени\n");
	printf("4 - найти имя по номеру телефона\n");
	printf("5 - сохранить текущие данные в файл\n\n");
}

bool checkContact(struct Contact array[], const int index, const char expectedName[NAME_LENGTH], const char expectedNumber[NUMBER_LENGTH])
{
	if (strcmp(array[index].name, expectedName) == 0 && strcmp(array[index].phoneNumber, expectedNumber) == 0)
	{
		return true;
	}
	return false;
}

bool testAddContact()
{
	struct Contact testPhoneBook[3];
	int index = 0;
	addContact(testPhoneBook, &index, "Max", "111");
	addContact(testPhoneBook, &index, "Mike", "222");
	addContact(testPhoneBook, &index, "Tim", "333");
	if (index = 3 && checkContact(testPhoneBook, 0, "Max", "111") && checkContact(testPhoneBook, 1, "Mike", "222") &&
		checkContact(testPhoneBook, 2, "Tim", "333"))
	{
		return true;
	}
	return false;
}

bool testPhoneNumberSearch()
{
	struct Contact testPhoneBook[3] = { "Max", "111", "Mike", "222", "Tim", "333" };
	if (phoneNumberSearch(testPhoneBook, 3, "Tim") == 2 && phoneNumberSearch(testPhoneBook, 3, "Alex") == -1)
	{
		return true;
	}
	return false;
}

bool testNameSearch()
{
	struct Contact testPhoneBook[3] = { "Max", "111", "Mike", "222", "Tim", "333" };
	if (nameSearch(testPhoneBook, 3, "333") == 2 && nameSearch(testPhoneBook, 3, "444") == -1)
	{
		return true;
	}
	return false;
}

bool testReadFile()
{
	struct Contact testPhoneBook[3];
	int index = 0;
	readFile(testPhoneBook, "testReadFile.txt", &index);
	if (index = 3 && checkContact(testPhoneBook, 0, "Max", "111") && checkContact(testPhoneBook, 1, "Mike", "222") &&
		checkContact(testPhoneBook, 2, "Tim", "333"))
	{
		return true;
	}
	return false;
}

bool testSaveFile()
{
	struct Contact testPhoneBook[3] = { "Max", "111", "Mike", "222", "Tim", "333" };
	saveFile(testPhoneBook, "testSaveFile.txt", 3);
	struct Contact testPhoneBookAfterSave[3];
	int index = 0;
	readFile(testPhoneBookAfterSave, "testSaveFile.txt", &index);
	if (index = 3 && checkContact(testPhoneBookAfterSave, 0, "Max", "111") && checkContact(testPhoneBookAfterSave, 1, "Mike", "222") &&
		checkContact(testPhoneBookAfterSave, 2, "Tim", "333"))
	{
		return true;
	}
	return false;
}

bool testsResult()
{
	return testAddContact() && testPhoneNumberSearch() && testNameSearch() && testReadFile() && testSaveFile();
}

void main()
{
	if (!testsResult())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int currentIndex = 0;
	struct Contact phoneBook[PHONEBOOK_LENGTH];
	readFile(phoneBook, FILE_NAME, &currentIndex);
	operations();
	int operationNumber = 0;
	printf("Введите номер операции: ");
	scanf("%i", &operationNumber);
	while (operationNumber != 0)
	{
		switch (operationNumber)
		{
		case 0:
			break;
		case 1:
		{
			char name[NAME_LENGTH];
			char phoneNumber[NUMBER_LENGTH];
			printf("Введите имя: ");
			scanf("%s", &name);
			printf("Введите номер телефон: ");
			scanf("%s", &phoneNumber);
			addContact(phoneBook, &currentIndex, name, phoneNumber);
			printf("Контакт сохранен\n\n");
			break;
		}
		case 2:
			writePhoneBook(phoneBook, currentIndex);
			printf("\n");
			break;
		case 3:
		{
			char name[NAME_LENGTH];
			printf("Введите имя: ");
			scanf("%s", &name);
			int index = phoneNumberSearch(phoneBook, currentIndex, name);
			if (index < 0)
			{
				printf("Введённое имя не найдено в телефонном справочнике\n\n");
				break;
			}
			printf("По введённому имени был найден следующий номер телефона: %s\n\n", phoneBook[index].phoneNumber);
			break;
		}
		case 4:
		{
			char phoneNumber[NUMBER_LENGTH];
			printf("Введите номер телефона: ");
			scanf("%s", &phoneNumber);
			int index = nameSearch(phoneBook, currentIndex, phoneNumber);
			if (index < 0)
			{
				printf("Введённый номер телефона не найден в телефонном справочнике\n\n");
				break;
			}
			printf("По введённому номеру телефона было найдено следующее имя: %s\n\n", phoneBook[index].name);
			break;
		}
		case 5:
			saveFile(phoneBook, FILE_NAME, currentIndex);
			printf("Телефонный справочник сохранён в файл \"%s\"\n\n", FILE_NAME);
			break;
		default:
			printf("Введите корректный номер операции (0 - 5)\n\n");
			break;
		}
		operations();
		printf("Введите номер операции: ");
		scanf("%i", &operationNumber);
	}
	printf("Программа завершена");
}